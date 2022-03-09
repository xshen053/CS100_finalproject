#ifndef __TASKTEST_HPP
#define __TASKTEST_HPP 

#include "gtest/gtest.h"

#include "../Base.hpp"
#include "../task.hpp"
#include <vector>
#include <iostream>


TEST(TaskTest1, Display){
    Base* task1 = new Task("by diary", "High", "by some diary", "03/02/2022", "personal");
    EXPECT_EQ(task1->getName(), "by diary");
    EXPECT_EQ(task1->getPriority(), "High");
    EXPECT_EQ(task1->getDescription(), "by some diary");
    EXPECT_EQ(task1->getDuedate(), "03/02/2022");
    EXPECT_EQ(task1->getType(), "personal");  
	
}
TEST(TaskTest2, getName){
    Base* task1 = new Task("by Han", "", "", "", "");
    EXPECT_EQ(task1->getName(),"by Han");
}
TEST(TaskTest3, getPriorityOtherempty){
    Base* task1 = new Task("", "High", "", "", "");
    EXPECT_EQ(task1->getPriority(), "High");
}


TEST(TaskTest4, getDescriptionempty){
    Base* task1 = new Task("", "", "", "", "");
    EXPECT_EQ(task1->getDescription(), "");
}

TEST(TaskTest5, getDuedate){
    Base* task1 = new Task("", "", "", "2022", "");
    EXPECT_EQ(task1->getDuedate(), "2022");
}
TEST(TaskTest6, getTyperamdom){
    Base* task1 = new Task("", "", "", "", "hahaha");
    EXPECT_EQ(task1->getType(), "hahaha");
}

#endif
