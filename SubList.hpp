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
	
//    ~SubList();
	
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
		for (int i = 0; i < hierarchy; i++){
			cout << "\t"; 
		}		 
		cout << "Is Sublist complete: ";
		if(complete == false){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}		
		displaySubLists();	
	}
	
	void refreshSubLists(vector<Base*> ListofTasks){
		listOfTasks = ListofTasks;
	} 
	
	void displaySubLists(){
            for(int i = 0; i < listOfTasks.size(); i++){   
                listOfTasks.at(i)->display();

        }
	}
	//releasememory space of whole sublist of current sublist
        void releaseMemory(){
	    for(int i = 0; i < listOfTasks.size(); i++){
	        if(listOfTasks.at(i)->checkType() == "Single task"){
		    delete listOfTasks.at(i);
		}
	        else if(listOfTasks.at(i)->checkType() == "SubList task"){
		    listOfTasks.at(i)->releaseMemory();
		    delete listOfTasks.at(i);
		}	
	    }    
	}

	void setName(){
		cout << "Type in new sublist name followed by ENTER:" << endl;
		string taskName = "";
		cin.ignore();
		while(taskName == ""){
			getline(cin,taskName);
			if(taskName == ""){
				cout << "ERROR: NO NAME DETECTED. PLEASE ENTER A NAME FOR SUBLIST" << endl;
			}
		}
		title = taskName;
	}
	
	string getName(){
		return title;
	}
	
	void setPriority(){
		cout << "Type in the new sublist priority (high, medium, or low) followed by ENTER" << endl;
		string taskPriority;
		cin >> taskPriority;
		while(taskPriority != "high" && taskPriority != "medium" && taskPriority != "low"){
			cout << "WARNING: INVALID PRIORITY. PLEASE ENTER SUBLIST PRIORITY:" << endl;
			cin >> taskPriority;
		}
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
		cout << "Type in the new Sublist duedate (dd/mm/yyyy) followed by ENTER:" << endl;
		string d="";
		string m="";
		string y="";
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
			cout << "Please enter a valid 4 digit Year: ";
			cin >> m;
		}
		dueDate = d+"//"+m+"//" + y;
	}
	
	string getDuedate(){
		return dueDate;
	}
	
	void setType(){
		cout << "Type in the new sublist classification (personal, study, or work)  followed by ENTER:" << endl;
		string taskType = "";
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
	
	void setParent(Base* p){
		parent = p;
	}
	
	Base* getParent(){
		return parent;
	}
	
	bool isComplete(){
		return complete;
	}	
	
	//SubList function
	vector<Base*> getSubLists(){
		return listOfTasks;
	}
	
	//put one task/sublist into its list as a sublist
	void push(Base* t){
		listOfTasks.push_back(t);
	}
	
	//delete all its Sublist
	void deleteAllSublist(){
		if(listOfTasks.size() != 0){
	            releaseMemory();
		    for(vector<Base*>::iterator itr = listOfTasks.begin(); itr != listOfTasks.end();){
			    itr = listOfTasks.erase(itr);
		    }	
		}

	}
	//deleteOneSpecificSublist
	void deleteOneSpecificSublist(string name){
		//debug
//		cout << "size: " << listOfTasks.size() << endl;
		int flag = -1;
		for(int i = 0; i < listOfTasks.size(); i++){
			if (listOfTasks.at(i)->getName() == name){
				flag = i;
				//debug
                //cout << "flag:" << flag << endl;
				break;
			}
		}
		if(listOfTasks.at(flag)->checkType() == "Single task"){
		    delete listOfTasks.at(flag);
		}
		else{
		//release its sublist's memory
		    listOfTasks.at(flag)->releaseMemory();
		    delete listOfTasks.at(flag);
		}
                listOfTasks.erase(listOfTasks.begin() + flag);
        //debug
//        cout << "size: " << listOfTasks.size() << endl;
	}
	
};

#endif 
