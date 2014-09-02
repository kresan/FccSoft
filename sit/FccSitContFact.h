/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef SITCONTFACT_H
#define SITCONTFACT_H

#include "FairContFact.h"

class FairContainer;

class FccSitContFact : public FairContFact
{
  private:
    void setAllContainers();
  public:
    FccSitContFact();
    ~FccSitContFact() {}
    FairParSet* createContainer(FairContainer*);
    ClassDef( FccSitContFact,0) // Factory for all FccSit parameter containers
};

#endif
