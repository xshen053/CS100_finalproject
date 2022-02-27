#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <string>
#include <vector>
#include "SubList.hpp"
#include "task.hpp"
class Base;

class Select{
public:
    virtual ~Select() = default;
    
    virtual void view() = 0;
};

//class Select_ByDueDate: public Select{
//protected:
//    vector<Base*> base;
//    
//public:
//    ~Select_ByDueDate(){}
//    Select_ByDueDate(vector<Base*> data){
//	base = data;
//	}
//    
//    
//};

class Select_ByPriority: public Select{
protected:
    vector<Base*> base;
    
public:
//    ~Select_ByPriority(){}
    Select_ByPriority(vector<Base*> data){
	base = data;
	}
    
    void view(){
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "high"){
    			base.at(i)->display();
			}
		}
	}
    
};
//
//class Select_ByCategory: public Select{
//protected:
//    int column;
//    bool* Rows;
//    int size;
//    
//public:
//    ~Select_ByCategory(){}
//    Select_ByCategory(){}
//    
//
//    
//};
//
//class Select_Finished: public Select{
//protected:
//    int column;
//    bool* Rows;
//    int size;
//    
//public:
//    ~Select_Finished(){}
//    Select_Finished(){}
//    
//
//    
//};
//
//class Select_Unfinished: public Select{
//protected:
//    int column;
//    bool* Rows;
//    int size;
//    
//public:
//    ~Select_Unfinished(){}
//    Select_Unfinished(){}
//    
//
//    
//};
#endif
