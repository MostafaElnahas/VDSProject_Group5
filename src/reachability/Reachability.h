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
    // bool isReachable(const std::vector<bool> &stateVector) ;
     void setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions) ;

vector<BDD_ID> initialstate;
vector<BDD_ID> SetofStates;
vector<BDD_ID> SetofnextStates;
vector<BDD_ID> TF;
BDD_ID Taw,Cs0,CRit,CR,imgc,imgnx;


     void setInitState(const vector<bool> &stateVector);
     BDD_ID computetransationrelation ();
     BDD_ID computecs0();
      BDD_ID imgcurrentstate ();
     BDD_ID imgnextstate ();
     BDD_ID computereachablestate ();
 };

}
#endif
