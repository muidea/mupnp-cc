/******************************************************************
*
*  mUPnP for C++
*
*  Copyright (C) Satoshi Konno 2002
*
*  File: QueryResponse.h
*
*  Revision;
*
*  08/13/03
*    - first revision
*
******************************************************************/

#ifndef _MUPMPCC_QUERYRESPONSE_H_
#define _MUPMPCC_QUERYRESPONSE_H_

#include <mupnp/control/ControlResponse.h>
#include <cybergarage/soap/SOAP.h>

#include <sstream>

namespace mUPnP {
class StateVariable;

class QueryResponse : public ControlResponse {
public:
  ////////////////////////////////////////////////
  // Constructor
  ////////////////////////////////////////////////
  
  QueryResponse() {
  }

  QueryResponse(CyberSOAP::SOAPResponse *soapRes) {
    set(soapRes);
  }

  ////////////////////////////////////////////////
  // Qyery
  ////////////////////////////////////////////////

private:

  CyberXML::Node *getReturnNode();
  
 public:
  const char *getReturnValue();

  ////////////////////////////////////////////////
  // Response
  ////////////////////////////////////////////////

 public:
  void setResponse(StateVariable *stateVar);

private:

  CyberXML::Node *createResponseNode(const std::string &value);
};

}

#endif
