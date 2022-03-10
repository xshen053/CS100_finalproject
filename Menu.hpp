#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <string>
#include <vector>
#include "SubList.hpp"
#include "task.hpp"
#include "select.hpp"
using namespace std;



class Select;
class Base;

class Menu{                           
private:
    vector<Base*> base;
    vector<Base*> spreadsheet;    //store all task and sublist regardless of hierarchy 
    int currentElement;           //current Task/Sublist order in spreadsheet
    string Name;                  //current Task/Sublist name
	Select *displayStrategy = nullptr;      //different method to display tasks and sublists
public:
	
	Menu(vector<Base*> tasklist){
	    base = tasklist;
	}
	
	//Select
	void set(Select *s){
//		displayStrategy->clear();
		delete displayStrategy;
		displayStrategy = s;
	}
	
	//release memory
        void clear(){
	    cout << "test:" << endl;
            for (vector<Base*>::iterator it = base.begin(); it != base.end(); it++){
	        if(*it != NULL){
		    delete *it;
		    *it = NULL;
		}
	    }
	    
            for (vector<Base*>::iterator it = spreadsheet.begin(); it != spreadsheet.end(); it++){
                if(*it != NULL){
                    delete *it;
                    *it = NULL;
                }
            }
	    //spreadsheet.clear();
	    
	}
        //release all memory 
        void release(){
            for(int i = 0; i < spreadsheet.size(); i++){
                delete spreadsheet.at(i);
	   
	}
	}
        //release memory of one task
	//only work when hierarchy is 0
	void releaseOneTask(){
             for(int i = 0; i < spreadsheet.size(); i++){
                 if (spreadsheet.at(i)->getName() == Name){
	             delete spreadsheet.at(i);
                     break;
                 }
             }
	}

	//release memory of one sublist and its childs
//	void releaseOneSubList()
	    

	void clear1(){
	    release();
//	    displayStrategy->clear();
	    delete displayStrategy;
	}

    Base* initializeTask(){
		Base* task = new Task("", "", "", "", "");
		//When creating a new task, we automatically enable user set all its properties 
		task->setName();
		task->setPriority();
		task->setDescription();
		task->setDuedate();
		task->setType();
		spreadsheet.push_back(task);
		
		return task;
	}
	
	//delete one element in spreadsheet
	void deleteOneElementFromSpreadsheet(){
		spreadsheet.erase(spreadsheet.begin() + currentElement);
	}
	
	//delete one element in base
	void deleteOneElementFromBase(){
		for(int i = 0; i < base.size(); i++){
			if (base.at(i)->getName() == Name){
				base.erase(base.begin() + i);
				break;
			}
		}
	}
	
	void deleteAllElementFromSpreadsheet(){
		if(spreadsheet.size() == 0){
		    cout << "Don't have any task or sublist!!" << endl;
		}
		else{
		    for(vector<Base*>::iterator itr = spreadsheet.begin(); itr != spreadsheet.end();){
			    itr = spreadsheet.erase(itr);
		    }				
		} 
	}
	void deleteAllElementFromBase(){
		if(base.size() == 0){
		    cout << "Don't have any task or sublist!!" << endl;
		}
		else{
		    for(vector<Base*>::iterator itr = base.begin(); itr != base.end();){
			    itr = base.erase(itr);
		    }				
		} 		
	}
	
	//find a specific sublist or task
	void searchdata(){
		cout << "Which SubList/Task do you want to edit?" << endl;
	    string name;
	    getline(cin.ignore(), name);
	    int flag = -1;
		for(int i = 0; i < spreadsheet.size(); i++){
			if (spreadsheet.at(i)->getName() == name){
				flag = i;
				break;
			}
		}
		currentElement = flag;
	}
	
