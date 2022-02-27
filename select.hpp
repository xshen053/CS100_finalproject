#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <string>
#include <vector>
#include "SubList.hpp"
#include "task.hpp"
#include <algorithm>
using namespace std;
class Base;

class Select{
public:
    virtual ~Select() = default;
    virtual void view() = 0;
};

class Select_ByPriority: public Select{
protected:
    vector<Base*> base;
    
public:
    ~Select_ByPriority(){}
    Select_ByPriority(vector<Base*> data){
	base = data;
	}
    
    void view(){
    	int flag = 1;
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "high"){
    			cout << flag++ << ")" << endl;
    			base.at(i)->display();
			}
		}
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "medium"){
    			cout << flag++ << ")" << endl;    			
    			base.at(i)->display();
			}
		}
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "low"){
    			cout << flag++ << ")" << endl;    			
    			base.at(i)->display();
			}
		}				
	}
    
};

class Select_ByDueDate: public Select{
protected:
    vector<Base*> base;
    vector<Base*> temp;
public:
    ~Select_ByDueDate(){}
    
    Select_ByDueDate(vector<Base*> data){
	    base = data;
	    for(int i = 0; i < data.size(); i++){   	
	    	temp.push_back(data.at(i));
		}
	}
	
	static bool cmp(Base* a1, Base* a2){
		int dd1, dd2;
		int mm1, mm2;
		int yy1, yy2;	
		dd1 = stoi(a1->getDuedate().substr(0, 2));
		dd2 = stoi(a2->getDuedate().substr(0, 2));
		mm1 = stoi(a1->getDuedate().substr(3, 2));
		mm2 = stoi(a2->getDuedate().substr(3, 2));
		yy1 = stoi(a1->getDuedate().substr(6, 4));
		yy2 = stoi(a2->getDuedate().substr(6, 4));			
	    if(yy1 != yy2)
	        return yy1 < yy2;
	    else if(mm1 != mm2){
	    	return mm1 < mm2;
		}
		else if(dd1 != dd2){
			return dd1 < dd2;
        }
        //two dates are equal
		else{
			return false;
		}		
	}
	
	void view(){
	    sort(temp.begin(), temp.end(), cmp);
    	for(int i = 0; i < temp.size(); i++){
    		cout << i + 1 << ")" << endl;	     		
    		temp.at(i)->display();
		}
	}
    
    
};


//
class Select_ByClassification: public Select{
protected:
    vector<Base*> base;
    string t;
public:
    ~Select_ByClassification(){}
    Select_ByClassification(vector<Base*> data, string type){
	   base = data;
	   t = type; 
	}
    
    void view(){
    	int flag = 1;
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getType() == t){
    		    cout << flag++ << ")" << endl;	     			
    			base.at(i)->display();
			}
		}    	
	}

    
};

class Select_Finished: public Select{
protected:
    vector<Base*> base;
    
public:
    ~Select_Finished(){}
    Select_Finished(vector<Base*> data){
	    base = data;}
	void view(){
		int flag = 1;
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->isComplete() == true){
   		        cout << flag++ << ")" << endl;    			
    			base.at(i)->display();
			}
		}		
	}    

    
};

class Select_Unfinished: public Select{
protected:
    vector<Base*> base;
	    
public:
    ~Select_Unfinished(){}
    Select_Unfinished(vector<Base*> data){
        base = data;
	}
	void view(){
		int flag = 1;
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->isComplete() == false){
   		        cout << flag++ << ")" << endl;        			
    			base.at(i)->display();
			}
		}		
	}    

    
};
#endif
