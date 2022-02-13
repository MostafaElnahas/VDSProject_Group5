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
initialstate.assign(stateSize,0);
for(int i=0; i <= stateSize; i++)
{

SetofStates.push_back(Manager::createVar(st));

}
//Define next states.
    for(int i=0; i <= stateSize; i++)
    {
        SetofnextStates.push_back(Manager::createVar(st));

    }
}

const vector<ClassProject::BDD_ID> & ClassProject::Reachability::getStates()
{
    return SetofStates;
}


//bool ClassProject::Reachability::isReachable(const std::vector<bool> &stateVector)
//{




//}

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
     initialstate[i]=stateVector[i];

    }
    }
ClassProject::BDD_ID ClassProject::Reachability:: computetransationrelation (){
BDD_ID Tawtemp=1;
    Taw=1;
    for(int i=0; i <=SetofStates.size(); i++)
    {
        Tawtemp=Manager::xnor2(SetofnextStates[i],TF[i]);
        Taw=Manager::and2(Taw,Tawtemp);

    }
    return Taw;
}
ClassProject::BDD_ID ClassProject::Reachability::computecs0()
{
    Cs0=1;
    BDD_ID Cs0temp;
    for(int i=0; i <=SetofStates.size(); i++)
    {
        Cs0temp= Manager::xnor2(SetofnextStates[i],initialstate[i]);
        Cs0=Manager::and2(Cs0,Cs0temp);
    }

    return Cs0;
}

ClassProject::BDD_ID ClassProject::Reachability::imgnextstate() {

vector<BDD_ID > temp;
temp[SetofStates.size()]=CR*Taw;
    for(int i=SetofStates.size(); i >=0; i--)
    {
        temp[i]=Manager::or2(coFactorTrue(temp[i],SetofStates[i]),Manager::coFactorFalse(temp[i],SetofStates[i]));

        imgc=temp[i];

    }


}

ClassProject::BDD_ID ClassProject::Reachability::imgcurrentstate()  {

    vector<BDD_ID > temp;
    BDD_ID x,y,xt=1;
    for(int i=0; i <=SetofStates.size(); i++)
    {
        x=Manager::Manager::xnor2(SetofStates[i],SetofnextStates[i]);
         xt=Manager::and2(x,xt);
    }
    y=Manager::and2(x,imgc);

    temp[SetofStates.size()]=Manager::and2(xt,y);
    for(int i=SetofStates.size(); i >=0; i--)
    {
        temp[i]=Manager::or2(coFactorTrue(temp[i],SetofnextStates[i]),Manager::coFactorFalse(temp[i],SetofnextStates[i]));

     imgnx=temp[i];
    }


}



ClassProject::BDD_ID ClassProject::Reachability::computereachablestate()

 {
    Reachability::computetransationrelation();
    Reachability::computecs0();
    CRit=Cs0;
    while (true) {
        CR = CRit;
        Reachability::SetofStates;
        Reachability::SetofnextStates;
        CRit = Manager::or2(CR, imgnx);
        if (CRit == CR)
            break;
    }
     return CR;

}