    Base* initializeSublist(){
		vector<Base*> listofTasks;
		Base* sublist = new SubList("", "", "", "", "", listofTasks);
		//When creating a new sublist, we automatically enable user set all its properties 
		sublist->setName();
		sublist->setPriority();
		sublist->setDescription();
		sublist->setDuedate();
		sublist->setType();
		spreadsheet.push_back(sublist);
        return sublist;
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
    cout << "f - View finished tasks (multiple strategy)" << endl;
    cout << "g - View unfinished tasks (multiple strategy)" << endl;
    cout << "h - Display by priority (multiple strategy)" << endl;
    cout << "i - Display by duedate (multiple strategy)" << endl;
    cout << "j - Display by classification (multiple strategy)" << endl;
    cout << "k - Delete all Sublists and tasks" << endl;
//    cout << "l - Display by duedate with priority" << endl; 
//    cout << "m - Display unfinished task ordered by duedate and priority" << endl;    
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
	cout << "g - Mark this task as finished" << endl;
	cout << "h - Mark this task as unfinished" << endl;
	cout << "q - return to Main Menu" << endl;
	cout << "------------------------------------------" << endl;
	}
	void printSubListActions(){
	cout << "What do you want to do with this sublist?" << endl;
	cout << "a - Set(change) sublist name" << endl;
	cout << "b - Set(change) priority" << endl;
	cout << "c - Set(change) desciption" << endl;
	cout << "d - Set(change) due date" << endl;
	cout << "e - Set(change) classification" << endl;
	cout << "f - Add another task to this sublist" << endl;
	cout << "g - Add another sublist to this sublist" << endl;
	cout << "h - Delete this Sublist" << endl;
    cout << "i - Mark this sublist as finished" << endl;
    cout << "j - Mark this sublist as unfinished" << endl;	
	cout << "q - Return to Main Menu" << endl;
	cout << "------------------------------------------" << endl;
	
	
	
	}
	
	void MenuActions(){
		char input;
		string userInput;
		cin >> input;
		cout << endl;
		
		while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&  //&& input != 'l' && input != 'L' && input != 'm' && input != 'M' 
	           input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
	           input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
	           input != 'H' && input != 'i' && input != 'I' && input != 'j' && input != 'J' &&
			   input != 'k' && input != 'K' && input != 'q' && input != 'Q') {
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> input;
	        cout << endl;
	    }
	    
	    //Create a SubList
	    if (input == 'a' || input == 'A'){
		    //start running
		    Base* temp = initializeSublist();
		    //hierachy = 0, they don't need any parent, we can just delete them directly use Base and Spreadsheet
		    temp->setParent(NULL);
		    base.push_back(temp);
		    
		    printMenu();
		}
		
		//Create a task
	    if (input == 'b' || input == 'B'){
	        //start running
		    Base* temp = initializeTask();
		    //hierachy = 0, they don't need any parent, we can just delete them directly use Base and Spreadsheet
		    temp->setParent(NULL);
		    base.push_back(temp);
	
		    printMenu();
		}

		//Edit a SubList
	    if (input == 'c' || input == 'C'){
	    	//first display all tasks and sublists
	    	for(int i = 0; i < base.size(); i++) {
            	base.at(i)->display();
			}
			
			//search specific task or sublist
	    	searchdata();
	        if(currentElement == -1) {
	            cout << "no such SubList or Task!!" << endl;
	            cout << "\n returning to Main Menu......" << endl << endl;
	            printMenu();
			}
			
			//task or sublist found, enter task/sublist menu
			else{
	    	    printSubListActions();
	    	    SubListActions();
	        }
		printMenu();
		}
		
