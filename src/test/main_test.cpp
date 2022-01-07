//
// Created by ludwig on 22.11.16.
//


#include "Tests.h"

int main(int argc, char* argv[])
{
 ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();



}

TEST(Createvaribletest, label) {
    ClassProject::Manager * myManager = new ClassProject::Manager();

    EXPECT_EQ(2, myManager->createVar("a"));
    EXPECT_EQ(3, myManager->createVar("b"));
    EXPECT_EQ(4, myManager->createVar("c"));

}


TEST(constantfunction, constan) {
    ClassProject::Manager * myManager = new ClassProject::Manager();

    EXPECT_EQ(true, myManager->isConstant(0));
    EXPECT_EQ(true, myManager->isConstant(1));
    EXPECT_EQ(false, myManager->isConstant(2));
}
TEST(varfunc, var) {
    ClassProject::Manager * myManager = new ClassProject::Manager();
    EXPECT_EQ(2, myManager->createVar("a"));
    EXPECT_EQ(3, myManager->createVar("b"));
    EXPECT_EQ(4, myManager->createVar("c"));
    EXPECT_EQ(false, myManager->isVariable(0));
    EXPECT_EQ(true, myManager->isVariable(2));
    EXPECT_EQ(true, myManager->isVariable(3));
    EXPECT_EQ(true, myManager->isVariable(4));
}
TEST(Topvafunction, top) {
    ClassProject::Manager * myManager = new ClassProject::Manager();
    EXPECT_EQ(2, myManager->createVar("a"));
    EXPECT_EQ(2, myManager->topVar(2));
    EXPECT_EQ(3, myManager->createVar("b"));
    EXPECT_EQ(3, myManager->topVar(3));
}

TEST(ite, iteee) {
    ClassProject::Manager * myManager = new ClassProject::Manager();
    EXPECT_EQ(2, myManager->createVar("a"));
    EXPECT_EQ(2, myManager->topVar(2));
    EXPECT_EQ(3, myManager->createVar("b"));
    EXPECT_EQ(3, myManager->topVar(3));
    EXPECT_EQ(4, myManager->createVar("c"));
    EXPECT_EQ(4, myManager->topVar(4));
    EXPECT_EQ(5, myManager->createVar("d"));
    EXPECT_EQ(5, myManager->topVar(5));
    EXPECT_EQ(2, myManager->ite(1,2,3));// i==1, output=t
    EXPECT_EQ(3, myManager->ite(0,2,3));//i==0,output=e
    EXPECT_EQ(2, myManager->ite(2,2,2));//t==e, output=t
    EXPECT_EQ(1, myManager->coFactorTrue(1,2));
    EXPECT_EQ(3, myManager->coFactorTrue(3,2));
    EXPECT_EQ(3, myManager->coFactorTrue(3,2));
    EXPECT_EQ(0, myManager->coFactorFalse(2,2));
    EXPECT_EQ(1, myManager->coFactorFalse(1,2));
    EXPECT_EQ(0, myManager->coFactorFalse(2,2));
    //EXPECT_EQ(6, myManager->ite(2,1,3));
    EXPECT_EQ(6, myManager->or2(2,3));
    EXPECT_EQ(7, myManager->and2(4,5));
    EXPECT_EQ(9, myManager->and2(6,7));
    EXPECT_EQ("a", myManager->getTopVarName(9));
    set<ClassProject::BDD_ID> val,vars;
    set<ClassProject::BDD_ID> i,j;
    i={9,8,7,5,1,0};
    j={2,3,4,5,1,0};
myManager->findNodes(9,val);

    EXPECT_EQ(i, (val));
    myManager->findVars(9,vars);
    EXPECT_EQ(j, (vars));
    EXPECT_EQ(10, myManager->uniqueTableSize());
    EXPECT_EQ(1, myManager->True());
    EXPECT_EQ(0, myManager->False());

}


TEST(logicgates, logic_gates) {
    ClassProject::Manager * myManager = new ClassProject::Manager();
    EXPECT_EQ(2, myManager->createVar("a"));
    EXPECT_EQ(2, myManager->topVar(2));
    EXPECT_EQ(3, myManager->createVar("b"));
    EXPECT_EQ(3, myManager->topVar(3));
    EXPECT_EQ(4, myManager->createVar("c"));
    EXPECT_EQ(4, myManager->topVar(4));
    EXPECT_EQ(5, myManager->createVar("d"));
    EXPECT_EQ(5, myManager->topVar(5));
    EXPECT_EQ(1, myManager->or2(1,0));
    EXPECT_EQ(0, myManager->or2(0,0));
    EXPECT_EQ(1, myManager->or2(2,1));
    EXPECT_EQ(1, myManager->and2(1,0));
    EXPECT_EQ(0, myManager->and2(0,0));
    EXPECT_EQ(1, myManager->and2(2,1));
}
