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
//	listofTasks.push_back(a);
//	listofTasks.push_back(c);
//	Base* b = new SubList("", "", "", "", "", listofTasks);
////	listofTasks.push_back(b);
//	vector<Base*> listofTasksb;    
//	listofTasksb.push_back(b);
//    Base* d = new SubList("", "", "", "", "", listofTasksb);
//	a->setName("helloworld");
//	a->setPriority("hurry");
//	a->setDuedate("2020");
//	a->setDescription("fdsf");
//	a->setType("haha");
//	
//	c->setName("helloworld");
//	c->setPriority("hurry");
//	c->setDuedate("2021");
//	c->setDescription("fdsf");
//	c->setType("haha");
////	a->displayTask();
//	b->setName("helloworld");
//	b->setPriority("hurry");
//	b->setDuedate("2022");
//	b->setDescription("fdsf");
//	b->setType("haha");
////	b->displayTask();
//	cout << endl;
////	auto iter = listofTasks.erase(listofTasks.begin());
//	
//	//veryimportant function to delete task from a sublist
////	b->refreshSubLists(listofTasks);
//	
//	d->display();
//	cout << endl;


	return 0;
	
	
	
	
}
