//
// Created by ludwig on 22.11.16.
//

#include "Tests.h"

TEST(Createvaribletest, label) {
    unsigned int j=2;
    ClassProject::Reachability * myReachabiliy= new ClassProject::Reachability(j);
    myReachabiliy->setInitState({0,0});
    vector<ClassProject::BDD_ID>i={2,3};
    vector< bool > k = {false,false};
    EXPECT_EQ(i, myReachabiliy->getStates());
    myReachabiliy->neg(2);
    myReachabiliy->neg(3);
    myReachabiliy->setTransitionFunctions({,1});





}



int main(int argc, char *argv[]) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();


    }




//  ClassProject::Manager * myManager = new ClassProject::Manager();



