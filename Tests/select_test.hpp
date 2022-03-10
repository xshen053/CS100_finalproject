#ifndef __SELECT_TEST_HPP__
#define __SELECT_TEST_HPP__

#include "gtest/gtest.h"

#include "../Base.hpp"
#include "../task.hpp"
#include <vector>
#include <iostream>

#include "../select.hpp"

TEST(SelectTest, Orderbyduedate){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/03/2022", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "09/03/2022", "work");

    Base* c = new Task("bread", "low", "brown bread", "10/03/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByDueDate(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "egg");

}

TEST(SelectTest, Orderbypriority){
    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/03/2022", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "09/03/2022", "work");

    Base* c = new Task("bread", "low", "brown bread", "10/03/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByPriority(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");
    
}

TEST(SelectTest, OrderbyPriorityAndDuedate){
    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/03/2022", "personal");

    Base* b = new Task("egg", "high", "chicken eggs", "09/03/2022", "work");

    Base* c = new Task("bread", "low", "brown bread", "10/03/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByDueDate(new Select_ByPriority(new Select_GetList(data)));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "egg");

}



#endif
