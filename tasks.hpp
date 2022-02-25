#ifndef TASKS_HPP
#define TASKS_HPP

#include <string>
#include <vector>


using namespace std;

class taskBase{
	
	public:
		virtual void display() = 0;
		
};	

class task: public taskBase{
    private:
    	string taskName;
    	string taskC; // category
    	int taskP; // priority
    	
    	
    public:
    	task(string name, string category, int priority);
    	void setName(string);
    	string getName();
    	void display();
};

class taskList: public taskBase{
	private:
    	vector<taskBase*>tList;
    	string lName;
    	string listDesc;
    	
    public:
    	taskList(string listName, string listD); // list name and description.
    	void display(); // output list of tasks
    	void addTask(taskBase* t);
    	int listSize();
    
};

#endif
