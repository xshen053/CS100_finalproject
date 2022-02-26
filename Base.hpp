#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <vector>

using namespace std;

class Base {
public:
    virtual void display() = 0;
    virtual void setName(string taskName) = 0;
    virtual string getName() = 0;
    virtual void setPriority(string taskPriority) = 0;
    virtual string getPriority() = 0;
    virtual void setDescription(string taskDescription) = 0;
    virtual string getDescription() = 0;
    virtual void setDuedate(string taskDueDate) = 0;
    virtual string getDuedate() = 0;
    virtual void setType(string taskType) = 0;
    virtual string getType() = 0;
    virtual string checkType() = 0;
    virtual vector<Base*> getSubLists() = 0;
    virtual void refreshSubLists(vector<Base*> ListofTasks) = 0;
protected:
    string title;
    string priority;
    string description;
    string dueDate;
    string classification;
    vector<Base> tasks;
    int hierarchy = 0; 
};


#endif 
