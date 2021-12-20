/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "K8sdispatcherApiImpl.h"

namespace polycube {
namespace service {
namespace api {

using namespace polycube::service::model;

namespace K8sdispatcherApiImpl {
namespace {
std::unordered_map<std::string, std::shared_ptr<K8sdispatcher>> cubes;
std::mutex cubes_mutex;

std::shared_ptr<K8sdispatcher> get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

}

void create_k8sdispatcher_by_id(const std::string &name, const K8sdispatcherJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<K8sdispatcher>(name, jsonObject);
  std::unordered_map<std::string, std::shared_ptr<K8sdispatcher>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void replace_k8sdispatcher_by_id(const std::string &name, const K8sdispatcherJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void delete_k8sdispatcher_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::vector<K8sdispatcherJsonObject> read_k8sdispatcher_list_by_id() {
  std::vector<K8sdispatcherJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/**
* @brief   Create natting-rule by ID
*
* Create operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value natting-rulebody object
*
* Responses:
*
*/
void
create_k8sdispatcher_natting_rule_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingRuleJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->addNattingRule(internalSrc, internalDst, internalSport, internalDport, proto, value);
}

/**
* @brief   Create natting-rule by ID
*
* Create operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] value natting-rulebody object
*
* Responses:
*
*/
void
create_k8sdispatcher_natting_rule_list_by_id(const std::string &name, const std::vector<NattingRuleJsonObject> &value) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->addNattingRuleList(value);
}

/**
* @brief   Create nodeport-rule by ID
*
* Create operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
* @param[in] value nodeport-rulebody object
*
* Responses:
*
*/
void
create_k8sdispatcher_nodeport_rule_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto, const NodeportRuleJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->addNodeportRule(nodeportPort, proto, value);
}

/**
* @brief   Create nodeport-rule by ID
*
* Create operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] value nodeport-rulebody object
*
* Responses:
*
*/
void
create_k8sdispatcher_nodeport_rule_list_by_id(const std::string &name, const std::vector<NodeportRuleJsonObject> &value) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->addNodeportRuleList(value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->addPorts(portsName, value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_k8sdispatcher_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->addPortsList(value);
}

/**
* @brief   Delete natting-rule by ID
*
* Delete operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
*
*/
void
delete_k8sdispatcher_natting_rule_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->delNattingRule(internalSrc, internalDst, internalSport, internalDport, proto);
}

/**
* @brief   Delete natting-rule by ID
*
* Delete operation of resource: natting-rule*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_k8sdispatcher_natting_rule_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->delNattingRuleList();
}

/**
* @brief   Delete nodeport-rule by ID
*
* Delete operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
*
* Responses:
*
*/
void
delete_k8sdispatcher_nodeport_rule_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->delNodeportRule(nodeportPort, proto);
}

/**
* @brief   Delete nodeport-rule by ID
*
* Delete operation of resource: nodeport-rule*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_k8sdispatcher_nodeport_rule_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->delNodeportRuleList();
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
*
*/
void
delete_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->delPorts(portsName);
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_k8sdispatcher_ports_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  k8sdispatcher->delPortsList();
}

/**
* @brief   Read k8sdispatcher by ID
*
* Read operation of resource: k8sdispatcher*
*
* @param[in] name ID of name
*
* Responses:
* K8sdispatcherJsonObject
*/
K8sdispatcherJsonObject
read_k8sdispatcher_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}

/**
* @brief   Read internal-src-ip by ID
*
* Read operation of resource: internal-src-ip*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_internal_src_ip_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getInternalSrcIp();

}

/**
* @brief   Read natting-rule by ID
*
* Read operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
* NattingRuleJsonObject
*/
NattingRuleJsonObject
read_k8sdispatcher_natting_rule_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getNattingRule(internalSrc, internalDst, internalSport, internalDport, proto)->toJsonObject();

}

/**
* @brief   Read external-ip by ID
*
* Read operation of resource: external-ip*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_natting_rule_external_ip_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  auto nattingRule = k8sdispatcher->getNattingRule(internalSrc, internalDst, internalSport, internalDport, proto);
  return nattingRule->getExternalIp();

}

/**
* @brief   Read external-port by ID
*
* Read operation of resource: external-port*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
*
* Responses:
* uint16_t
*/
uint16_t
read_k8sdispatcher_natting_rule_external_port_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  auto nattingRule = k8sdispatcher->getNattingRule(internalSrc, internalDst, internalSport, internalDport, proto);
  return nattingRule->getExternalPort();

}

/**
* @brief   Read natting-rule by ID
*
* Read operation of resource: natting-rule*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<NattingRuleJsonObject>
*/
std::vector<NattingRuleJsonObject>
read_k8sdispatcher_natting_rule_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  auto &&nattingRule = k8sdispatcher->getNattingRuleList();
  std::vector<NattingRuleJsonObject> m;
  for(auto &i : nattingRule)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read nodeport-range by ID
