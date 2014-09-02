/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef TPCCONTFACT_H
#define TPCCONTFACT_H

#include "FairContFact.h"

class FairContainer;

class FccTpcContFact : public FairContFact
{
  private:
    void setAllContainers();
  public:
    FccTpcContFact();
    ~FccTpcContFact() {}
    FairParSet* createContainer(FairContainer*);
    ClassDef( FccTpcContFact,0) // Factory for all FccTpc parameter containers
};

#endif
