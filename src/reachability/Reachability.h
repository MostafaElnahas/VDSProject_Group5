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
     vector<BDD_ID> initialstate;
     vector<BDD_ID> SetofStates;
     vector<BDD_ID> SetofnextStates;
     vector<BDD_ID> TF;
 public:

    Reachability(unsigned int stateSize){
if (stateSize==0)
    throw std::runtime_error("error");

         vector<BDD_ID> S;
         string st;
         if (stateSize==0)
             throw ;
//Define States
        TF.assign(stateSize,0);

         initialstate.assign(stateSize,0);

         for(int i=0; i < stateSize; i++)
         {

             SetofStates.push_back(Manager::createVar(st));

         }
//Define next states.
         for(int i=0; i < stateSize; i++)
         {
             SetofnextStates.push_back(Manager::createVar(st));

         }
     }












     const std::vector<BDD_ID> &getStates() const ;
   bool isReachable(const std::vector<bool> &stateVector) ;
     void setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions) ;

     void setInitState(const vector<bool> &stateVector);
BDD_ID computetransationrelation ();
BDD_ID computecs0();
BDD_ID imgcurrentstate (BDD_ID e);
BDD_ID imgnextstate (BDD_ID e, BDD_ID t);
BDD_ID computereachablestate ();

 };
}

#endif
