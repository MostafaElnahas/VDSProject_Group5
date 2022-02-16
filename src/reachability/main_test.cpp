//
// Created by ludwig on 22.11.16.
//

#include "Tests.h"

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


TEST_F(ReachabilityTest, SetTransitionFunction) { /* NOLINT */

    transitionFunctions.push_back(stateVars2.at(0)); // s0' = s0
    transitionFunctions.push_back(fsm2->neg(stateVars2.at(1))); // s1' = neg(s1)
    fsm2->setTransitionFunctions(transitionFunctions);

    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_TRUE(fsm2->isReachable({false, true}));
    ASSERT_FALSE(fsm2->isReachable({true, false}));
    ASSERT_FALSE(fsm2->isReachable({true, true}));
}

TEST_F(ReachabilityTest, SetTransitionFunctionsException) { /* NOLINT */

    // Mismatching size
    ASSERT_THROW(fsm2->setTransitionFunctions({fsm2->False()}), std::runtime_error);
    ASSERT_THROW(fsm2->setTransitionFunctions({fsm2->False(), fsm2->False(), fsm2->False()}), std::runtime_error);

    // Invalid BDD_ID
    ASSERT_THROW(fsm2->setTransitionFunctions({fsm2->False(), fsm2->uniqueTableSize() + 1337}), std::runtime_error);
}

TEST_F(ReachabilityTest, SetInitState) { /* NOLINT */
    ASSERT_NO_THROW(fsm1->setInitState({true}));
    ASSERT_NO_THROW(fsm2->setInitState({true, false}));
    ASSERT_NO_THROW(fsm3->setInitState({true, false, false}));

    ASSERT_FALSE(fsm1->isReachable({false}));
    ASSERT_TRUE(fsm1->isReachable({true}));

    ASSERT_FALSE(fsm2->isReachable({false, false}));
    ASSERT_FALSE(fsm2->isReachable({false, true}));
    ASSERT_TRUE(fsm2->isReachable({true, false}));
    ASSERT_FALSE(fsm2->isReachable({true, true}));

    ASSERT_FALSE(fsm3->isReachable({false, false, false}));
    ASSERT_FALSE(fsm3->isReachable({false, false, true}));
    ASSERT_FALSE(fsm3->isReachable({false, true, false}));
    ASSERT_FALSE(fsm3->isReachable({false, true, true}));
    ASSERT_TRUE(fsm3->isReachable({true, false, false}));
    ASSERT_FALSE(fsm3->isReachable({true, false, true}));
    ASSERT_FALSE(fsm3->isReachable({true, true, false}));
    ASSERT_FALSE(fsm3->isReachable({true, true, true}));
}

TEST_F(ReachabilityTest, HowTo_Example) { /* NOLINT */

    auto s0 = stateVars2.at(0);
    auto s1 = stateVars2.at(1);

    transitionFunctions.push_back(fsm2->neg(s0)); // s0' = not(s0)
    transitionFunctions.push_back(fsm2->neg(s1)); // s1' = not(s1)
    fsm2->setTransitionFunctions(transitionFunctions);

    fsm2->setInitState({false, false});


    ASSERT_TRUE(fsm2->isReachable({false, false}));
    ASSERT_FALSE(fsm2->isReachable({false, true}));
    ASSERT_FALSE(fsm2->isReachable({true, false}));
    ASSERT_TRUE(fsm2->isReachable({true, true}));


}

TEST_F(ReachabilityTest, ThreeStateBitExample1) { /* NOLINT */

    auto s0 = stateVars3.at(0);
    auto s1 = stateVars3.at(1);
    auto s2 = stateVars3.at(2);

    transitionFunctions.push_back(fsm3->neg(s0)); //s0' = not(s0)
    transitionFunctions.push_back(s1); //s1' = s1
    transitionFunctions.push_back(fsm3->or2(s2, s0)); //s2' = s2 or s0
    fsm3->setTransitionFunctions(transitionFunctions);

    fsm3->setInitState({false, false, false});

    ASSERT_TRUE(fsm3->isReachable({false, false, false}));
    ASSERT_TRUE(fsm3->isReachable({false, false, true}));
    ASSERT_FALSE(fsm3->isReachable({false, true, false}));
    ASSERT_FALSE(fsm3->isReachable({false, true, true}));
    ASSERT_TRUE(fsm3->isReachable({true, false, false}));
    ASSERT_TRUE(fsm3->isReachable({true, false, true}));
    ASSERT_FALSE(fsm3->isReachable({true, true, false}));
    ASSERT_FALSE(fsm3->isReachable({true, true, true}));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();


}




//  ClassProject::Manager * myManager = new ClassProject::Manager();