		//Edit a task
	        if (input == 'd' || input == 'D'){
	        	
	        //first display all tasks and sublists
	    	for(int i = 0; i < base.size(); i++) {
            	base.at(i)->display();
			}
			
			//search specific task or sublist
	        searchdata();
	        if(currentElement == -1) {
	            cout << "no such SubList or Task!!" << endl;
	            cout << "\n returning to Main Menu......" << endl << endl;
	            printMenu();
			}
			
			//task or sublist found, enter task/sublist menu
			else{
	    	    printTaskActions();
	    	    TaskActions();
	        }
		printMenu();	
		}
		
		
		//View all SubLists and tasks
	    if (input == 'e' || input == 'E'){
	    	if(base.size() == 0){
	    		cout << "Don't have any task or sublist!!" << endl;
			}
			else{
                for(int i = 0; i < base.size(); i++) {
                	//have number before every display
                	cout << i + 1 << ")" << endl;
            	    base.at(i)->display();
			    }
		    }
		printMenu();
		}
		
		//View finished tasks
	    if (input == 'f' || input == 'F'){
	    	string c = "0";
	    	cout << "1 -- just view finished tasks  " << endl << "  2 -- view finished tasks by duedate order" << endl;
	    	cin >> c;
	    	cout << endl;
	    	while(c != "1" && c != "2"){
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> c;
	        cout << endl;	    	    
			}
	    	if(c == "1"){
	    	    set(new Select_Finished(new Select_GetList(base)));	
			}
			else if(c == "2"){
				set(new Select_Finished(new Select_ByDueDate(new Select_GetList(base))));
			}
			print();
                printMenu();			
		}
		
		//View unfinished tasks
	    if (input == 'g' || input == 'G'){
	    	string c = "0";
	    	cout << "1 -- just view unfinished tasks  " << endl << "  2 -- view unfinished tasks by duedate order" << endl;
	    	cin >> c;
	    	cout << endl;
	    	while(c != "1" && c != "2"){
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> c;
	        cout << endl;	    	    
			}
	    	if(c == "1"){
	    	    set(new Select_Unfinished(new Select_GetList(base)));	
			}
			else if(c == "2"){
				set(new Select_Unfinished(new Select_ByDueDate(new Select_GetList(base))));
			}
			print();
	        printMenu();		
		}
		
	//	//Display by priority
	    if (input == 'h' || input == 'H'){
	    	string c = "0";
	    	cout << "1 -- just view tasks by priority  " << endl << "  2 -- view tasks by priority and duedate" << endl;
	    	cin >> c;
	    	cout << endl;
	    	while(c != "1" && c != "2"){
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> c;
	        cout << endl;	    	    
			}
	    	if(c == "1"){
	    	    set(new Select_ByPriority(new Select_GetList(base)));	
			}
			else if(c == "2"){
				set(new Select_ByPriority(new Select_ByDueDate(new Select_GetList(base))));
			}
			print();
                printMenu();
		}
		
		//Display by duedate
	    if (input == 'i' || input == 'I'){
	    	string c = "0";
	    	cout << "1 -- just view tasks by duedate  " << endl << "  2 -- view tasks by priority and duedate" << endl;
	    	cin >> c;
	    	cout << endl;
	    	while(c != "1" && c != "2"){
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> c;
	        cout << endl;	    	    
			}
	    	if(c == "1"){
	    	    set(new Select_ByDueDate(new Select_GetList(base)));	
			}
			else if(c == "2"){
				set(new Select_ByDueDate(new Select_ByPriority(new Select_GetList(base))));
			}
			print();  	
	        printMenu();
		}
		
		//Display by classification
	    if (input == 'j' || input == 'J'){
	    	string c = "0";
	    	cout << "1 -- just view tasks by classification  " << endl << "  2 -- view tasks by classification and duedate" << endl;
	    	cin >> c;
	    	cout << endl;
	    	while(c != "1" && c != "2"){
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> c;
	        cout << endl;	    	    
			}
	    	cout << "Which type of tasks and sublist do you want to see (work, study, or personal)" << endl;
	    	string type;
	    	cin >> type;			
	    	if(c == "1"){
	    	    set(new Select_ByClassification(new Select_GetList(base), type));	
			}
			else if(c == "2"){
				set(new Select_ByClassification(new Select_ByDueDate(new Select_GetList(base)), type));
			}
			print();
                printMenu();
		}
		