*
* Read operation of resource: nodeport-range*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_nodeport_range_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getNodeportRange();

}

/**
* @brief   Read nodeport-rule by ID
*
* Read operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
*
* Responses:
* NodeportRuleJsonObject
*/
NodeportRuleJsonObject
read_k8sdispatcher_nodeport_rule_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getNodeportRule(nodeportPort, proto)->toJsonObject();

}

/**
* @brief   Read nodeport-rule by ID
*
* Read operation of resource: nodeport-rule*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<NodeportRuleJsonObject>
*/
std::vector<NodeportRuleJsonObject>
read_k8sdispatcher_nodeport_rule_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  auto &&nodeportRule = k8sdispatcher->getNodeportRuleList();
  std::vector<NodeportRuleJsonObject> m;
  for(auto &i : nodeportRule)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read nodeport-name by ID
*
* Read operation of resource: nodeport-name*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_nodeport_rule_nodeport_name_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  auto nodeportRule = k8sdispatcher->getNodeportRule(nodeportPort, proto);
  return nodeportRule->getNodeportName();

}

/**
* @brief   Read service-type by ID
*
* Read operation of resource: service-type*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
*
* Responses:
* NodeportRuleServiceTypeEnum
*/
NodeportRuleServiceTypeEnum
read_k8sdispatcher_nodeport_rule_service_type_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto) {
  auto k8sdispatcher = get_cube(name);
  auto nodeportRule = k8sdispatcher->getNodeportRule(nodeportPort, proto);
  return nodeportRule->getServiceType();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsJsonObject
*/
PortsJsonObject
read_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);
  return k8sdispatcher->getPorts(portsName)->toJsonObject();

}

/**
* @brief   Read ip by ID
*
* Read operation of resource: ip*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* std::string
*/
std::string
read_k8sdispatcher_ports_ip_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);
  return ports->getIp();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<PortsJsonObject>
*/
std::vector<PortsJsonObject>
read_k8sdispatcher_ports_list_by_id(const std::string &name) {
  auto k8sdispatcher = get_cube(name);
  auto &&ports = k8sdispatcher->getPortsList();
  std::vector<PortsJsonObject> m;
  for(auto &i : ports)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsTypeEnum
*/
PortsTypeEnum
read_k8sdispatcher_ports_type_by_id(const std::string &name, const std::string &portsName) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);
  return ports->getType();

}

/**
* @brief   Replace natting-rule by ID
*
* Replace operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value natting-rulebody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_natting_rule_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingRuleJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->replaceNattingRule(internalSrc, internalDst, internalSport, internalDport, proto, value);
}

/**
* @brief   Replace natting-rule by ID
*
* Replace operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] value natting-rulebody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_natting_rule_list_by_id(const std::string &name, const std::vector<NattingRuleJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Replace nodeport-rule by ID
*
* Replace operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
* @param[in] value nodeport-rulebody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_nodeport_rule_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto, const NodeportRuleJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->replaceNodeportRule(nodeportPort, proto, value);
}

/**
* @brief   Replace nodeport-rule by ID
*
* Replace operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] value nodeport-rulebody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_nodeport_rule_list_by_id(const std::string &name, const std::vector<NodeportRuleJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->replacePorts(portsName, value);
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_k8sdispatcher_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update k8sdispatcher by ID
*
* Update operation of resource: k8sdispatcher*
*
* @param[in] name ID of name
* @param[in] value k8sdispatcherbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_by_id(const std::string &name, const K8sdispatcherJsonObject &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->update(value);
}

/**
* @brief   Update internal-src-ip by ID
*
* Update operation of resource: internal-src-ip*
*
* @param[in] name ID of name
* @param[in] value Internal src ip used for services with externalTrafficPolicy&#x3D;CLUSTER
*
* Responses:
*
*/
void
update_k8sdispatcher_internal_src_ip_by_id(const std::string &name, const std::string &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->setInternalSrcIp(value);
}

