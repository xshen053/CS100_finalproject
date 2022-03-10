#ifndef __SELECT_TEST_HPP__
#define __SELECT_TEST_HPP__

#include "gtest/gtest.h"

#include "../Base.hpp"
#include "../task.hpp"
#include <vector>
#include <iostream>

#include "../select.hpp"

TEST(OrderByDueDate,RandomA){

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

TEST(OrderByDueDate, RandB){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/03/2023", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2022", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2021", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByDueDate(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "bread");

}

TEST(OrderByDueDate, RandC){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByDueDate(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(OrderByDueDate, SameDate){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/03/2022", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2022", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByDueDate(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(OrderByPriority, HighMediumLow){

    vector<Base*> data;
    Base* a = new Task("Car", "high", "oil change", "01/03/2022", "personal");

    Base* b = new Task("Gym", "low", "Push day", "01/03/2022", "personal");

    Base* c = new Task("Hw", "medium", "cs programming", "01/06/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy = new Select_ByPriority(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "Car");

}

TEST(OrderByPriority, AllHigh){

    vector<Base*> data;
    Base* a = new Task("Car", "high", "oil change", "01/03/2022", "personal");

    Base* b = new Task("Gym", "high", "Push day", "01/03/2022", "personal");

    Base* c = new Task("Hw", "high", "cs programming", "01/06/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy = new Select_ByPriority(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "Car");

}

TEST(OrderByPriority,AllMedium){

    vector<Base*> data;
    Base* a = new Task("Car", "medium", "oil change", "01/03/2022", "personal");

    Base* b = new Task("Gym", "medium", "Push day", "01/03/2022", "personal");

    Base* c = new Task("Hw", "medium", "cs programming", "01/06/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy = new Select_ByPriority(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "Car");

}

TEST(OrderByPriority,AllLow){

    vector<Base*> data;
    Base* a = new Task("Car", "Low", "oil change", "01/03/2022", "personal");

    Base* b = new Task("Gym", "Low", "Push day", "01/03/2022", "personal");

    Base* c = new Task("Hw", "Low", "cs programming", "01/06/2022", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy = new Select_ByPriority(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "Car");

}

TEST(Classification, Personal){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByClassification(new Select_GetList(data),"personal");
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(Classification, AllPersonal){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "personal");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "personal");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByClassification(new Select_GetList(data),"personal");
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(Classification, Work){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByClassification(new Select_GetList(data),"work");
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "egg");

}

TEST(Classification, AllWork){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "work");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "work");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByClassification(new Select_GetList(data),"work");
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(Classification, Study){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "personal");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "work");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByClassification(new Select_GetList(data),"study");
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "bread");

}

TEST(Classification, AllStudy){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "study");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "study");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_ByClassification(new Select_GetList(data),"study");
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(Completion, NotFinished){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "study");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "study");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);
    Select* strategy;
    strategy = new Select_Unfinished(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(Completion, OneNotFinished){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "study");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "study");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);

    data.at(0)->setFinished();data.at(1)->setFinished();
    Select* strategy;
    strategy = new Select_Unfinished(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "bread");

}

TEST(Completion, AllFinished){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "study");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "study");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);

    data.at(0)->setFinished();
    data.at(1)->setFinished();
    data.at(2)->setFinished();
    Select* strategy;
    strategy = new Select_Finished(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    
    EXPECT_EQ(out.at(0)->getName(), "milk");

}

TEST(Completion, OneFinished){

    vector<Base*> data;
    Base* a = new Task("milk", "high", "whoe milk", "11/01/2023", "study");

    Base* b = new Task("egg", "medium", "chicken eggs", "11/03/2023", "study");

    Base* c = new Task("bread", "low", "brown bread", "11/03/2023", "study");

    data.push_back(a);

    data.push_back(b);

    data.push_back(c);

    data.at(1)->setFinished();

    Select* strategy;
    strategy = new Select_Finished(new Select_GetList(data));
    vector<Base*> out;
    out = strategy->getData();
    EXPECT_EQ(out.at(0)->getName(), "egg");

}

#endif
