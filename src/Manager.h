// A minimalistic BDD library, following Wolfgang Kunz lecture slides
//
// Created by Markus Wedler 2014

#ifndef VDSPROJECT_MANAGER_H
#define VDSPROJECT_MANAGER_H
#define USE_HASH_TABLE

#include "ManagerInterface.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <boost/functional/hash.hpp>

using namespace std;
namespace ClassProject {

    class Manager : public ClassProject::ManagerInterface {
    public:
        struct rows {
            string label;
            BDD_ID id, High, Low, TopVar;
        };

        struct Key {
            BDD_ID i, t, e; //ite(i,t,e)

            bool operator==(const Key &other) const {
                return (i == other.i
                        && t == other.t
                        && e == other.e);
            }
        };

        struct KeyHasher {
            std::size_t operator()(const Key &k) const {
                using boost::hash_value;
                using boost::hash_combine;

                // Start with a hash value of 0    .
                std::size_t seed = 0;

                // Modify 'seed' by XORing and bit-shifting in
                // one member of 'Key' after the other:
                hash_combine(seed, hash_value(k.i));
                hash_combine(seed, hash_value(k.t));
                hash_combine(seed, hash_value(k.e));

                // Return the result.
                return seed;
            }
        };


    public :
        void filltable(string Label, BDD_ID idd, BDD_ID high, BDD_ID low, BDD_ID topvar) {
            unique_table.push_back({Label, idd, high, low, topvar});
#ifdef USE_HASH_TABLE
            unique_table_hash.insert({{high, low, topvar}, idd});
#endif
        }

        Manager();

        BDD_ID createVar(const std::string &label);

        const BDD_ID &True();

        const BDD_ID &False();

        bool isConstant(BDD_ID f);

        bool isVariable(BDD_ID x);

        BDD_ID topVar(BDD_ID f);

        BDD_ID findorAddVar(BDD_ID high, BDD_ID low, BDD_ID top);

        BDD_ID ite(BDD_ID i, BDD_ID t, BDD_ID e);

        BDD_ID coFactorTrue(BDD_ID f, BDD_ID x);

        BDD_ID coFactorFalse(BDD_ID f, BDD_ID x);

        BDD_ID coFactorTrue(BDD_ID f);

        BDD_ID coFactorFalse(BDD_ID f);

        BDD_ID neg(BDD_ID a);

        BDD_ID and2(BDD_ID a, BDD_ID b);

        BDD_ID or2(BDD_ID a, BDD_ID b);

        BDD_ID xor2(BDD_ID a, BDD_ID b);

        BDD_ID nand2(BDD_ID a, BDD_ID b);

        BDD_ID nor2(BDD_ID a, BDD_ID b);

        BDD_ID xnor2(BDD_ID a, BDD_ID b);

        std::string getTopVarName(const BDD_ID &root);

        void findNodes(const BDD_ID &root, std::set<BDD_ID> &nodes_of_root);

        void findVars(const BDD_ID &root, std::set<BDD_ID> &vars_of_root);

        size_t uniqueTableSize();

    private:
        vector<rows> unique_table;
#ifdef USE_HASH_TABLE
        unordered_map<Key, BDD_ID, KeyHasher> unique_table_hash;
        unordered_map<Key, BDD_ID, KeyHasher> computed_table;
#endif

    };


}


#endif
