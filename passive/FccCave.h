/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    FccCave  file                               -----
// -----                Created 26/03/14  by M. Al-Turany              -----
// -------------------------------------------------------------------------


#ifndef Cave_H
#define Cave_H

#include "FairModule.h"                 // for FairModule

#include "Rtypes.h"                     // for FccCave::Class, ClassDef, etc

class FccCave : public FairModule
{
  public:
    FccCave(const char* name, const char* Title="Exp Cave");
    FccCave();
    virtual ~FccCave();
    virtual void ConstructGeometry();


  private:
    Double_t world[3];
    ClassDef(FccCave,1) //PNDCaveSD
};

#endif //Cave_H

