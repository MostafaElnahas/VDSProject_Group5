//
// Created by ludwig on 27.11.18
// Refactored by deutschmann on 19.04.21
//

#ifndef VDSPROJECT_REACHABILITY_H
#define VDSPROJECT_REACHABILITY_H
#include <vector>
#include "ReachabilityInterface.h"

namespace ClassProject {

 class Reachability : public ReachabilityInterface {
     Reachability(unsigned int stateSize);
     const std::vector<BDD_ID> &getStates() ;
     bool isReachable(const std::vector<bool> &stateVector) ;
     void setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions) ;
     void setInitState(const std::vector<bool> &stateVector) ;
vector<BDD_ID> SetofStates;
 };

}
#endif
