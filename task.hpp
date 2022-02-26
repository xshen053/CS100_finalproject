#ifndef __TASK_HPP
#define __TASK_HPP

#include "Base.hpp" 

#include <string>
#include <iostream>


class Base;

class Task: public Base{
	
	
public:

    Task(string taskTitle, string taskPriority, string taskDescription, string taskDueDate, string taskType){
        title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
        classification = taskType;
	}
	
	void display(){
		cout << "Task Name:" << title << endl;
		cout << "Task Priority:" << priority << endl;
		cout << "Task Description:" << description << endl;
		cout << "Task Duedate:" << dueDate << endl;
		cout << "Task type:" << classification << endl;
	}
	
	void setName(string taskName){
		title = taskName;
	}
	
	string getName(){
		return title;
	}
	
	void setPriority(string taskPriority){
	    priority = taskPriority;
	}
	
	string getPriority(){
		return priority;
	}
	
	void setDescription(string taskDescription){
		description = taskDescription;
	}
	
	string getDescription(){
		return description;
	}
	
	void setDuedate(string taskDueDate){
		dueDate = taskDueDate;
	}
	
	string getDuedate(){
		return dueDate;
	}
	
	void setType(string taskType){
		classification = taskType;
	}
	
	string getType(){
		return classification;
	}
	
	string checkType(){
		return "Single task";
	}
	
	virtual vector<Base*> getSubLists(){}
	virtual void refreshSubLists(vector<Base*> ListofTasks){}
	
};

#endif 
