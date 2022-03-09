#ifndef __TASK_TEST_HPP
#define __TASK_TEST_HPP 

#include "gtest/gtest.h"

#include "../task.hpp"
#include <vector>
#include <iostream>

TEST(TaskTest, Display){
    Base* task1 = new Task("by diary", "High", "by some diary", "03/02/2022", "personal");
    EXPECT_EQ(task1->getName() "by diary");
    EXPECT_EQ(task1->getPriority(), "high");
    EXPECT_EQ(task1->getDescription(), "by some diary");
	EXPECT_EQ(task1->getDuedate(), "03/02/2022");
	EXPECT_EQ(task1->getType(), "personal");  
	
}

#endif
