#include "Base.hpp"
#include "task.hpp"
#include "Menu.hpp"
#include "SubList.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(){
	vector<Base*> listofTasks;
	Menu *menu = new Menu(listofTasks);
	menu->printMenu();
//	
//	Base* a = new Task("", "", "", "", "");
//	Base* c = new Task("", "", "", "", "");
//	Base* e = new Task("", "", "", "", "");
////	listofTasks.push_back(a);
////	listofTasks.push_back(c);
//	Base* b = new SubList("", "", "", "", "", listofTasks);
//	//variable can only be change in that function 
//	b->push(a);
//	b->push(c);
////	vector<Base*> temp = b->getSubLists();
//////	
//////	temp.push_back(a);
//////	temp.push_back(c);
//////	listofTasks.push_back(b);
//	vector<Base*> listofTasksb;    
//	listofTasksb.push_back(b);
//	listofTasksb.push_back(e);
//    Base* d = new SubList("", "", "", "", "", listofTasksb);
//////    d->getSubLists().back()->getSubLists().push_back(a);
//////    d->getSubLists().back()->getSubLists().push_back(c);
//	a->setName();
//	a->setPriority();
//	a->setDuedate();
//	a->setDescription();
//	a->setType();
//	
//	b->setName();
//	b->setPriority();
//	b->setDuedate();
//	b->setDescription();
//	b->setType();
//	c->setName();
//	c->setPriority();
//	c->setDuedate();
//	c->setDescription();
//	c->setType();
//		
//	e->setName();
//	e->setPriority();
//	e->setDuedate();
//	e->setDescription();
//	e->setType();
//////	b->displayTask();
////	cout << endl;
//////	auto iter = listofTasks.erase(listofTasks.begin());
////	
////	//veryimportant function to delete task from a sublist
//////	b->refreshSubLists(listofTasks);
////	
//    string g = "b";
//	d->display();
////	d->deleteAllSublist();
//	cout << "--------------------";
//	d->display();
//	d->deleteOneSpecificSublist(g);
//	cout << "--------------------";
//	d->display();
////	cout << endl;


	return 0;
	
	
	
	
}
