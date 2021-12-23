// A minimalistic BDD library, following Wolfgang Kunz lecture slides
//
// Created by Markus Wedler 2014

#ifndef VDSPROJECT_MANAGER_H
#define VDSPROJECT_MANAGER_H

#include "ManagerInterface.h"
#include <vector>
#include <iostream>
using namespace std;
namespace ClassProject {
public:

    BDD_ID  createVar(const std::string &a);
    BDD_ID  createVar(const std::string &b);
    BDD_ID  createVar(const std::string &c);
    BDD_ID  createVar(const std::string &d);

    void createtable() {

        vector<vector<int> > table
                {
                        {0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1},
                        {0, 2, 1, 0, 2},
                        {0, 3, 1, 0, 3},
                        {0, 4, 1, 0, 4},
                        {0, 5, 1, 0, 5},
                        {0, 6, 1, 3, 2},
                        {0, 7, 5, 0, 4},
                        {0, 8, 7, 0, 3},
                        {0, 9, 7, 8, 2}

                };

        int i, j;
        for (int i = 0; i < table.size(); i++) {
            for (int j = 0; j < table[i].size(); j++) {
                cout << table[i][j] << " ";
            }
            cout << endl;


        }
    }


};



#endif
