/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


#pragma once


#include "../base/NodeportRuleBase.h"


class K8sdispatcher;

using namespace polycube::service::model;

class NodeportRule : public NodeportRuleBase {
public:
    NodeportRule(K8sdispatcher &parent, const NodeportRuleJsonObject &conf);
    virtual void update(const NodeportRuleJsonObject &conf);
    virtual NodeportRuleJsonObject toJsonObject();

    virtual ~NodeportRule();

    /// <summary>
    /// An optional name for the NodePort rule
    /// </summary>
    std::string getNodeportName() override;

    void setNodeportName(const std::string &value) override;

    /// <summary>
    /// Destination L4 port number
    /// </summary>
    uint16_t getNodeportPort() override;

    /// <summary>
    /// L4 protocol
    /// </summary>
    std::string getProto() override;

    /// <summary>
    /// Denotes if this Service desires to route external traffic to node-local or cluster-wide endpoint
    /// </summary>
    NodeportRuleServiceTypeEnum getServiceType() override;

    void setServiceType(const NodeportRuleServiceTypeEnum &value) override;

    static int serviceTypeToInt(const NodeportRuleServiceTypeEnum &serviceType);

private:
    K8sdispatcher &parent_;
    std::string nodeportName_;
    uint16_t nodeportPort_;
    std::string proto_;
    NodeportRuleServiceTypeEnum serviceType_;
};
