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
     void findnextstates();
     const std::vector<BDD_ID> &getStates() ;
     bool isReachable(const std::vector<bool> &stateVector) ;
     void setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions) ;

vector<bool> initialstate;
vector<BDD_ID> SetofStates;
vector<BDD_ID> SetofnextStates;

vector<BDD_ID> TF;


     void setInitState(const vector<bool> &stateVector);
     void computereachablestate (const std::vector<BDD_ID> &transitionFunctions,const vector<bool> &stateVector);
 };

}
#endif
