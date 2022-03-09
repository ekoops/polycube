/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/

#include "Ports.h"
#include "K8sdispatcher.h"


Ports::Ports(polycube::service::Cube <Ports> &parent,
             std::shared_ptr <polycube::service::PortIface> port,
             const PortsJsonObject &conf)
        : PortsBase(parent, port) {
    auto name = port->name();
    logger()->info("creating new port {0}", name);
    this->portType_ = conf.getType();
    if (conf.ipIsSet()) {
        this->ip_ = conf.getIp();
    }
    logger()->info("created new port {0}", name);
}

Ports::~Ports() {}

PortsTypeEnum Ports::getType() {
    return this->portType_;
}

void Ports::setType(const PortsTypeEnum &value) {
    logger()->warn("Ports::setType: Method not implemented");
    throw std::runtime_error("Ports::setType: Method not implemented");
}

std::string Ports::getIp() {
    return this->ip_;
}

void Ports::setIp(const std::string &value) {
    logger()->warn("Ports::setIp: Method not implemented");
    throw std::runtime_error("Ports::setIp: Method not implemented");
}