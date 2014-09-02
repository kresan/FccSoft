/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH *
 *                                                                              *
 *              This software is distributed under the terms of the *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3, *
 *                  copied verbatim in the file "LICENSE" *
 ********************************************************************************/
#include "FccVxd.h"

#include "FccVxdPoint.h"
#include "FccVxdGeo.h"
#include "FccVxdGeoPar.h"

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

FccVxd::FccVxd()
    : FairDetector("FccVxd", kTRUE, kFccVxd)
    , fTrackID(-1)
    , fVolumeID(-1)
    , fPos()
    , fMom()
    , fTime(-1.)
    , fLength(-1.)
    , fELoss(-1)
    , fFccVxdPointCollection(new TClonesArray("FccVxdPoint"))
{
}

FccVxd::FccVxd(const char* name, Bool_t active)
    : FairDetector(name, active, kFccVxd)
    , fTrackID(-1)
    , fVolumeID(-1)
    , fPos()
    , fMom()
    , fTime(-1.)
    , fLength(-1.)
    , fELoss(-1)
    , fFccVxdPointCollection(new TClonesArray("FccVxdPoint"))
{
}

FccVxd::~FccVxd()
{
    if (fFccVxdPointCollection)
    {
        fFccVxdPointCollection->Delete();
        delete fFccVxdPointCollection;
    }
}

void FccVxd::Initialize()
{
    FairDetector::Initialize();
    FairRuntimeDb* rtdb = FairRun::Instance()->GetRuntimeDb();
    FccVxdGeoPar* par = (FccVxdGeoPar*)(rtdb->getContainer("FccVxdGeoPar"));
}

Bool_t FccVxd::ProcessHits(FairVolume* vol)
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

    // Create FccVxdPoint at exit of active volume
    if (gMC->IsTrackExiting() || gMC->IsTrackStop() || gMC->IsTrackDisappeared())
    {
        fTrackID = gMC->GetStack()->GetCurrentTrackNumber();
        fVolumeID = vol->getMCid();
        if (fELoss == 0.)
        {
            return kFALSE;
        }
        AddHit(fTrackID, fVolumeID, TVector3(fPos.X(), fPos.Y(), fPos.Z()), TVector3(fMom.Px(), fMom.Py(), fMom.Pz()), fTime, fLength, fELoss);

        // Increment number of FccVxd det points in TParticle
        FccStack* stack = (FccStack*)gMC->GetStack();
        stack->AddPoint(kFccVxd);
    }

    return kTRUE;
}

void FccVxd::EndOfEvent()
{
    fFccVxdPointCollection->Clear();
}

void FccVxd::Register()
{

    /** This will create a branch in the output tree called
        FccVxdPoint, setting the last parameter to kFALSE means:
        this collection will not be written to the file, it will exist
        only during the simulation.
    */

    FairRootManager::Instance()->Register("FccVxdPoint", "FccVxd", fFccVxdPointCollection, kTRUE);
}

TClonesArray* FccVxd::GetCollection(Int_t iColl) const
{
    if (iColl == 0)
    {
        return fFccVxdPointCollection;
    }
    else
    {
        return NULL;
    }
}

void FccVxd::Reset()
{
    fFccVxdPointCollection->Clear();
}

void FccVxd::ConstructGeometry()
{
    TGeoRotation* rot = new TGeoRotation("rot0");
    LOG(INFO) << "FccVxd : constructing GDML geometry from " << GetGeometryFileName() << FairLogger::endl;
    ConstructGDMLGeometry(rot);
    gGeoManager->DefaultColors();
}

Bool_t FccVxd::CheckIfSensitive(std::string name)
{
    if (TString(name).Contains("sens"))
    {
        return kTRUE;
    }
    return kFALSE;
}

FccVxdPoint* FccVxd::AddHit(Int_t trackID, Int_t detID, TVector3 pos, TVector3 mom, Double_t time, Double_t length, Double_t eLoss)
{
    TClonesArray& clref = *fFccVxdPointCollection;
    Int_t size = clref.GetEntriesFast();
    return new (clref[size]) FccVxdPoint(trackID, detID, pos, mom, time, length, eLoss);
}

ClassImp(FccVxd)
