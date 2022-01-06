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
BDD_ID X;
BDD_ID top_var1;
BDD_ID top_var;

    if (isConstant(i) or (t == e) or ((t==1) & (e==0)))
    {
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
      if (topVar(i)==0 ||topVar(i)==1)
      top_var = min(topVar(t),topVar(e));
      else if(topVar(t)==0 && topVar(e)==1)
      {
          top_var = topVar(i);
      }
      else if(topVar(t)==0 ||topVar(t)==1)
      top_var = min(topVar(i),topVar(e));
      else if(topVar(e)==0 ||topVar(e)==1)
      top_var = min(topVar(i), topVar(t));
      else {
      top_var1 = min(topVar(t), topVar(e));
       top_var = min(top_var1, topVar(t));
           }

        BDD_ID ihigh= coFactorTrue(i,top_var);
        BDD_ID thigh= coFactorTrue(t,top_var);
        BDD_ID ehigh= coFactorTrue(e,top_var);
        BDD_ID high_successor = ite(ihigh,thigh,ehigh);
        BDD_ID low_successor = ite(coFactorFalse(i,top_var),coFactorFalse(t,top_var),coFactorFalse(e,top_var));

        if(high_successor==low_successor)
            return high_successor;
        else{


             X=findorAddVar(high_successor,low_successor,top_var);
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


        return  ite(topVar(f),T,F);


       }


    };
ClassProject::BDD_ID ClassProject::Manager::coFactorFalse(BDD_ID f, BDD_ID x) {
    BDD_ID high;
    BDD_ID low;
    BDD_ID T;
    BDD_ID F;
    if(isConstant(f) ||   isConstant(x) || topVar(f)>x)//Terminal case
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
        return  ite(topVar(f),T,F);


    }
};
ClassProject::BDD_ID ClassProject::Manager::neg(BDD_ID a) {
    return ite(a,0,1);
}

ClassProject::BDD_ID ClassProject::Manager:: and2(BDD_ID a, BDD_ID b) {
    return ite(a,b,0);
}
ClassProject::BDD_ID ClassProject::Manager::or2(BDD_ID a, BDD_ID b) {
    return ite(a,1,b);
}
ClassProject::BDD_ID ClassProject::Manager:: xor2(BDD_ID a, BDD_ID b) {
    return ite(a,neg(b),b);
}
ClassProject:: BDD_ID ClassProject::Manager:: nand2(BDD_ID a, BDD_ID b) {
    return neg(and2(a,b));
}
ClassProject::BDD_ID ClassProject::Manager:: nor2(BDD_ID a, BDD_ID b) {
    return neg(or2(a,b));
}
ClassProject::BDD_ID ClassProject::Manager:: xnor2(BDD_ID a, BDD_ID b) {
    return neg(xor2(a,b));
}

std::string ClassProject::Manager::getTopVarName(const BDD_ID &root) {
BDD_ID Y;
Y=topVar(root);
for (const auto &unique_table: unique_table) {
        if (unique_table.TopVar == Y)
            return unique_table.label;
    }

}

void ClassProject::Manager::findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root) {
   BDD_ID high_var;
   BDD_ID low_var;
    for (const auto &unique_table: unique_table) {
        if (unique_table.id == root) {

            high_var = unique_table.High;
            low_var = unique_table.Low;
            nodes_of_root.insert(high_var);
            nodes_of_root.insert(low_var);

        }
    }
        for (_Rb_tree_const_iterator<unsigned long long int> itr = nodes_of_root.begin(); itr != nodes_of_root.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    if (high_var>1 )
        findNodes(high_var, nodes_of_root);
    if (low_var>0)
        findNodes(low_var, nodes_of_root);

}

/*


















 size_t uniqueTableSize() {
     return unique_table.size();
 }*/
