//
// Created by Tomev on 07.04.2019.
// An interface class for rules.
//

#ifndef DALIA_TESTS_I_RULE_H
#define DALIA_TESTS_I_RULE_H

#include <unordered_map>
#include <memory>

namespace DALia {

  class i_rule {
    public:
      /**
       * One can imagine, that premises and conclusions has multiple in one attribute, that are not necessarily joined
       * together. Consider the rule:
       *
       * "wantsToStopExplosion=true=>buttonToPress=Red,ButtonToPress=Blue"
       *
       * meaning, that these to buttons should be pressed. There's no reason for rules to be in that form, but there's
       * also no reason for them not to. The interface should provide the way to process both cases.
      */
      virtual std::unordered_map<std::string, std::vector<std::string>> getPremises() = 0;
      virtual std::unordered_map<std::string, std::vector<std::string>> getConclusion() = 0;

      virtual ~i_rule();
  };

  typedef std::shared_ptr<i_rule> rulePtr;

}

#endif //DALIA_TESTS_I_RULE_H
