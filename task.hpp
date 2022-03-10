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
		string taskName = "";
		cin.ignore();
		while(taskName == ""){
			getline(cin,taskName);
			if(taskName == ""){
				cout << "ERROR: NO NAME DETECTED. PLEASE ENTER A NAME FOR TASK" << endl;
			}
		}
		title = taskName;
	}
	
	string getName(){
		return title;
	}
	
	void setPriority(){
		cout << "Type in the new task priority (high, medium, or low) followed by ENTER" << endl;
		string taskPriority;
		cin >> taskPriority;
		while(taskPriority != "high" && taskPriority != "medium" && taskPriority != "low"){
			cout << "WARNING: INVALID PRIORITY. PLEASE ENTER TASK PRIORITY:" << endl;
			cin >> taskPriority;
		}
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
		string d;
		string m;
		string y;
		cout << "Type in a day (two digit number): ";
		cin >> d;
		while((d.size() > 2 && d.at(0) >= '4' && d.at(0)>'9')||d.size() < 2){
			cout << "Please enter a valid two digit day: ";
			cin >> d;
		}
		cout << "Type in a month (two digit number): ";
		cin >> m;
		while((m.size() > 2 && m.at(0)<= '1' && m.at(1)<='9')||m.size()<2){
			cout << "Please enter a valid two digit Month: ";
			cin >> m;
		}
		cout << "Type in a year (4 digit number): ";
		cin >> y;
		while((y.size() > 4 && y.at(0)> '9' && y.at(1)>'9'&& y.at(2)<='9'&& y.at(3)<='9')||y.size()<4){
			cout << "Please enter a valid two digit Year: ";
			cin >> m;
		}
		dueDate = d+"//"+m+"//" + y;
	}
	
	string getDuedate(){
		return dueDate;
	}
	
	void setType(){
		cout << "Type in the new task classification (personal, study, or work) followed by ENTER:" << endl;
		string taskType;
		cin >> taskType;
		while(taskType != "personal" && taskType != "study" && taskType != "work"){
			cout << "WARNING: INVALID CLASSIFICATION. PLEASE TYPE VALID CLASSIFICATION" << endl;
			cin >> taskType;
		}
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
	virtual void releaseMemory(){}
};

#endif 
