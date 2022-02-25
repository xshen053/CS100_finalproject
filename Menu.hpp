#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task;
class SubList;
class Select;


class Menu{                           //spreadsheet 
private:
    std::vector<std::Base*> Base;
    
    
public:
	
	Menu(vector<Base*> tasklist) {}
	
	void printMenu(){}
	void printTaskActions(){}
	void printSubListActions(){}
	void TaskActions(){}
	void SubListActions(){}
	void MenuActions(){}
	
	
	
	
	
};
