//
// Created by Tomev on 15.04.2019.
// Classical inferer implementation.
//

#ifndef DALIA_CLASSICALINFERER_H
#define DALIA_CLASSICALINFERER_H

#include <unordered_map>
#include <vector>

#include "i_inferer.h"

class classicalInferer : public i_inferer {
  public:
    classicalInferer();
    void infer(std::vector<rulePtr> rules) = 0;
    std::unordered_map<std::string, std::string> getReport() = 0;
  private:
    std::unordered_map<std::string, std::vector<std::string>> inferenceTarget;

};


#endif //DALIA_CLASSICALINFERER_H
