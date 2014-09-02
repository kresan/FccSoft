/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "FccVxdContFact.h"

#include "FccVxdGeoPar.h"

#include "FairRuntimeDb.h"

#include <iostream>

ClassImp(FccVxdContFact)

static FccVxdContFact gFccVxdContFact;

FccVxdContFact::FccVxdContFact()
  : FairContFact()
{
  /** Constructor (called when the library is loaded) */
  fName="FccVxdContFact";
  fTitle="Factory for parameter containers in libFccVxd";
  setAllContainers();
  FairRuntimeDb::instance()->addContFactory(this);
}

void FccVxdContFact::setAllContainers()
{
  /** Creates the Container objects with all accepted
      contexts and adds them to
      the list of containers for the FccVxd library.
  */

  FairContainer* p= new FairContainer("FccVxdGeoPar",
                                      "FccVxd Geometry Parameters",
                                      "TestDefaultContext");
  p->addContext("TestNonDefaultContext");

  containers->Add(p);
}

FairParSet* FccVxdContFact::createContainer(FairContainer* c)
{
  /** Calls the constructor of the corresponding parameter container.
      For an actual context, which is not an empty string and not
      the default context
      of this container, the name is concatinated with the context.
  */
  const char* name=c->GetName();
  FairParSet* p=NULL;
  if (strcmp(name,"FccVxdGeoPar")==0) {
    p=new FccVxdGeoPar(c->getConcatName().Data(),
                            c->GetTitle(),c->getContext());
  }
  return p;
}
