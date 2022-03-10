#ifndef SUBLISTHPP
#define SUBLISTHPP

#include "gtest/gtest.h"

#include "../Base.hpp"
#include "../SubList.hpp"
#include <vector>
#include <iostream>


TEST(TaskTest0, Display){
  vector<Base>thesublist;

  Base task1 = new SubList("by diary", "Low", "by some diary", "03/02/2022", "group", thesublist);

  thesublist.push_back(task1);
  EXPECT_EQ(task1->getName(), "by diary");
  EXPECT_EQ(task1->getPriority(), "Low");
  EXPECT_EQ(task1->getDescription(), "by some diary");
  EXPECT_EQ(task1->getDuedate(), "03/10/2022");
  EXPECT_EQ(task1->getType(), "group");
}

TEST(TaskTest1, getName){
  Base* task1 = new Task("by Kannan", "", "", "", "");
  EXPECT_EQ(task1->getName(),"by Kannan");
}
  
TEST(TaskTest2, getPriority){
  Base* task1 = new Task("", "Low", "", "", "");
  EXPECT_EQ(task1->getPriority(), "Low");
}

TEST(TaskTest3, getDescriptionempty){
  Base* task1 = new Task("", "", "", "", "");
  EXPECT_EQ(task1->getDescription(), "");
}

TEST(TaskTest4, getDuedate){
  Base* task1 = new Task("", "", "", "2022", "");
  EXPECT_EQ(task1->getDuedate(), "2022");
}
    
TEST(TaskTest5, getTyperamdom){
  Base* task1 = new Task("", "", "", "", "endmysuffering");
  EXPECT_EQ(task1->getType(), "endmysuffering");
}

