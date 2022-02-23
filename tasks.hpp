#ifndef TASKS_HPP
#define TASKS_HPP

#include <string>
#include <vector>


using namespace std;

class task{
    private:
    	string taskName;
    public:
    	void setName(string);
    	string getName();
};

class taskList{
    public:
    	void writeTask(); // output list of tasks
    	void addTask(string t);
	int listSize();
    
    private:
    	vector<task*>tList;
};

#endif
