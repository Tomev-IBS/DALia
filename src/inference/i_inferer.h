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

#include "rule"

namespace DALia {

  class i_inferer {
    public:
      virtual void infer(std::vector<rulePtr> rules) = 0;
      virtual std::unordered_map<std::string, std::string> getReport() = 0;
    private:
      virtual ~i_inferer();
  };

  typedef std::shared_ptr<i_inferer> infererPtr;

}


#endif //DALIA_TESTS_I_INFERENCER_H
