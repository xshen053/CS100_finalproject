#include "tasks.hpp"
#include <string>
#include <iostream>
#include <vector>
 
using namespace std;

void taskList::writeTask(){
	cout << "Users List" << endl; //need to change to users name
    for(unsigned i = 0; i < tList.size(); i++){
        cout << i+1 << ". " << tList.at(i)->getName() << endl;
    }
}
void taskList::addTask(string t){
    task* i = new task();
    i->setName(t);
    tList.push_back(i);
}

int taskList::listSize(){
	return tList.size();
}

void task::setName(string name){
	taskName = name;
}
 string task::getName(){
 	return taskName;
 }