/**
* @brief   Update k8sdispatcher by ID
*
* Update operation of resource: k8sdispatcher*
*
* @param[in] value k8sdispatcherbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_list_by_id(const std::vector<K8sdispatcherJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update natting-rule by ID
*
* Update operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value natting-rulebody object
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_rule_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const NattingRuleJsonObject &value) {
  auto k8sdispatcher = get_cube(name);
  auto nattingRule = k8sdispatcher->getNattingRule(internalSrc, internalDst, internalSport, internalDport, proto);

  return nattingRule->update(value);
}

/**
* @brief   Update external-ip by ID
*
* Update operation of resource: external-ip*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value Translated IP address
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_rule_external_ip_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const std::string &value) {
  auto k8sdispatcher = get_cube(name);
  auto nattingRule = k8sdispatcher->getNattingRule(internalSrc, internalDst, internalSport, internalDport, proto);

  return nattingRule->setExternalIp(value);
}

/**
* @brief   Update external-port by ID
*
* Update operation of resource: external-port*
*
* @param[in] name ID of name
* @param[in] internalSrc ID of internal-src
* @param[in] internalDst ID of internal-dst
* @param[in] internalSport ID of internal-sport
* @param[in] internalDport ID of internal-dport
* @param[in] proto ID of proto
* @param[in] value Translated L4 port number
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_rule_external_port_by_id(const std::string &name, const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport, const uint16_t &internalDport, const std::string &proto, const uint16_t &value) {
  auto k8sdispatcher = get_cube(name);
  auto nattingRule = k8sdispatcher->getNattingRule(internalSrc, internalDst, internalSport, internalDport, proto);

  return nattingRule->setExternalPort(value);
}

/**
* @brief   Update natting-rule by ID
*
* Update operation of resource: natting-rule*
*
* @param[in] name ID of name
* @param[in] value natting-rulebody object
*
* Responses:
*
*/
void
update_k8sdispatcher_natting_rule_list_by_id(const std::string &name, const std::vector<NattingRuleJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update nodeport-range by ID
*
* Update operation of resource: nodeport-range*
*
* @param[in] name ID of name
* @param[in] value Port range used for NodePort services
*
* Responses:
*
*/
void
update_k8sdispatcher_nodeport_range_by_id(const std::string &name, const std::string &value) {
  auto k8sdispatcher = get_cube(name);

  return k8sdispatcher->setNodeportRange(value);
}

/**
* @brief   Update nodeport-rule by ID
*
* Update operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
* @param[in] value nodeport-rulebody object
*
* Responses:
*
*/
void
update_k8sdispatcher_nodeport_rule_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto, const NodeportRuleJsonObject &value) {
  auto k8sdispatcher = get_cube(name);
  auto nodeportRule = k8sdispatcher->getNodeportRule(nodeportPort, proto);

  return nodeportRule->update(value);
}

/**
* @brief   Update nodeport-rule by ID
*
* Update operation of resource: nodeport-rule*
*
* @param[in] name ID of name
* @param[in] value nodeport-rulebody object
*
* Responses:
*
*/
void
update_k8sdispatcher_nodeport_rule_list_by_id(const std::string &name, const std::vector<NodeportRuleJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update nodeport-name by ID
*
* Update operation of resource: nodeport-name*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
* @param[in] value An optional name for the NodePort rule
*
* Responses:
*
*/
void
update_k8sdispatcher_nodeport_rule_nodeport_name_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto, const std::string &value) {
  auto k8sdispatcher = get_cube(name);
  auto nodeportRule = k8sdispatcher->getNodeportRule(nodeportPort, proto);

  return nodeportRule->setNodeportName(value);
}

/**
* @brief   Update service-type by ID
*
* Update operation of resource: service-type*
*
* @param[in] name ID of name
* @param[in] nodeportPort ID of nodeport-port
* @param[in] proto ID of proto
* @param[in] value Denotes if this Service desires to route external traffic to node-local or cluster-wide endpoint
*
* Responses:
*
*/
void
update_k8sdispatcher_nodeport_rule_service_type_by_id(const std::string &name, const uint16_t &nodeportPort, const std::string &proto, const NodeportRuleServiceTypeEnum &value) {
  auto k8sdispatcher = get_cube(name);
  auto nodeportRule = k8sdispatcher->getNodeportRule(nodeportPort, proto);

  return nodeportRule->setServiceType(value);
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);

  return ports->update(value);
}

/**
* @brief   Update ip by ID
*
* Update operation of resource: ip*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value IP address of the node interface (only for FRONTEND port)
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_ip_by_id(const std::string &name, const std::string &portsName, const std::string &value) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);

  return ports->setIp(value);
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update type by ID
*
* Update operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value Type of the k8sdispatcher port (e.g. BACKEND or FRONTEND)
*
* Responses:
*
*/
void
update_k8sdispatcher_ports_type_by_id(const std::string &name, const std::string &portsName, const PortsTypeEnum &value) {
  auto k8sdispatcher = get_cube(name);
  auto ports = k8sdispatcher->getPorts(portsName);

  return ports->setType(value);
}



/*
 * help related
 */

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_natting_rule_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8sdispatcher = get_cube(name);

  auto &&nattingRule = k8sdispatcher->getNattingRuleList();
  for(auto &i : nattingRule) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["internalSrc"] = i->getInternalSrc();
    keys["internalDst"] = i->getInternalDst();
    keys["internalSport"] = std::to_string(i->getInternalSport());
    keys["internalDport"] = std::to_string(i->getInternalDport());
    keys["proto"] = i->getProto();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_nodeport_rule_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8sdispatcher = get_cube(name);

  auto &&nodeportRule = k8sdispatcher->getNodeportRuleList();
  for(auto &i : nodeportRule) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["nodeportPort"] = std::to_string(i->getNodeportPort());
    keys["proto"] = i->getProto();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_k8sdispatcher_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8sdispatcher = get_cube(name);

  auto &&ports = k8sdispatcher->getPortsList();
  for(auto &i : ports) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}


}

}
}
}

