#ifndef __SUBLIST_HPP
#define __SUBLIST_HPP

#include "Base.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;


class Base;

class SubList: public Base{

private:
    vector<Base*> listOfTasks;
	
	
public:
	
	SubList(string taskTitle, string taskPriority, string taskDescription, string taskDueDate, string taskType, vector<Base*> ListofTasks){
		title = taskTitle;
        priority = taskPriority;
        description = taskDescription;
        dueDate = taskDueDate;
        classification = taskType;
		listOfTasks = ListofTasks;
	}
	
    void display(){
		cout << "Task Name:" << title << endl;
		cout << "Task Priority:" << priority << endl;
		cout << "Task Description:" << description << endl;
		cout << "Task Duedate:" << dueDate << endl;
		cout << "Task type:" << classification << endl;   
		displaySubLists(); 	
	}
	
	void refreshSubLists(vector<Base*> ListofTasks){
		listOfTasks = ListofTasks;
	} 
	
	void displaySubLists(){
        for(int i = 0; i < listOfTasks.size(); i++) {
                listOfTasks.at(i)->display();

        }
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
		return "SubList task";
	}
	
	//SubList function
	vector<Base*> getSubLists(){
		return listOfTasks;
	}
	
};

#endif 
