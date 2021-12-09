/**
* k8slbrp API generated from k8slbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "ServiceBackendBase.h"
#include "../K8slbrp.h"


ServiceBackendBase::ServiceBackendBase(Service &parent)
    : parent_(parent) {}

ServiceBackendBase::~ServiceBackendBase() {}

void ServiceBackendBase::update(const ServiceBackendJsonObject &conf) {

  if (conf.nameIsSet()) {
    setName(conf.getName());
  }
  if (conf.portIsSet()) {
    setPort(conf.getPort());
  }
  if (conf.weightIsSet()) {
    setWeight(conf.getWeight());
  }
}

ServiceBackendJsonObject ServiceBackendBase::toJsonObject() {
  ServiceBackendJsonObject conf;

  conf.setName(getName());
  conf.setIp(getIp());
  conf.setPort(getPort());
  conf.setWeight(getWeight());

  return conf;
}

std::shared_ptr<spdlog::logger> ServiceBackendBase::logger() {
  return parent_.logger();
}

