#include "Manager.h"
#include <vector>
#include <iostream>
#include <experimental/iterator>

using namespace std;

namespace ClassProject{

struct rows{
       char label;
       int IDD,High,Low,TopVar;
           };
    vector<rows> table;
void filltable  (char Label, int idd,int high,int low,int topvar ) {



table.push_back({Label,idd,high,low,topvar});


}
void print ( )
{


    for (const auto &table : table) {
        cout << "First Name: " << table.label << endl
             << "Last Name: " << table.IDD << endl
             << "Roll Number: " << table.High << endl;
    }
}



};

int main(){
    ClassProject::filltable('a', 0 , 1, 0 , 0);
    ClassProject::print();
    cout<<"hello word"<<endl;

};







