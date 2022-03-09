/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* NodeportRuleJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"


namespace polycube {
namespace service {
namespace model {

enum class NodeportRuleServiceTypeEnum {
  CLUSTER, LOCAL
};

/// <summary>
///
/// </summary>
class  NodeportRuleJsonObject : public JsonObjectBase {
public:
  NodeportRuleJsonObject();
  NodeportRuleJsonObject(const nlohmann::json &json);
  ~NodeportRuleJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  /// An optional name for the NodePort rule
  /// </summary>
  std::string getNodeportName() const;
  void setNodeportName(std::string value);
  bool nodeportNameIsSet() const;
  void unsetNodeportName();

  /// <summary>
  /// Destination L4 port number
  /// </summary>
  uint16_t getNodeportPort() const;
  void setNodeportPort(uint16_t value);
  bool nodeportPortIsSet() const;

  /// <summary>
  /// L4 protocol
  /// </summary>
  std::string getProto() const;
  void setProto(std::string value);
  bool protoIsSet() const;

  /// <summary>
  /// Denotes if this Service desires to route external traffic to node-local or cluster-wide endpoint
  /// </summary>
  NodeportRuleServiceTypeEnum getServiceType() const;
  void setServiceType(NodeportRuleServiceTypeEnum value);
  bool serviceTypeIsSet() const;
  static std::string NodeportRuleServiceTypeEnum_to_string(const NodeportRuleServiceTypeEnum &value);
  static NodeportRuleServiceTypeEnum string_to_NodeportRuleServiceTypeEnum(const std::string &str);

private:
  std::string m_nodeportName;
  bool m_nodeportNameIsSet;
  uint16_t m_nodeportPort;
  bool m_nodeportPortIsSet;
  std::string m_proto;
  bool m_protoIsSet;
  NodeportRuleServiceTypeEnum m_serviceType;
  bool m_serviceTypeIsSet;
};

}
}
}
