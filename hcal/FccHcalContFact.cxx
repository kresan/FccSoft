/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "FccHcalContFact.h"

#include "FccHcalGeoPar.h"

#include "FairRuntimeDb.h"

#include <iostream>

ClassImp(FccHcalContFact)

static FccHcalContFact gFccHcalContFact;

FccHcalContFact::FccHcalContFact()
  : FairContFact()
{
  /** Constructor (called when the library is loaded) */
  fName="FccHcalContFact";
  fTitle="Factory for parameter containers in libFccHcal";
  setAllContainers();
  FairRuntimeDb::instance()->addContFactory(this);
}

void FccHcalContFact::setAllContainers()
{
  /** Creates the Container objects with all accepted
      contexts and adds them to
      the list of containers for the FccHcal library.
  */

  FairContainer* p= new FairContainer("FccHcalGeoPar",
                                      "FccHcal Geometry Parameters",
                                      "TestDefaultContext");
  p->addContext("TestNonDefaultContext");

  containers->Add(p);
}

FairParSet* FccHcalContFact::createContainer(FairContainer* c)
{
  /** Calls the constructor of the corresponding parameter container.
      For an actual context, which is not an empty string and not
      the default context
      of this container, the name is concatinated with the context.
  */
  const char* name=c->GetName();
  FairParSet* p=NULL;
  if (strcmp(name,"FccHcalGeoPar")==0) {
    p=new FccHcalGeoPar(c->getConcatName().Data(),
                            c->GetTitle(),c->getContext());
  }
  return p;
}
