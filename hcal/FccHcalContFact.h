/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef HCALCONTFACT_H
#define HCALCONTFACT_H

#include "FairContFact.h"

class FairContainer;

class FccHcalContFact : public FairContFact
{
  private:
    void setAllContainers();
  public:
    FccHcalContFact();
    ~FccHcalContFact() {}
    FairParSet* createContainer(FairContainer*);
    ClassDef( FccHcalContFact,0) // Factory for all FccHcal parameter containers
};

#endif
