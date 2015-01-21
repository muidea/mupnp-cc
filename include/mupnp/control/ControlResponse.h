/******************************************************************
 *
 * mUPnP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#ifndef _MUPMPCC_CONTROLRESPONSE_H_
#define _MUPMPCC_CONTROLRESPONSE_H_

#include <mupnp/soap/SOAPResponse.h>
#include <mupnp/xml/Node.h>
#include <mupnp/soap/SOAP.h>
#include <mupnp/UPnP.h>
#include <mupnp/UPnPStatus.h>

#include <sstream>

namespace mUPnP {
class ControlResponse : public mUPnP::SOAPResponse {
  UPnPStatus upnpErr;

public:
  ////////////////////////////////////////////////
  // Constructor
  ////////////////////////////////////////////////

  static const char *FAULT_CODE;
  static const char *FAULT_STRING;

public:
  ////////////////////////////////////////////////
  // Constructor
  ////////////////////////////////////////////////
  
  ControlResponse() {
    std::string serverName;
    setServer(UPnP::GetServerName(serverName));
  }

  ControlResponse(SOAPResponse *soapRes) {
    set(soapRes);
  }

  ////////////////////////////////////////////////
  // FaultResponse
  ////////////////////////////////////////////////

public:
  
  void setFaultResponse(int errCode, const std::string &errDescr);
  void setFaultResponse(int errCode) {
    setFaultResponse(errCode, UPnP::StatusCodeToString(errCode));
  }

private:
  
  mUPnP::Node *createFaultResponseNode(int errCode, const std::string &errDescr);

  ////////////////////////////////////////////////
  // UPnP Error
  ////////////////////////////////////////////////

private:

  mUPnP::Node *getUPnPErrorNode() {
    mUPnP::Node *detailNode = getFaultDetailNode();
    if (detailNode == NULL)
      return NULL;
    return detailNode->getNodeEndsWith(SOAP::UPNP_ERROR);
  }

  mUPnP::Node *getUPnPErrorCodeNode() {
    mUPnP::Node *errorNode = getUPnPErrorNode();
    if (errorNode == NULL)
      return NULL;
    return errorNode->getNodeEndsWith(SOAP::ERROR_CODE);
  }

  mUPnP::Node *getUPnPErrorDescriptionNode() {
    mUPnP::Node *errorNode = getUPnPErrorNode();
    if (errorNode == NULL)
      return NULL;
    return errorNode->getNodeEndsWith(SOAP::ERROR_DESCRIPTION);
  }

 public:
  int getUPnPErrorCode() {
    mUPnP::Node *errorCodeNode = getUPnPErrorCodeNode();
    if (errorCodeNode == NULL)
      return -1;
    const char *errorCodeStr = errorCodeNode->getValue();
    return atoi(errorCodeStr);
  }

  const char *getUPnPErrorDescription() {
    mUPnP::Node *errorDescNode = getUPnPErrorDescriptionNode();
    if (errorDescNode == NULL)
      return "";
    return errorDescNode->getValue();
  }

  UPnPStatus *getUPnPError() {
    upnpErr.setCode(getUPnPErrorCode());
    upnpErr.setDescription(getUPnPErrorDescription());
    return &upnpErr;
  }

};

}

#endif

