/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    FccFieldCreator header file                  -----
// -----                Created 26/03/14  by M. Al-Turany              -----
// -------------------------------------------------------------------------


#ifndef FccFieldCreator_H
#define FccFieldCreator_H

#include "FairFieldFactory.h"

class FccFieldPar;

class FairField;

class FccFieldCreator : public FairFieldFactory 
{

 public:
  FccFieldCreator();
  virtual ~FccFieldCreator();
  virtual FairField* createFairField();
  virtual void SetParm();
  ClassDef(FccFieldCreator,1);
  
 protected:
  FccFieldPar* fFieldPar;
  
 private:
  FccFieldCreator(const FccFieldCreator&);
  FccFieldCreator& operator=(const FccFieldCreator&);

};
#endif //FccFieldCreator_H
