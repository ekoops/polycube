/**
* k8slbrp API generated from k8slbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* ServiceBackendBase.h
*
*
*/

#pragma once

#include "../serializer/ServiceBackendJsonObject.h"






#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class Service;

class ServiceBackendBase {
 public:
  
  ServiceBackendBase(Service &parent);
  
  virtual ~ServiceBackendBase();
  virtual void update(const ServiceBackendJsonObject &conf);
  virtual ServiceBackendJsonObject toJsonObject();

  /// <summary>
  /// name
  /// </summary>
  virtual std::string getName() = 0;
  virtual void setName(const std::string &value) = 0;

  /// <summary>
  /// IP address of the backend server of the pool
  /// </summary>
  virtual std::string getIp() = 0;

  /// <summary>
  /// Port where the server listen to (this value is ignored in case of ICMP)
  /// </summary>
  virtual uint16_t getPort() = 0;
  virtual void setPort(const uint16_t &value) = 0;

  /// <summary>
  /// Weight of the backend in the pool
  /// </summary>
  virtual uint16_t getWeight() = 0;
  virtual void setWeight(const uint16_t &value) = 0;

  std::shared_ptr<spdlog::logger> logger();
 protected:
  Service &parent_;
};