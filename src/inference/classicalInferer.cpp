//
// Created by Tomev on 15.04.2019.
// This class is an implementation of classical inference.
//

#include "classicalInferer.h"
#include <algorithm>
#include <cassert>

/**
 * @brief Performs classical inference on given rule vector.
 * @param Vector of rules called rules.
 * @param
 */
void DALia::classicalInferer::infer( std::vector<rulePtr> rules,
                              std::unordered_map<std::string, std::vector<std::string>> facts ){

  _facts = facts;

  int indexOfRuleToFire = findRuleToFire(rules);

  // Note that classical inference is required by definition to fire all possible rules
  while(indexOfRuleToFire != -1){
    fireRule(indexOfRuleToFire, rules);
    indexOfRuleToFire = findRuleToFire(rules);
  }

}

/**
 * @brief Looks into rules vector to find the first rule to fire starting from the beginning of the vector.
 * If no rule could be fired then -1 is returned instead.
 *
 * @return Index of the rule to fire of -1 if no rule could be fired.
 */
int DALia::classicalInferer::findRuleToFire(const std::vector<rulePtr>& rules) const {
  int indexOfRuleToFire = -1;

  // Check loop exit condition.
  for(unsigned int i = 0; i < rules.size() && indexOfRuleToFire == -1; ++i){
    if(!canRuleBeFired(const_cast<rulePtr &>(rules[i]))) continue;
    indexOfRuleToFire = i;
  }

  return indexOfRuleToFire;
}

/**
 * @brief A method deciding whether a rule can be fired or not basing on given facts.
 * @param r A pointer to examined rule.
 * @return True if rule can be fired, false otherwise.
 */
bool DALia::classicalInferer::canRuleBeFired(rulePtr& r) const {
  auto rulePremises = r->getPremises();

  for(const auto& kv : rulePremises){
    std::string attributeName = kv.first;

    // If map doesn't have data on given attribute return false.
    if(_facts.find(attributeName) == _facts.end()) return false;

    std::vector<std::string> attributeValues = kv.second;

    for(const auto& value : attributeValues){
      auto valuePosition = std::find(_facts.at(attributeName).begin(), _facts.at(attributeName).end(), value);

      // Return false if there is no such value in facts for given attribute.
      if(valuePosition == _facts.at(attributeName).end()) return false;
    }
  }

  return true;
}

/**
 * Fires the rule denoted by index from given vector of rules. It's conclusion will be added to facts and it will
 * be removed from rules vector. Note that there won't be premise check, as it was performed earlier, on the rule index
 * finding phase.
 *
 * @brief Fires the rule denoted by index from given vector of rules.
 * @param indexOfRuleToFire -- self explanatory parameter.
 * @param rules -- vector of rules that
 */
void DALia::classicalInferer::fireRule(const int& indexOfRuleToFire, std::vector<rulePtr> rules){
  assert(rules.size() > indexOfRuleToFire);

  std::unordered_map<std::string, std::vector<std::string>> conclusions = rules[indexOfRuleToFire]->getConclusion();

  for(const auto& kv : conclusions){
    // Add key to facts map if facts don't contain it already.
    if(_facts.find(kv.first) == _facts.end()){
      _facts[kv.first] = kv.second;
      continue;
    }

    // Add non-duplicate information to facts map.
    std::vector<std::string> attributeValues = kv.second;

    for(const std::string& val : attributeValues){
      if(std::find(_facts[kv.first].begin(), _facts[kv.first].end(), val) != _facts[kv.first].end()) continue;
      _facts[kv.first].push_back(val);
    }
  }

  // Remove the rule.
  rules.erase(rules.begin() + indexOfRuleToFire);
}

/**
 * @brief Returns type of inference.
 * @return Const string "Classical Inference".
 */
std::string DALia::classicalInferer::getInferenceType() {
  return "Classical Inference";
}

bool DALia::classicalInferer::wasInferenceTargetSet() {
  return !_inferenceTarget.empty();
}

bool DALia::classicalInferer::wasInferenceTargetInitiallyConfirmable() {
  return false;
}

unsigned int DALia::classicalInferer::getNumberOfInferenceIterations() {
  return 0;
}

bool DALia::classicalInferer::wasAnyRuleFired() {
  return false;
}

unsigned int DALia::classicalInferer::getNumberOfRulesFired() {
  return 0;
}

unsigned int DALia::classicalInferer::getNumberOfNewFacts() {
  return 0;
}

bool DALia::classicalInferer::wasInferenceTargetConfirmed() {
  return false;
}

bool DALia::classicalInferer::wasNewKnowledgeExplored() {
  return false;
}

int DALia::classicalInferer::getNumberOfCheckedObjects() {
  return 0;
}

int DALia::classicalInferer::getNumberOfRulesThatCouldBeFired() {
  return 0;
}

double DALia::classicalInferer::getInferenceTime() {
  return 0;
}

unsigned int DALia::classicalInferer::getNumberOfRulesThatCouldInitiallyBeFired() {
  return 0;
}



