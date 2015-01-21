/******************************************************************
 *
 * mUPnP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#ifndef _MUPMPCC_DEVICELIST_H_
#define _MUPMPCC_DEVICELIST_H_

#include <uhttp/util/Vector.h>

namespace mUPnP {
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


