//
// Created by ludwig on 27.11.18
// Refactored by deutschmann on 19.04.21
//

#include "Reachability.h"

const vector<ClassProject::BDD_ID> & ClassProject::Reachability::getStates() const
{

    return SetofStates;
}


bool ClassProject::Reachability::isReachable(const std::vector<bool> &stateVector)
{
    BDD_ID CRtemp;
CRtemp=computereachablestate();
for(int i=0;i<=stateVector.size();i++){
    if(stateVector[i]==true)
        CRtemp= coFactorTrue(CRtemp,SetofStates[i]);
    else
        CRtemp= Manager::coFactorFalse(CRtemp,SetofStates[i]);

    return (CRtemp==True());




    }
}


void ClassProject::Reachability::setTransitionFunctions(const std::vector<BDD_ID> &transitionFunctions) {

if(transitionFunctions.size()!=SetofStates.size())
    throw;
    for(int i=0; i <transitionFunctions.size(); i++)
    {
        TF[i]=transitionFunctions[i];
    cout<<TF[i]<<endl;
    }


}
void ClassProject::Reachability::setInitState(const std::vector<bool> &stateVector) {

    for(int i=0; i < SetofStates.size(); i++)
    {
        if (stateVector[i]==false)
            initialstate[i]=0;
        else
            initialstate[i]=1;
        cout<<initialstate[i]<<endl;

    }
    }





ClassProject::BDD_ID ClassProject::Reachability:: computetransationrelation (){
BDD_ID Tawtemp=1,taw=1;

    for(int i=0; i <SetofStates.size(); i++)
    {
        Tawtemp=Manager::xnor2(SetofnextStates[i],TF[i]);
        taw=Manager::and2(taw,Tawtemp);

    }
    return taw;
}


ClassProject::BDD_ID ClassProject::Reachability::computecs0()
{
    ;
    BDD_ID Cs0temp,cs01=1;
    for(int i=0; i <SetofStates.size(); i++)
    {
        Cs0temp= Manager::xnor2(SetofnextStates[i],initialstate[i]);
        cs01=Manager::and2(cs01,Cs0temp);
    }

    return cs01;
}



ClassProject::BDD_ID ClassProject::Reachability::imgnextstate(BDD_ID e, BDD_ID t) {
BDD_ID imgnxtemp,temp;
temp=e*t;
    for(int i=SetofStates.size()-1; i >=0; i--)
    {
        temp=Manager::or2(coFactorTrue(temp,SetofStates[i]),Manager::coFactorFalse(temp,SetofStates[i]));

        imgnxtemp=temp;

    }

return imgnxtemp;
}





ClassProject::BDD_ID ClassProject::Reachability::imgcurrentstate(BDD_ID e)  {
    BDD_ID x,y,xt=1,imgctemp,temp;
    for(int i=0; i <SetofStates.size()-1; i++)
    {
        x=Manager::Manager::xnor2(SetofStates[i],SetofnextStates[i]);
             xt=Manager::and2(x,xt);
    }
    y=Manager::and2(x,e);

    temp=Manager::and2(xt,y);
    for(int i=SetofStates.size(); i >=0; i--)
    {
        temp=Manager::or2(Manager::coFactorTrue(temp,SetofnextStates[i]),Manager::coFactorFalse(temp,SetofnextStates[i]));

     imgctemp=temp;
    }

return imgctemp;
}






ClassProject::BDD_ID ClassProject::Reachability::computereachablestate()

 {     BDD_ID Taw,Cs0,CRit,CR,imgc,imgnx;

     Taw=Reachability::computetransationrelation();
    Cs0=Reachability::computecs0();
    CRit=Cs0;
    while (true) {
        CR = CRit;
       imgc= Reachability::imgnextstate(Taw,Cs0);
        imgnx=Reachability::imgcurrentstate(imgc);
        CRit = Manager::or2(CR, imgnx);
        if (CRit == CR)
            break;
    }
     return CR;
 }



