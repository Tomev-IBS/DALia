//
// Created by Tomev on 07.04.2019.
// An interface class for rules.
//

#ifndef DALIA_TESTS_I_RULE_H
#define DALIA_TESTS_I_RULE_H

#include <unordered_map>
#include <memory>

namespace DALia {

  class i_rule() {
    public:
    private:
      virtual ~i_rule();
  }

  typedef std::shared_ptr<i_rule> rulePtr;

}

#endif //DALIA_TESTS_I_RULE_H
