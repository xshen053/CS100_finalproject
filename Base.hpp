#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include <vector>

using namespace std;

class Base {
public:
	virtual ~Base() = default;
	
    virtual void display() = 0;
    virtual void setName() = 0;
    virtual string getName() = 0;
    virtual void setPriority() = 0;
    virtual string getPriority() = 0;
    virtual void setDescription() = 0;
    virtual string getDescription() = 0;
    virtual void setDuedate() = 0;
    virtual string getDuedate() = 0;
    virtual void setType() = 0;
    virtual string getType() = 0;
    virtual string checkType() = 0;
    virtual vector<Base*> getSubLists() = 0;
    virtual void refreshSubLists(vector<Base*> ListofTasks) = 0;
    virtual void push(Base* t) = 0;
    virtual void setFinished() = 0;
    virtual void setUnfinished() = 0;
    virtual void hierarchyIncrease(int h) = 0;
	virtual int getHierarchy()  = 0;
	virtual void setParent(Base* p) = 0;
	virtual void deleteAllSublist() = 0;
	virtual void deleteOneSpecificSublist(string name) = 0;
	virtual Base* getParent() = 0;
protected:
    string title;
    string priority;
    string description;
    string dueDate;
    string classification;
    bool complete;
    int hierarchy = 0; 
    Base* parent;
};


#endif 
