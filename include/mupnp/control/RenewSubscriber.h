/******************************************************************
*
*  mUPnP for C++
*
*  Copyright (C) Satoshi Konno 2002
*
*  File: RenewSubscriber.h
*
*  Revision;
*
*  07/07/04
*    - first revision
*
******************************************************************/

#ifndef _MUPMPCC_RENEWSUBSCRIBER_H_
#define _MUPMPCC_RENEWSUBSCRIBER_H_

#include <uhttp/util/Thread.h>

namespace mUPnP {
class ControlPoint;

class RenewSubscriber : public uHTTP::Thread {
 public:
  ////////////////////////////////////////////////
  // Constants
  ////////////////////////////////////////////////

  static const long INTERVAL;

  ////////////////////////////////////////////////
  // Constructor
  ////////////////////////////////////////////////

 public:
  RenewSubscriber(ControlPoint *ctrlp) {
    setControlPoint(ctrlp);
  }
  
  ////////////////////////////////////////////////
  // Member
  ////////////////////////////////////////////////

private:
  
  ControlPoint *controlPoint;

 public:
  void setControlPoint(ControlPoint *ctrlp) {
    controlPoint = ctrlp;
  }
  
  ControlPoint *getControlPoint() {
    return controlPoint;
  }

  ////////////////////////////////////////////////
  // Thread
  ////////////////////////////////////////////////
  
 public:
  void run();

};

}

#endif

