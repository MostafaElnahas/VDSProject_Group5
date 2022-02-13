//
// Created by ludwig on 27.11.18
// Refactored by deutschmann on 19.04.21
//

#include "Reachability.h"

ClassProject::Reachability::Reachability(unsigned int stateSize) : ReachabilityInterface(stateSize){
     vector<BDD_ID> S;
     string st;
if (stateSize==0)
    throw ;
//Define States
for(int i=0; i <= stateSize; i++)
{

SetofStates.push_back(Manager::createVar(st));

}
//Define next states.
    for(int i=0; i <= stateSize; i++)
    {
        SetofStates.push_back(Manager::createVar(st));

    }
}

const vector<ClassProject::BDD_ID> & ClassProject::Reachability::getStates()
{
    return SetofStates;
}


bool ClassProject::Reachability::isReachable(const std::vector<bool> &stateVector)
{




}

void ClassProject::Reachability::setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions) {

if(transitionFunctions.size()!=SetofStates.size())
    throw;
    for(int i=0; i <= transitionFunctions.size(); i++)
    {
        TF[i]=transitionFunctions[i];
    }


}
void ClassProject::Reachability::setInitState(const std::vector<bool> &stateVector) {

    for(int i=0; i <= SetofStates.size(); i++)
    {
     SetofStates[i]=stateVector[i];

    }
    }

 void ClassProject::Reachability::computereachablestate(const std::vector<BDD_ID> &transitionFunctions,const std::vector<bool> &stateVector)

 {




}






