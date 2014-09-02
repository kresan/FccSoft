/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef HCALGEOPAR_H
#define HCALGEOPAR_H

#include "FairParGenericSet.h"

class TObjArray;
class FairParamList;

class FccHcalGeoPar       : public FairParGenericSet
{
  public:

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoSensNodes;

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoPassNodes;

    FccHcalGeoPar(const char* name="FccHcalGeoPar",
                      const char* title="FccHcal Geometry Parameters",
                      const char* context="TestDefaultContext");
    ~FccHcalGeoPar(void);
    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);
    TObjArray* GetGeoSensitiveNodes() {return fGeoSensNodes;}
    TObjArray* GetGeoPassiveNodes()   {return fGeoPassNodes;}

  private:
    FccHcalGeoPar(const FccHcalGeoPar&);
    FccHcalGeoPar& operator=(const FccHcalGeoPar&);

    ClassDef(FccHcalGeoPar,1)
};

#endif
