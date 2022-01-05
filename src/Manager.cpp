#include "Manager.h"
#include <vector>
#include <iostream>
#include <experimental/iterator>
#include <algorithm>

//typedef size_t BDD_ID;
using namespace std;

/*
 * Terminal cases:
 *
 * t == 1 and e == 0
 * i == 1
 * i == 0
 * t == e
 */



ClassProject::Manager::Manager() {
    filltable("False", 0, 0, 0, 0);
    filltable("True", 1, 1, 1, 1);



}



ClassProject::BDD_ID ClassProject::Manager::createVar(const std::string &label) {
    BDD_ID new_ID = unique_table.size();
    filltable(label, new_ID, 1, 0, new_ID);
    return new_ID;
}
ClassProject::BDD_ID ClassProject::Manager::findorAddVar( BDD_ID high, BDD_ID low,BDD_ID top) {
    BDD_ID new_ID = unique_table.size();
    for (const auto &unique_table: unique_table) {
        if (unique_table.TopVar == top && unique_table.High==high && unique_table.Low==low)
            return unique_table.id;
    }

    filltable("new", new_ID, high, low, top);
    return new_ID;

    }







    /*
    for (const auto &unique_table: unique_table) {
        if (unique_table.label == label) {
            return unique_table.id;
        } else {
            filltable(label, sizeof(unique_table), 1, 0, sizeof(unique_table));//other cases?
            return sizeof(unique_table);
        }
    }
     */


/*const ClassProject::BDD_ID ClassProject::Manager::&True(){

    return 1;
    }
*/
    bool ClassProject::Manager::isConstant(BDD_ID f) {

        return (f==0) || (f==1);

    }

bool ClassProject::Manager::isVariable(BDD_ID x) {

    for (const auto &unique_table : unique_table){
        if (unique_table.id == x) {
           if ((unique_table.Low == 0) & (unique_table.High == 1))
                return true;
        }
    }
    return false;

}


ClassProject::BDD_ID ClassProject::Manager::topVar(BDD_ID f) {

    for (const auto &unique_table : unique_table){
        if (unique_table.id == f) {
            return unique_table.TopVar;
        }
    }
}
ClassProject::BDD_ID ClassProject::Manager::ite(BDD_ID i, BDD_ID t, BDD_ID e) {

        if (isConstant(i) or (t == e) or ((t==1) & (e==0))) {    //terminal cases   --- is complete?
        if(i == 1)
            return t;
        else if (i==0)
            return e;
        else if (t==e)
            return t;
        else
            return i;
    }
    else {
        BDD_ID top_var1 = min(topVar(i),topVar(t));
        BDD_ID top_var = min(top_var1,topVar(e));
        BDD_ID high_successor = ite(coFactorTrue(i,top_var),coFactorTrue(t,top_var),coFactorTrue(e,top_var));
        BDD_ID low_successor = ite(coFactorFalse(i,top_var),coFactorFalse(t,top_var),coFactorFalse(e,top_var));
        if(high_successor==low_successor)
            return high_successor;
        else{


            BDD_ID X=findorAddVar(high_successor,low_successor,top_var);
          return X;

            }
        }
    }









ClassProject::BDD_ID ClassProject::Manager::coFactorTrue(BDD_ID f, BDD_ID x) {
BDD_ID high;
BDD_ID low;
BDD_ID T;
BDD_ID F;
       if(isConstant(f)  || isConstant(x)  || topVar(f)>x)//Terminal case
           return f;
    for (const auto &unique_table: unique_table) {
        if (unique_table.id == f) {

             high = unique_table.High;
             low = unique_table.Low;
        }
    }

    if(topVar(f)==x) {

        return high;
    }
    else{
        T= coFactorTrue(high,x);
        F= coFactorTrue(low,x);
        return  ClassProject::Manager::ite(topVar(f),T,F);


       }



    };
ClassProject::BDD_ID ClassProject::Manager::coFactorFalse(BDD_ID f, BDD_ID x) {
    BDD_ID high;
    BDD_ID low;
    BDD_ID T;
    BDD_ID F;
    if(isConstant(f)  || isConstant(x)  || topVar(f)>x)//Terminal case
        return f;
    for (const auto &unique_table: unique_table) {
        if (unique_table.id == f) {

            high = unique_table.High;
            low = unique_table.Low;
        }
    }

    if(topVar(f)==x) {

        return low;
    }
    else{
        T= coFactorFalse(high,x);
        F= coFactorFalse(low,x);
        return  ClassProject::Manager::ite(topVar(f),T,F);


    }



};



/* const BDD_ID &False() {
     return 0;
 }



 bool isVariable(const BDD_ID x) {  //what does it mean? low is False and high is True?
     for (const auto &unique_table : unique_table){
         if (unique_table.id == x) {
             if ((unique_table.low == 0) & (unique_table.high == 1))
                 return True;
         }
     }
     return False;
 }




      BDD_ID neg(BDD_ID a) {
     return ite(a,0,1);
 }

 BDD_ID and2(BDD_ID a, BDD_ID b) {
     return ite(a,b,0);
 }

 BDD_ID or2(BDD_ID a, BDD_ID b) {
     return ite(a,1,b);
 }

 BDD_ID xor2(BDD_ID a, BDD_ID b) {
     return ite(a,neg(b),b);
 }

 BDD_ID nand2(BDD_ID a, BDD_ID b) {
     return neg(and2(a,b));
 }

 BDD_ID nor2(BDD_ID a, BDD_ID b) {
     return neg(or2(a,b));
 }

 BDD_ID xnor2(BDD_ID a, BDD_ID b) {
     return neg(xor2(a,b));
 }

 size_t uniqueTableSize() {
     return unique_table.size();
 }*/
