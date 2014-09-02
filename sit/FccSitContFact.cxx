/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "FccSitContFact.h"

#include "FccSitGeoPar.h"

#include "FairRuntimeDb.h"

#include <iostream>

ClassImp(FccSitContFact)

static FccSitContFact gFccSitContFact;

FccSitContFact::FccSitContFact()
  : FairContFact()
{
  /** Constructor (called when the library is loaded) */
  fName="FccSitContFact";
  fTitle="Factory for parameter containers in libFccSit";
  setAllContainers();
  FairRuntimeDb::instance()->addContFactory(this);
}

void FccSitContFact::setAllContainers()
{
  /** Creates the Container objects with all accepted
      contexts and adds them to
      the list of containers for the FccSit library.
  */

  FairContainer* p= new FairContainer("FccSitGeoPar",
                                      "FccSit Geometry Parameters",
                                      "TestDefaultContext");
  p->addContext("TestNonDefaultContext");

  containers->Add(p);
}

FairParSet* FccSitContFact::createContainer(FairContainer* c)
{
  /** Calls the constructor of the corresponding parameter container.
      For an actual context, which is not an empty string and not
      the default context
      of this container, the name is concatinated with the context.
  */
  const char* name=c->GetName();
  FairParSet* p=NULL;
  if (strcmp(name,"FccSitGeoPar")==0) {
    p=new FccSitGeoPar(c->getConcatName().Data(),
                            c->GetTitle(),c->getContext());
  }
  return p;
}