		//Delete all Sublists and tasks
	    if (input == 'k' || input == 'K'){
		//release memory
                release();
	    	deleteAllElementFromSpreadsheet();
	    	deleteAllElementFromBase();
                printMenu();		
		}
    	    
	    if (input == 'q' || input == 'Q'){
            cout << "See you next time!" << endl;
//            exit(0);
	    }
	    cout << "\n returning to Main Menu......" << endl << endl;
//	    printMenu();
	
}


    void TaskActions(){
    	
    	//get input;
		char input;
		string userInput;
		cin >> input;
		cout << endl;
		
		//make sure input is valid
		while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
	           input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
	           input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
	           input != 'H' && input != 'q' && input != 'Q') {
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> input;
	        cout << endl;
	    }
	    
	    //a - Set(change) task name
	    if (input == 'a' || input == 'A'){
//	        base.at(base.size() - 1)->setName();
	        spreadsheet.at(currentElement)->setName();
//	        (base.at(base.size() - 1))->display();
	    }
	    
	    //b - Set(change) priority    
	    if (input == 'b' || input == 'B'){
//			base.at(base.size() - 1)->setPriority();
            spreadsheet.at(currentElement)->setPriority();
		}
		
		//c - Set(change) desciption
	    if (input == 'c' || input == 'C'){
//			base.at(base.size() - 1)->setDescription();
            spreadsheet.at(currentElement)->setDescription();
		}
		
		//d - Set(change) due date
	    if (input == 'd' || input == 'D'){
//			base.at(base.size() - 1)->setDuedate();
            spreadsheet.at(currentElement)->setDuedate();
		}
		
		//e - Set(change) classification
	    if (input == 'e' || input == 'E'){
//		    base.at(base.size() - 1)->setType();
            spreadsheet.at(currentElement)->setType();
		}
	    
	    //f - Delete this task
	    if (input == 'f' || input == 'F'){
	    	//we need to know the name of sublist we need to delete
                Name = spreadsheet.at(currentElement)->getName();
	    	//its hierarchy is 0 
		    if(spreadsheet.at(currentElement)->getHierarchy() == 0) {
                        deleteOneElementFromBase();    
			//release its memory
			releaseOneTask();
		    	//delete this task both in spreadsheet and base
		    	deleteOneElementFromSpreadsheet();
			}
			else{
			    // now currentElement task is the one we need to delete
				//just call function to delete it
				spreadsheet.at(currentElement)->getParent()->deleteOneSpecificSublist(Name);
				//release its memory
				//releaseOneTask();
				//we still need to delete it from vector spreadsheet, we just deleted it from vector base
				deleteOneElementFromSpreadsheet();
			}            
		}
		
		//g - Mark this task as finished
		if  (input == 'g' || input == 'G'){
//			base.at(base.size() - 1)->setFinished();
                    spreadsheet.at(currentElement)->setFinished();
	        }
		
		//h - Mark this task as unfinished
		if  (input == 'h' || input == 'H'){
//			base.at(base.size() - 1)->setUnfinished();
                    spreadsheet.at(currentElement)->setUnfinished();
         	}
	    
	    //q - Return to Main Menu
	    if (input == 'q' || input == 'Q'){
	    cout << "\n returning to Main Menu......" << endl << endl;
	    printMenu();
		}

        
    }
	
	

    
	//Edit a Sublist
	void SubListActions(){
		char input;
		string userInput;
		cin >> input;
		cout << endl;
		
		//make sure input is valid
		while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' &&
	           input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' &&
	           input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
	           input != 'H' && input != 'i' && input != 'I' && input != 'j' && input != 'J' && 
			   input != 'q' && input != 'Q') {
	        cout << "Error: Unknown input. Please Select a valid option: ";
	        cin >> input;
	        cout << endl;
	    }
	    
	    //a - Set(change) sublist name
	    if (input == 'a' || input == 'A'){
//	        base.at(base.size() - 1)->setName();
            spreadsheet.at(currentElement)->setName();
	    }
	    
	    //b - Set(change) priority    
	    if (input == 'b' || input == 'B'){
//			base.at(base.size() - 1)->setPriority();
            spreadsheet.at(currentElement)->setPriority();
		}
		//c - Set(change) desciption
	    if (input == 'c' || input == 'C'){
//			base.at(base.size() - 1)->setDescription();
			spreadsheet.at(currentElement)->setDescription();
		}
		
		//d - Set(change) due date
	    if (input == 'd' || input == 'D'){
//			base.at(base.size() - 1)->setDuedate();
            spreadsheet.at(currentElement)->setDuedate();
		}
		
		//e - Set(change) classification
	    if (input == 'e' || input == 'E'){
//		    base.at(base.size() - 1)->setType();
            spreadsheet.at(currentElement)->setType();
		}
		
		//f - Add another task to this sublist
		//assumption: we can only first creat a new task and then add it to this sublist 
	    if (input == 'f' || input == 'F'){
		    Base* temp = initializeTask();
		    //A task embedded in a list will not store in the main vector which is vector<Base*> base 
		    spreadsheet.at(currentElement)->push(temp);
		    //set its parent, so that we are able to delete it using its parent
		    temp->setParent(spreadsheet.at(currentElement));
		    //get this task's hierarchy 
		    int h = spreadsheet.at(currentElement)->getHierarchy();
		    //Increase newly-add task hierarchy
			temp->hierarchyIncrease(h);
		}
	    
	    //g - Add another List to this sublist
	    //assumption: we can only first creat a new sublist and then add it to this sublist 
	    if (input == 'g' || input == 'G'){
		    Base* temp = initializeSublist();
		    //A sublist embedded in a list will not store in the main vector which is vector<Base*> base 
		    spreadsheet.at(currentElement)->push(temp);
		    //set its parent, so that we are able to delete it using its parent
		    temp->setParent(spreadsheet.at(currentElement));
		    //get this list's hierarchy 
		    int h = spreadsheet.at(currentElement)->getHierarchy();
		    //Increase newly-add sublist hierarchy
			temp->hierarchyIncrease(h);

		}
	    
	    //h - Delete this Sublist, which will automatically delete all of its sublist 
	    if (input == 'h' || input == 'H'){
	    	Name = spreadsheet.at(currentElement)->getName();
	    	//its hierarchy is 0 
		    if(spreadsheet.at(currentElement)->getHierarchy() == 0) {
                
		    	//make sure this list have already erase all of its sublists
		    	spreadsheet.at(currentElement)->deleteAllSublist();
			//we need to delete it in base before we release its memory
                        deleteOneElementFromBase();
			//release its memory
			delete spreadsheet.at(currentElement);
		    	//delete this sublist both in spreadsheet and base
		    	deleteOneElementFromSpreadsheet();
			}
			else{
			    // now currentElement sublist is the one we need to delete
			    // so we need to get its parent	
				spreadsheet.at(currentElement)->getParent();
				//we need to know the name of sublist we need to delete
				string name = spreadsheet.at(currentElement)->getName();
				//just call function to delete it
				spreadsheet.at(currentElement)->getParent()->deleteOneSpecificSublist(name);
				//release its memory
				//delete spreadsheet.at(currentElement);
				//we still need to delete it from vector spreadsheet, we just deleted it from vector base
				deleteOneElementFromSpreadsheet();
			}
		}
		
		if (input == 'i' || input == 'I'){
            spreadsheet.at(currentElement)->setFinished();			
		}
		
		if (input == 'j' || input == 'J'){
			spreadsheet.at(currentElement)->setUnfinished();
		}
	    
	    //q - Return to Main Menu
	    if (input == 'q' || input == 'Q'){
	    cout << "\n returning to Main Menu......" << endl << endl;
		printMenu();
		}
	        
    }
    
    //strategy for print
	void print(){
		displayStrategy->view();
	}
};
#endif
