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
    EXPECT_EQ(6, myManager->ite(2,1,3));         //t==e, output=t    NOT WORKING
}

