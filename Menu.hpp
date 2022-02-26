#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "SubList.hpp"
#include "task.hpp"
using namespace std;
void SubListActions();


class Select;
class Base;

class Menu{                           //spreadsheet 
private:
    vector<Base*> base;
    
    
public:
	
	Menu(vector<Base*> tasklist){
	base = tasklist;
	}
	
	
	
	
	void printMenu(){
    cout << "=====================================================" << endl;
    cout << " \t\tMENU \t \n ";
    cout << "=====================================================" << endl;
    cout << "a - Create a SubList" << endl;
    cout << "b - Create a task" << endl;
    cout << "c - Edit a SubList" << endl;
    cout << "d - Edit a task" << endl;
    cout << "e - View all SubLists and tasks" << endl;
    cout << "f - View finished tasks" << endl;
    cout << "g - View finished tasks" << endl;
    cout << "h - Display by priority" << endl;
    cout << "i - Display by duedate" << endl;
    cout << "j - Display by classification" << endl;
    cout << "k - Delete all Sublists and tasks" << endl;
    cout << "q - Exit Task Scheduler" << endl;
    MenuActions();
	}
	
	
	void printTaskActions(){
	cout << "What do you want to do with this task?" << endl;
	cout << "=====================================================" << endl;
	cout << "a - Set(change) task name" << endl;
	cout << "b - Set(change) priority" << endl;
	cout << "c - Set(change) desciption" << endl;
	cout << "d - Set(change) due date" << endl;
	cout << "e - Set(change) classification" << endl;
	cout << "f - Delete this task" << endl;
	cout << "q - return to Main Menu" << endl;
	cout << "------------------------------------------" << endl;
	}
	void printSubListActions(){
	cout << "What do you want to do with this sublist?" << endl;
	cout << "a - Set(change) task name" << endl;
	cout << "b - Set(change) priority" << endl;
	cout << "c - Set(change) desciption" << endl;
	cout << "d - Set(change) due date" << endl;
	cout << "e - Set(change) classification" << endl;
	cout << "f - Add another task" << endl;
	cout << "g - Add another List" << endl;
	cout << "h - Delete this Sublist" << endl;
	cout << "q - Return to Main Menu" << endl;
	cout << "------------------------------------------" << endl;
	
	
	
	}
	
	void MenuActions(){
	char input;
	string userInput;
	cin >> input;
	cout << endl;
	
	while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
           input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
           input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
           input != 'H' && input != 'i' && input != 'I' && input != 'q' && input != 'Q') {
        cout << "Error: Unknown input. Please Select a valid option: ";
        cin >> input;
        cout << endl;
    }
    
    //Create a SubList
    if (input == 'a' || input == 'A'){
    vector<Base*> listofTasks;
    Base* sublist = new SubList("", "", "", "", "", listofTasks);
	base.push_back(sublist);
	//start running
	printSubListActions();
	SubListActions();
	}
	
//	//Create a task
//    if (input == 'b' || input == 'B'){
//    	
//	}
//	
//	//Edit a SubList
//    if (input == 'c' || input == 'C'){
//    	
//	}
//	
//	//Edit a task
//    if (input == 'd' || input == 'D'){
//    	
//	}
//	
//	//View all SubLists and tasks
//    if (input == 'e' || input == 'E'){
//    	
//	}
//	
//	//View finished tasks
//    if (input == 'f' || input == 'F'){
//    	
//	}
//	
//	//View finished tasks
//    if (input == 'g' || input == 'G'){
//    	
//	}
//	
//	//Display by priority
//    if (input == 'h' || input == 'H'){
//    	
//	}
//	
//	//Display by duedate
//    if (input == 'i' || input == 'I'){
//    	
//	}
//	
//	//Display by classification
//    if (input == 'j' || input == 'J'){
//    	
//	}
//	
//	//Delete all Sublists and tasks
//    if (input == 'k' || input == 'K'){
//    	
//	}										
//    
//	}
//	
//	void TaskActions(){
//	
//	
//	}


	
	
}
	
	void SubListActions(){
	char input;
	string userInput;
	cin >> input;
	cout << endl;
	
	while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
           input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
           input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
           input != 'H' && input != 'i' && input != 'I' && input != 'q' && input != 'Q') {
        cout << "Error: Unknown input. Please Select a valid option: ";
        cin >> input;
        cout << endl;
    }
        if (input == 'a' || input == 'A'){
            base.at(base.size() - 1)->setName("Helloworld");
            cout << base.size() << endl;
            (base.at(base.size() - 1))->display();
        }
    }
};
#endif
