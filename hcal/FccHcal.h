/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef HCAL_H
#define HCAL_H

#include "FairDetector.h"

#include "TVector3.h"
#include "TLorentzVector.h"

class FccHcalPoint;
class FairVolume;
class TClonesArray;

class FccHcal : public FairDetector
{

  public:
    /**      Name :  Detector Name
     *       Active: kTRUE for active detectors (ProcessHits() will be called)
     *               kFALSE for inactive detectors
    */
    FccHcal(const char* Name, Bool_t Active);

    /**      default constructor    */
    FccHcal();

    /**       destructor     */
    virtual ~FccHcal();

    /**      Initialization of the detector is done here    */
    virtual void Initialize();

    /**       this method is called for each step during simulation
     *       (see FairMCApplication::Stepping())
    */
    virtual Bool_t ProcessHits(FairVolume* v = 0);

    /**       Registers the produced collections in FAIRRootManager.     */
    virtual void Register();

    /** Gets the produced collections */
    virtual TClonesArray* GetCollection(Int_t iColl) const;

    /**      has to be called after each event to reset the containers      */
    virtual void Reset();

    /**      Create the detector geometry        */
    void ConstructGeometry();

    /**      This method is an example of how to add your own point
     *       of type FccHcalPoint to the clones array
    */
    FccHcalPoint* AddHit(Int_t trackID, Int_t detID, TVector3 pos, TVector3 mom, Double_t time, Double_t length, Double_t eLoss);

    /** The following methods can be implemented if you need to make
     *  any optional action in your detector during the transport.
    */

    virtual void CopyClones(TClonesArray* cl1, TClonesArray* cl2, Int_t offset)
    {
        ;
    }
    virtual void SetSpecialPhysicsCuts()
    {
        ;
    }
    virtual void EndOfEvent();
    virtual void FinishPrimary()
    {
        ;
    }
    virtual void FinishRun()
    {
        ;
    }
    virtual void BeginPrimary()
    {
        ;
    }
    virtual void PostTrack()
    {
        ;
    }
    virtual void PreTrack()
    {
        ;
    }
    virtual void BeginEvent()
    {
        ;
    }

    virtual Bool_t CheckIfSensitive(std::string name);

  private:
    /** Track information to be stored until the track leaves the
    active volume.
    */
    Int_t fTrackID;      //!  track index
    Int_t fVolumeID;     //!  volume id
    TLorentzVector fPos; //!  position at entrance
    TLorentzVector fMom; //!  momentum at entrance
    Double32_t fTime;    //!  time
    Double32_t fLength;  //!  length
    Double32_t fELoss;   //!  energy loss

    /** container for data points */

    TClonesArray* fFccHcalPointCollection; //!

    FccHcal(const FccHcal&);
    FccHcal& operator=(const FccHcal&);

    ClassDef(FccHcal, 1)
};

#endif // NEWDETECTOR_H
