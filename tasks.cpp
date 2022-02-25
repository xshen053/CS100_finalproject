#include "tasks.hpp"
#include <string>
#include <iostream>
#include <vector>
 
using namespace std;

taskList::taskList(string listName, string listD){
	lName = listName;
	listDesc = listD;
}

void taskList::display(){
	cout << lName << " " << listDesc << endl;
    for(int i = 0; i < tList.size(); i++){
    	tList.at(i)->display();
    }
}

void taskList::addTask(taskBase* t){
    tList.push_back(t);
}

int taskList::listSize(){
	return tList.size();
}

task::task(string name, string category, int priority){
	taskName = name;
	taskC = category;
	taskP = priority;
}

void task::setName(string name){
	taskName = name;
}

 string task::getName(){
 	return taskName;
 }
 
 void task::display(){
 	cout << "Task: " << taskName << endl;
 	cout << "Category: " << taskC << endl;
 	cout << "Priority: " << taskP << endl << endl;
 }
