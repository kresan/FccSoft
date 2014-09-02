/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef SITGEOPAR_H
#define SITGEOPAR_H

#include "FairParGenericSet.h"

class TObjArray;
class FairParamList;

class FccSitGeoPar       : public FairParGenericSet
{
  public:

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoSensNodes;

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoPassNodes;

    FccSitGeoPar(const char* name="FccSitGeoPar",
                      const char* title="FccSit Geometry Parameters",
                      const char* context="TestDefaultContext");
    ~FccSitGeoPar(void);
    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);
    TObjArray* GetGeoSensitiveNodes() {return fGeoSensNodes;}
    TObjArray* GetGeoPassiveNodes()   {return fGeoPassNodes;}

  private:
    FccSitGeoPar(const FccSitGeoPar&);
    FccSitGeoPar& operator=(const FccSitGeoPar&);

    ClassDef(FccSitGeoPar,1)
};

#endif
