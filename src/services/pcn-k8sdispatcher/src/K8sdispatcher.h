/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


#pragma once


#include "../base/K8sdispatcherBase.h"
#include <cinttypes>

#include "NattingRule.h"
#include "NodeportRule.h"
#include "Ports.h"
#include "hash_tuple.h"

using namespace polycube::service::model;
using namespace polycube::service;

/* definitions copied from datapath */
struct dp_k {
    uint64_t dummy;
    uint16_t external_port;
    uint16_t proto;
} __attribute__((packed));

struct dp_v {
    uint16_t internal_port;
    uint16_t entry_type;
} __attribute__((packed));

class K8sdispatcher : public K8sdispatcherBase {
    friend class NodeportRule;

public:
    K8sdispatcher(const std::string name, const K8sdispatcherJsonObject &conf);

    virtual ~K8sdispatcher();

    void packet_in(Ports &port,
                   polycube::service::PacketInMetadata &md,
                   const std::vector<uint8_t> &packet) override;

    /// <summary>
    /// Entry of the ports table
    /// </summary>
    std::shared_ptr<Ports> getPorts(const std::string &name) override;

    std::vector<std::shared_ptr<Ports>> getPortsList() override;

    void addPorts(const std::string &name, const PortsJsonObject &conf) override;

    void addPortsList(const std::vector<PortsJsonObject> &conf) override;

    void replacePorts(const std::string &name, const PortsJsonObject &conf) override;

    void delPorts(const std::string &name) override;

    void delPortsList() override;

    /// <summary>
    /// Internal src ip used for services with externalTrafficPolicy&#x3D;CLUSTER
    /// </summary>
    std::string getInternalSrcIp() override;

    void setInternalSrcIp(const std::string &value) override;

    /// <summary>
    ///
    /// </summary>
    std::shared_ptr<NattingRule>
    getNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport,
                   const uint16_t &internalDport, const std::string &proto) override;

    std::vector<std::shared_ptr<NattingRule>> getNattingRuleList() override;

    void addNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport,
                        const uint16_t &internalDport, const std::string &proto,
                        const NattingRuleJsonObject &conf) override;

    void addNattingRuleList(const std::vector<NattingRuleJsonObject> &conf) override;

    void
    replaceNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport,
                       const uint16_t &internalDport, const std::string &proto,
                       const NattingRuleJsonObject &conf) override;

    void delNattingRule(const std::string &internalSrc, const std::string &internalDst, const uint16_t &internalSport,
                        const uint16_t &internalDport, const std::string &proto) override;

    void delNattingRuleList() override;

    /// <summary>
    ///
    /// </summary>
    std::shared_ptr<NodeportRule> getNodeportRule(const uint16_t &nodeportPort, const std::string &proto) override;

    std::vector<std::shared_ptr<NodeportRule>> getNodeportRuleList() override;

    void addNodeportRule(const uint16_t &nodeportPort, const std::string &proto,
                         const NodeportRuleJsonObject &conf) override;

    void addNodeportRuleList(const std::vector<NodeportRuleJsonObject> &conf) override;

    void updateNodeportRuleList(const std::vector<NodeportRuleJsonObject> &conf) override;

    void replaceNodeportRule(const uint16_t &nodeportPort, const std::string &proto,
                             const NodeportRuleJsonObject &conf) override;

    void replaceNodeportRuleList(const std::vector<NodeportRuleJsonObject> &conf) override;

    void delNodeportRule(const uint16_t &nodeportPort, const std::string &proto) override;

    void delNodeportRuleList() override;

    /// <summary>
    /// Port range used for NodePort services
    /// </summary>
    std::string getNodeportRange() override;

    void setNodeportRange(const std::string &value) override;

    void update(const K8sdispatcherJsonObject &conf);
    K8sdispatcherJsonObject toJsonObject();

    typedef std::tuple<std::string, uint16_t> NodeportKey;


    static uint16_t protoStrToInt(const std::string &proto);

    static std::string protoIntToStr(const uint16_t proto);

    static int serviceTypeToInt(const NodeportRuleServiceTypeEnum &serviceType);

private:
    bool inBuilding_;
    bool needReload_;

    std::string nodePortRange_;
    uint16_t nodePortRangeLow_;
    uint16_t nodePortRangeHigh_;

    std::string nattedIpString_;
    uint32_t nattedIp_;

    std::string externalIpString_;
    uint32_t externalIp_;

    std::unordered_map<NodeportKey, NodeportRule> nodePortMap_;
    static const std::string EBPF_DP_RULES_MAP;

    void setExternalIp(const std::string &value);

    uint32_t ip_to_dec(const std::string &ip);

    void parse_cidr(const std::string &cidr, uint32_t *subnet, uint32_t *netmask);

    void reloadConfig();

    std::shared_ptr<Ports> getFrontendPort();

    std::shared_ptr<Ports> getBackendPort();
};
