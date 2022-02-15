//
// Created by ludwig on 22.11.16.
//

#include "Tests.h"
/*
TEST(Createvaribletest, label) {
    unsigned int j=2;
    ClassProject::Reachability * myReachabiliy= new ClassProject::Reachability(j);
    myReachabiliy->setInitState({0,0});
    //myReachabiliy-> setTransitionFunctions({0,1});

    vector<ClassProject::BDD_ID>i={2,3};

    EXPECT_EQ(i, myReachabiliy->getStates());





}

*/
struct ReachabilityTest : testing::Test {

    std::unique_ptr<ClassProject::ReachabilityInterface> fsm1 = std::make_unique<ClassProject::Reachability>(1);
    std::unique_ptr<ClassProject::ReachabilityInterface> fsm2 = std::make_unique<ClassProject::Reachability>(2);
    std::unique_ptr<ClassProject::ReachabilityInterface> fsm3 = std::make_unique<ClassProject::Reachability>(3);
    std::unique_ptr<ClassProject::ReachabilityInterface> fsm4 = std::make_unique<ClassProject::Reachability>(4);

    std::vector<ClassProject::BDD_ID> stateVars2 = fsm2->getStates();
    std::vector<ClassProject::BDD_ID> stateVars3 = fsm3->getStates();
    std::vector<ClassProject::BDD_ID> stateVars4 = fsm4->getStates();
    std::vector<ClassProject::BDD_ID> transitionFunctions;

};
TEST_F(ReachabilityTest, HowTo_Example) { /* NOLINT */

    auto s0 = stateVars2.at(0);
    auto s1 = stateVars2.at(1);

ClassProject::BDD_ID t,i,k,l;
    transitionFunctions.push_back(fsm2->neg(s0)); // s0' = not(s0)
    transitionFunctions.push_back(fsm2->neg(s1)); // s1' = not(s1)
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false,false});
   t= fsm2->computetransationrelation();
   k= fsm2->computecs0();
   i=fsm2->imgnextstate(t,k);
   l=fsm2->imgcurrentstate(i);


 ASSERT_TRUE(fsm2->isReachable({false, false}));


    }



int main(int argc, char *argv[]) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();


    }




//  ClassProject::Manager * myManager = new ClassProject::Manager();



