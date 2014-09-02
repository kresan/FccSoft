/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef NEWDETECTORCONTFACT_H
#define NEWDETECTORCONTFACT_H

#include "FairContFact.h"

class FairContainer;

class FccVxdContFact : public FairContFact
{
  private:
    void setAllContainers();
  public:
    FccVxdContFact();
    ~FccVxdContFact() {}
    FairParSet* createContainer(FairContainer*);
    ClassDef( FccVxdContFact,0) // Factory for all FccVxd parameter containers
};

#endif
