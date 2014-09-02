/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                    FccPipe file                                -----
// -----                Created by M. Al-Turany  June 2014             -----
// -------------------------------------------------------------------------

#ifndef PIPE_H
#define PIPE_H

#include "FairModule.h"

class FccPipe : public FairModule {
  public:
    FccPipe(const char * name, const char *Title="Fcc Pipe");
    FccPipe();

    virtual ~FccPipe();
    virtual void ConstructGeometry();
   
  ClassDef(FccPipe,1) //FccPIPE

};

#endif //PIPE_H

