#ifndef SUBLISTHPP
#define SUBLISTHPP

#include "gtest/gtest.h"

#include "../Base.hpp"
#include "../SubList.hpp"
#include <vector>
#include <iostream>


TEST(TaskTest111111111, Display){
    vector<Base>thesublist;

    Base task1 = new SubList("by diary", "High", "by some diary", "03/02/2022", "personal",thesublist);

    thesublist.push_back(task1);
    EXPECT_EQ(task1->getName(), "by diary");
    EXPECT_EQ(task1->getPriority(), "High");
    EXPECT_EQ(task1->getDescription(), "by some diary");
    EXPECT_EQ(task1->getDuedate(), "03/02/2022");
    EXPECT_EQ(task1->getType(), "personal");

}


#endif
~
