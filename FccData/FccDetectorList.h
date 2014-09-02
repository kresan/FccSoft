/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

// -------------------------------------------------------------------------
// -----                  FccDetectorList header file               -----
// -----                  M. Al-Turany   June 2014                     -----
// -------------------------------------------------------------------------


/** Defines unique identifier for all Fcc detectors system **/
/** THis is needed for stack filtring **/

#ifndef FccDetectorList_H
#define FccDetectorList_H 1
// kSTOPHERE is needed for iteration over the enum. All detectors have to be put before.
enum DetectorId {kREF, kFccVxd, kFccSit, kFccTpc, kFccHcal, kSTOPHERE};

#endif
