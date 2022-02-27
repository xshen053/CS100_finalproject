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
		complete = false;
		hierarchy = 0; 
	}
	
    void display(){
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Sublist Name:" << title << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Sublist Priority:" << priority << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}
		cout << "Sublist Description:" << description << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}		
		cout << "Sublist Duedate:" << dueDate << endl;
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}		
		cout << "Sublist type:" << classification << endl; 
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
	
	void setName(){
		cout << "Type in new sublist name followed by ENTER:" << endl;
		string taskName;
		getline(cin.ignore(), taskName);
		title = taskName;
	}
	
	string getName(){
		return title;
	}
	
	void setPriority(){
		cout << "Type in the new sublist priority (high, medium, or low) followed by ENTER" << endl;
		string taskPriority;
		cin >> priority;
	    priority = taskPriority;
	}
	
	string getPriority(){
		return priority;
	}
	
	void setDescription(){
		cout << "Type in the new sublist description followed by ENTER:" << endl;
		string taskDescription;
		getline(cin.ignore(), taskDescription);
		description = taskDescription;
	}
	
	string getDescription(){
		return description;
	}
	
	void setDuedate(){
		cout << "Type in the new sublist duedate (mm/dd/year) followed by ENTER:" << endl;
		string taskDueDate;
		cin >> taskDueDate;
		dueDate = taskDueDate;
	}
	
	string getDuedate(){
		return dueDate;
	}
	
	void setType(){
		cout << "Type in the new sublist classification followed by ENTER:" << endl;
		string taskType;
		cin >> taskType;
		classification = taskType;
	}
	
	string getType(){
		return classification;
	}
	
	string checkType(){
		return "SubList task";
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
	
	//SubList function
	vector<Base*> getSubLists(){
		return listOfTasks;
	}
	
	void push(Base* t){
		listOfTasks.push_back(t);
	}
	
};

#endif 
