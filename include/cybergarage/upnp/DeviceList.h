/******************************************************************
*
*  CyberLink for C++
*
*  Copyright (C) Satoshi Konno 2002
*
*  File: DeviceList.h
*
*  Revision;
*
*  07/20/03
*    - first revision
*
******************************************************************/

#ifndef _CLINK_DEVICELIST_H_
#define _CLINK_DEVICELIST_H_

#include <uhttp/util/Vector.h>

namespace CyberLink {
class Device;

class DeviceList : public uHTTP::Vector<Device> {
public:
  ////////////////////////////////////////////////
  // Constants
  ////////////////////////////////////////////////
  
  static const char *ELEM_NAME;

public:
  ////////////////////////////////////////////////
  // Constructor
  ////////////////////////////////////////////////
  
  DeviceList() 
  {
  }
  
  ////////////////////////////////////////////////
  // Methods
  ////////////////////////////////////////////////
  
  Device *getDevice(size_t n) {
    return get(n);
  }
};

}

#endif


