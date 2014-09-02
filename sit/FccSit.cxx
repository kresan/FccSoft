/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH *
 *                                                                              *
 *              This software is distributed under the terms of the *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3, *
 *                  copied verbatim in the file "LICENSE" *
 ********************************************************************************/
#include "FccSit.h"

#include "FccSitPoint.h"
#include "FccSitGeo.h"
#include "FccSitGeoPar.h"

#include "FairVolume.h"
#include "FairGeoVolume.h"
#include "FairGeoNode.h"
#include "FairRootManager.h"
#include "FairGeoLoader.h"
#include "FairGeoInterface.h"
#include "FairRun.h"
#include "FairRuntimeDb.h"
#include "FccDetectorList.h"
#include "FccStack.h"

#include "TClonesArray.h"
#include "TVirtualMC.h"
#include "TGeoManager.h"
#include "TGeoBBox.h"
#include "TGeoCompositeShape.h"
#include "TGeoTube.h"
#include "TGeoMaterial.h"
#include "TGeoMedium.h"

#include <iostream>
using std::cout;
using std::endl;

FccSit::FccSit()
    : FairDetector("FccSit", kTRUE, kFccSit)
    , fTrackID(-1)
    , fVolumeID(-1)
    , fPos()
    , fMom()
    , fTime(-1.)
    , fLength(-1.)
    , fELoss(-1)
    , fFccSitPointCollection(new TClonesArray("FccSitPoint"))
{
}

FccSit::FccSit(const char* name, Bool_t active)
    : FairDetector(name, active, kFccSit)
    , fTrackID(-1)
    , fVolumeID(-1)
    , fPos()
    , fMom()
    , fTime(-1.)
    , fLength(-1.)
    , fELoss(-1)
    , fFccSitPointCollection(new TClonesArray("FccSitPoint"))
{
}

FccSit::~FccSit()
{
    if (fFccSitPointCollection)
    {
        fFccSitPointCollection->Delete();
        delete fFccSitPointCollection;
    }
}

void FccSit::Initialize()
{
    FairDetector::Initialize();
    FairRuntimeDb* rtdb = FairRun::Instance()->GetRuntimeDb();
    FccSitGeoPar* par = (FccSitGeoPar*)(rtdb->getContainer("FccSitGeoPar"));
}

Bool_t FccSit::ProcessHits(FairVolume* vol)
{
    /** This method is called from the MC stepping */

    // Set parameters at entrance of volume. Reset ELoss.
    if (gMC->IsTrackEntering())
    {
        fELoss = 0.;
        fTime = gMC->TrackTime() * 1.0e09;
        fLength = gMC->TrackLength();
        gMC->TrackPosition(fPos);
        gMC->TrackMomentum(fMom);
    }

    // Sum energy loss for all steps in the active volume
    fELoss += gMC->Edep();

    // Create FccSitPoint at exit of active volume
    if (gMC->IsTrackExiting() || gMC->IsTrackStop() || gMC->IsTrackDisappeared())
    {
        fTrackID = gMC->GetStack()->GetCurrentTrackNumber();
        fVolumeID = vol->getMCid();
        if (fELoss == 0.)
        {
            return kFALSE;
        }
        AddHit(fTrackID, fVolumeID, TVector3(fPos.X(), fPos.Y(), fPos.Z()), TVector3(fMom.Px(), fMom.Py(), fMom.Pz()), fTime, fLength, fELoss);

        // Increment number of FccSit det points in TParticle
        FccStack* stack = (FccStack*)gMC->GetStack();
        stack->AddPoint(kFccSit);
    }

    return kTRUE;
}

void FccSit::EndOfEvent()
{
    fFccSitPointCollection->Clear();
}

void FccSit::Register()
{

    /** This will create a branch in the output tree called
        FccSitPoint, setting the last parameter to kFALSE means:
        this collection will not be written to the file, it will exist
        only during the simulation.
    */

    FairRootManager::Instance()->Register("FccSitPoint", "FccSit", fFccSitPointCollection, kTRUE);
}

TClonesArray* FccSit::GetCollection(Int_t iColl) const
{
    if (iColl == 0)
    {
        return fFccSitPointCollection;
    }
    else
    {
        return NULL;
    }
}

void FccSit::Reset()
{
    fFccSitPointCollection->Clear();
}

void FccSit::ConstructGeometry()
{
    TGeoRotation* rot = new TGeoRotation("rot0");
    LOG(INFO) << "FccSit : constructing GDML geometry from " << GetGeometryFileName() << FairLogger::endl;
    ConstructGDMLGeometry(rot);
    gGeoManager->DefaultColors();
}

Bool_t FccSit::CheckIfSensitive(std::string name)
{
    if (TString(name).Contains("sens"))
    {
        return kTRUE;
    }
    return kFALSE;
}

FccSitPoint* FccSit::AddHit(Int_t trackID, Int_t detID, TVector3 pos, TVector3 mom, Double_t time, Double_t length, Double_t eLoss)
{
    TClonesArray& clref = *fFccSitPointCollection;
    Int_t size = clref.GetEntriesFast();
    return new (clref[size]) FccSitPoint(trackID, detID, pos, mom, time, length, eLoss);
}

ClassImp(FccSit)
