eventDisplay()
{
  //-----User Settings:-----------------------------------------------
  TString  InputFile     ="test.root";
  TString  ParFile       ="params.root";
  TString  OutFile	 ="tst.root";
    
    
  // -----   Reconstruction run   -------------------------------------------
  FairRunAna *fRun= new FairRunAna();
  fRun->SetInputFile(InputFile.Data());
  fRun->SetOutputFile(OutFile.Data());

  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
  FairParRootFileIo* parInput1 = new FairParRootFileIo();
  parInput1->open(ParFile.Data());
  rtdb->setFirstInput(parInput1);
   
  FairEventManager *fMan= new FairEventManager();
  
  //----------------------Traks and points -------------------------------------
  FairMCTracks    *Track     = new FairMCTracks("Monte-Carlo Tracks");
  FairMCPointDraw *VxdDetectorPoints = new FairMCPointDraw("FccVxdPoint", kBlue, kFullSquare);
  FairMCPointDraw *SitDetectorPoints = new FairMCPointDraw("FccSitPoint", kGreen, kFullSquare);
  FairMCPointDraw *TpcDetectorPoints = new FairMCPointDraw("FccTpcPoint", kRed, kFullSquare);
  FairMCPointDraw *HcalDetectorPoints = new FairMCPointDraw("FccHcalPoint", kMagenta, kFullSquare);
 
  fMan->AddTask(Track);
  fMan->AddTask(VxdDetectorPoints);
  fMan->AddTask(SitDetectorPoints);
  fMan->AddTask(TpcDetectorPoints);
  fMan->AddTask(HcalDetectorPoints);

  fMan->Init();                     

}
