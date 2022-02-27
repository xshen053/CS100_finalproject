#ifndef __TASK_HPP
#define __TASK_HPP

#include "Base.hpp" 

#include <string>
#include <iostream>


class Base;

class Task: public Base{
	
	
public:
//    ~Task();
    
    
    Task(string taskTitle, string taskPriority, string taskDescription, string taskDueDate, string taskType){
        title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
        classification = taskType;
        complete = false;
        hierarchy = 0; 
	}
	
	void display(){
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Task Name:" << title << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Task Priority:" << priority << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Task Description:" << description << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}		
		cout << "Task Duedate:" << dueDate << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}		
		cout << "Task type:" << classification << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Is Task complete: ";
		if(complete == false){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
	
	void setName(){
		cout << "Type in new task name followed by ENTER:" << endl;
		string taskName;
		getline(cin.ignore(), taskName);
		title = taskName;
	}
	
	string getName(){
		return title;
	}
	
	void setPriority(){
		cout << "Type in the new task priority (high, medium, or low) followed by ENTER" << endl;
		string taskPriority;
		cin >> taskPriority;
	    priority = taskPriority;
	}
	
	string getPriority(){
		return priority;
	}
	
	void setDescription(){
		cout << "Type in the new task description followed by ENTER:" << endl;
		string taskDescription;
		getline(cin.ignore(), taskDescription);
		description = taskDescription;
	}
	
	string getDescription(){
		return description;
	}
	
	void setDuedate(){
		cout << "Type in the new task duedate (dd/mm/yyyy) followed by ENTER:" << endl;
		string taskDueDate;
		cin >> taskDueDate;
		dueDate = taskDueDate;
	}
	
	string getDuedate(){
		return dueDate;
	}
	
	void setType(){
		cout << "Type in the new task classification (personal, study, or work) followed by ENTER:" << endl;
		string taskType;
		cin >> taskType;
		classification = taskType;
	}
	
	string getType(){
		return classification;
	}
	
	string checkType(){
		return "Single task";
	}
	
	void setFinished(){
		complete = true;
	}
	
	void setUnfinished(){
		complete = false;
	}
	
	void hierarchyIncrease(int h){
		hierarchy = h + 1; 
	} 
	
	int getHierarchy(){
		return hierarchy;
	}
	void setParent(Base* p){
		parent = p;
	}
	
	Base* getParent(){
		return parent;
	}
	
	bool isComplete(){
		return complete;
	}
	//virtual vector<Base*> getSubLists(){}
	virtual void refreshSubLists(vector<Base*> ListofTasks){}
	virtual void push(Base* t){}
	virtual void deleteAllSublist(){}
	virtual void deleteOneSpecificSublist(string name){}
};

#endif 
