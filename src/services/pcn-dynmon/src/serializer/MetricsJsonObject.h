/**
* dynmon API generated from dynmon.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* MetricsJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"


namespace polycube {
namespace service {
namespace model {


/// <summary>
///
/// </summary>
class  MetricsJsonObject : public JsonObjectBase {
public:
  MetricsJsonObject();
  MetricsJsonObject(const nlohmann::json &json);
  ~MetricsJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  /// Name of the metric (e.g, number of HTTP requests)
  /// </summary>
  std::string getName() const;
  void setName(std::string value);
  bool nameIsSet() const;

  /// <summary>
  /// Value of the metric
  /// </summary>
  std::string getValue() const;
  void setValue(std::string value);
  bool valueIsSet() const;
  void unsetValue();

  /// <summary>
  /// Timestamp
  /// </summary>
  int64_t getTimestamp() const;
  void setTimestamp(int64_t value);
  bool timestampIsSet() const;
  void unsetTimestamp();

private:
  std::string m_name;
  bool m_nameIsSet;
  std::string m_value;
  bool m_valueIsSet;
  int64_t m_timestamp;
  bool m_timestampIsSet;
};

}
}
}
