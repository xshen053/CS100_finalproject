#ifndef _SUBLIST_HPP_
#define _SUBLIST_HPP_

#include "gtest/gtest.h"

#include "../Base.hpp"
#include "../SubList.hpp"
#include <vector>
#include <iostream>


TEST(SubTest1, Display){
    vector<Base*>thesublist;

    Base* task1 = new SubList("by diary", "High", "by some diary", "03/02/2022", "personal",thesublist);

    thesublist.push_back(task1);
    EXPECT_EQ(task1->getName(), "by diary");
    EXPECT_EQ(task1->getPriority(), "High");
    EXPECT_EQ(task1->getDescription(), "by some diary");
    EXPECT_EQ(task1->getDuedate(), "03/02/2022");
    EXPECT_EQ(task1->getType(), "personal");

}

TEST(SubTest2, onlyname){
    vector<Base*>thesublist;

    Base* task1 = new SubList("Han", "", "", "", "",thesublist);

    thesublist.push_back(task1);
    EXPECT_EQ(task1->getName(), "Han");
}

TEST(SubTest3, nothing){
    vector<Base*>thesublist;

    Base* task1 = new SubList("", "", "", "", "",thesublist);

    thesublist.push_back(task1);
EXPECT_EQ(task1->getPriority(), "");
}

TEST(SubTest4, getDescription){
    vector<Base*>thesublist;

    Base* task1 = new SubList("", "", "123456789", "", "",thesublist);

    thesublist.push_back(task1);
    EXPECT_EQ(task1->getDescription(), "123456789");
}
TEST(SubTest5,baddate){
    vector<Base*>thesublist;

    Base* task1 = new SubList("", "", "", "00000000", "",thesublist);

    thesublist.push_back(task1);
    EXPECT_EQ(task1->getDuedate(), "00000000");
}
TEST(SubTest6, gettype){
    vector<Base*>thesublist;

    Base* task1 = new SubList("", "", "", "", "study",thesublist);

    thesublist.push_back(task1);
    EXPECT_EQ(task1->getType(), "study");
}


#endif

