//
// Created by Tomev on 15.04.2019.
// Classical inferer implementation.
//

#ifndef DALIA_CLASSICALINFERER_H
#define DALIA_CLASSICALINFERER_H

#include <unordered_map>
#include <vector>

#include "i_inferer.h"

namespace DALia {

  class classicalInferer : public i_inferer {
    public:
      classicalInferer();
      void infer(std::vector<rulePtr> rules, std::unordered_map<std::string, std::vector<std::string>> facts) override ;
      std::string getInferenceType() override ;
      unsigned int getNumberOfRulesThatCouldInitiallyBeFired() override;

      bool wasInferenceTargetSet() override;
      ~classicalInferer() override;
      bool wasInferenceTargetInitiallyConfirmable() override;
      unsigned int getNumberOfInferenceIterations() override;
      bool wasAnyRuleFired() override;
      unsigned int getNumberOfRulesFired() override;
      unsigned int getNumberOfNewFacts() override;
      bool wasInferenceTargetConfirmed() override;
      bool wasNewKnowledgeExplored() override;
      int getNumberOfCheckedObjects() override;
      int getNumberOfRulesThatCouldBeFired() override;
      double getInferenceTime() override;
    protected:
      unsigned int numberOfRulesFired = 0;
      std::unordered_map<std::string, std::vector<std::string>> _facts;
      std::unordered_map<std::string, std::vector<std::string>> _inferenceTarget;

      int findRuleToFire(const std::vector<rulePtr>& rules) const;
      bool canRuleBeFired(rulePtr& r) const;
      void fireRule(const int& indexOfRuleToFire, std::vector<rulePtr> rules);
  };

}


#endif //DALIA_CLASSICALINFERER_H
