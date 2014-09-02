/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef TPCGEOPAR_H
#define TPCGEOPAR_H

#include "FairParGenericSet.h"

class TObjArray;
class FairParamList;

class FccTpcGeoPar       : public FairParGenericSet
{
  public:

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoSensNodes;

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoPassNodes;

    FccTpcGeoPar(const char* name="FccTpcGeoPar",
                      const char* title="FccTpc Geometry Parameters",
                      const char* context="TestDefaultContext");
    ~FccTpcGeoPar(void);
    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);
    TObjArray* GetGeoSensitiveNodes() {return fGeoSensNodes;}
    TObjArray* GetGeoPassiveNodes()   {return fGeoPassNodes;}

  private:
    FccTpcGeoPar(const FccTpcGeoPar&);
    FccTpcGeoPar& operator=(const FccTpcGeoPar&);

    ClassDef(FccTpcGeoPar,1)
};

#endif
