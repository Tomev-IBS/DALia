//
// Created by Tomev on 07.04.2019.
// An interface class for inferers.
//

#ifndef DALIA_TESTS_I_INFERENCER_H
#define DALIA_TESTS_I_INFERER_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "i_rule.h"

namespace DALia {

  class i_inferer {
    public:
      virtual ~i_inferer();
      // Note that it has to be passed as a copy, as most inferers will remove rules that were fired during inference.
      virtual void infer(std::vector<rulePtr> rules, std::unordered_map<std::string, std::vector<std::string>> facts) = 0;
      // A few information has to be provided for experiments
      virtual std::string getInferenceType() = 0;
      virtual unsigned int getNumberOfRulesThatCouldInitiallyBeFired() = 0;
      virtual bool wasInferenceTargetSet() = 0;
      virtual bool wasInferenceTargetInitiallyConfirmable() = 0;
      virtual unsigned int getNumberOfInferenceIterations() = 0;
      virtual bool wasAnyRuleFired() = 0;
      virtual unsigned int getNumberOfRulesFired() = 0;
      virtual unsigned int getNumberOfNewFacts() = 0;
      // Note that inference target is also confirmed in case where no target was assigned, but a rule was fired.
      virtual bool wasInferenceTargetConfirmed() = 0;
      virtual bool wasNewKnowledgeExplored() = 0;
      // Note that inference can be done on different kind of objects (e.g. clusters)
      virtual int getNumberOfCheckedObjects() = 0;
      virtual int getNumberOfRulesThatCouldBeFired() = 0;
      virtual double getInferenceTime() = 0;
  };

  typedef std::shared_ptr<i_inferer> infererPtr;
}


#endif //DALIA_TESTS_I_INFERENCER_H
