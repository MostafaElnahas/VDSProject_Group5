#include "Manager.h"
#include <vector>
#include <iostream>
#include <experimental/iterator>
#include <algorithm>
typedef size_t BDD_ID;
using namespace std;



class myclass {
    public:
        struct rows{
            string &label;
            int id,High,Low,TopVar;
        };
        vector<rows> unique_table;


    void filltable  (string Label, int idd,int high,int low,int topvar ) {
        unique_table.push_back({Label,idd,high,low,topvar});
    }

    myclass(){
        filltable("False",0,0,0,0);
        filltable("True",1,1,1,1);
    }

    BDD_ID createVar(const std::string &label) {
        for (const auto &unique_table: unique_table) {
            if (unique_table.label == label) {
                return unique_table.id;
            } else {
                filltable(label, sizeof (unique_table), 1, 0, sizeof (unique_table));//other cases?
                return sizeof (unique_table);
            }
        }
    }
/*
    const BDD_ID &True() {
        return 1;
    }

    const BDD_ID &False() {
        return 0;
    }


    bool isConstant(const BDD_ID f) {  //what is leaf node? 0 and 1?
        return (f==0) || (f==1);
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


    BDD_ID topVar(const BDD_ID f){

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
    };


int main(){
    ClassProject::createVar("abc")  ;

};
