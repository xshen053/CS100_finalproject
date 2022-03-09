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
    virtual vector<Base*> getData() = 0;
    virtual void view() = 0;
//    virtual void sortt() = 0;
};


class Select_ByDuedateAndPriority: public Select{
protected:
    vector<Base*> base;
    vector<Base*> out;
	
public:
    ~Select_ByDuedateAndPriority(){}
    Select_ByDuedateAndPriority(Select* data){                               //data is an array already sorted by duedate
    	base = data->getData();
	    for(int i = 0; i < base.size(); i++){   	
	    	out.push_back(base.at(i));
		}
		sort(out.begin(), out.end(), cmp);    	
//    	for(int i = 0; i < base.size(); i++){
//    		if(base.at(i)->getPriority() == "high"){
//                out.push_back(base.at(i));
//			}    		
//		}
//    	for(int i = 0; i < base.size(); i++){
//    		if(base.at(i)->getPriority() == "medium"){
//                out.push_back(base.at(i));
//			}    		
//		}	
//    	for(int i = 0; i < base.size(); i++){
//    		if(base.at(i)->getPriority() == "low"){
//                out.push_back(base.at(i));
//			}    		
//		}    	
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
    	int flag = 1;
    	for(int i = 0; i < out.size(); i++){
    		cout << flag++ << ")" << endl;
    		out.at(i)->display();
		}		
	}

	vector<Base*> getData(){                                 //get vector that stores data already sorted
		return out;
	}	
	
};


class Select_ByPriority: public Select{
protected:
    vector<Base*> out;
public:
    ~Select_ByPriority(){}
    Select_ByPriority(const vector<Base*> data){
    	for(int i = 0; i < data.size(); i++){
    		if(data.at(i)->getPriority() == "high"){
                out.push_back(data.at(i));
			}    		
		}
    	for(int i = 0; i < data.size(); i++){
    		if(data.at(i)->getPriority() == "medium"){
                out.push_back(data.at(i));
			}    		
		}	
    	for(int i = 0; i < data.size(); i++){
    		if(data.at(i)->getPriority() == "low"){
                out.push_back(data.at(i));
			}    		
		}	    
	}
    
    void view(){
    	int flag = 1;
    	for(int i = 0; i < out.size(); i++){
    		cout << flag++ << ")" << endl;
    		out.at(i)->display();
		}
	}

	vector<Base*> getData(){                                 //get vector that stores data already sorted
		return out;
	}
    
};

class Select_ByDueDate: public Select{
protected:
    vector<Base*> out;
public:
    ~Select_ByDueDate(){}
    
    Select_ByDueDate(const vector<Base*> data){
	    for(int i = 0; i < data.size(); i++){   	
	    	out.push_back(data.at(i));
		}
		sort(out.begin(), out.end(), cmp);
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
    	for(int i = 0; i < out.size(); i++){
    		cout << i + 1 << ")" << endl;	     		
    		out.at(i)->display();
		}
	}

	vector<Base*> getData(){
		return out;
	}	
    
    
};


//
class Select_ByClassification: public Select{
protected:
    vector<Base*> out;
public:
    ~Select_ByClassification(){}
    Select_ByClassification(const vector<Base*> data, string type){
    	for(int i = 0; i < data.size(); i++){
    		if(data.at(i)->getType() == type){
    	        out.push_back(data.at(i));
			}
		}         
	}
    
    void view(){
    	int flag = 1;
    	for(int i = 0; i < out.size(); i++){
    		    cout << flag++ << ")" << endl;	     			
    			out.at(i)->display();
		}    	
	}
	vector<Base*> getData(){
		return out;
	}    
};

class Select_Finished: public Select{
protected:
    vector<Base*> out;
    
public:
    ~Select_Finished(){}
    Select_Finished(vector<Base*> data){
    	for(int i = 0; i < data.size(); i++){
    		if(data.at(i)->isComplete() == true){   			
    	        out.push_back(data.at(i));    			
			}
		}		
	}
	void view(){
		int flag = 1;
    	for(int i = 0; i < out.size(); i++){
    		    cout << flag++ << ")" << endl;	     			
    			out.at(i)->display();
		}		
	}
	vector<Base*> getData(){
		return out;
	}	    

    
};

class Select_Unfinished: public Select{
protected:
    vector<Base*> out;
	    
public:
    ~Select_Unfinished(){}
    Select_Unfinished(vector<Base*> data){
    	for(int i = 0; i < data.size(); i++){
    		if(data.at(i)->isComplete() == false){   			
    	        out.push_back(data.at(i));    			
			}
		}
	}
	void view(){
		int flag = 1;
    	for(int i = 0; i < out.size(); i++){
    		    cout << flag++ << ")" << endl;	     			
    			out.at(i)->display();
		}		
	}
	vector<Base*> getData(){
		return out;
	}	    

    
};

class Select_UnfinishedAndOrdered: public Select{
protected:
	vector<Base*> out;

public:
	~Select_UnfinishedAndOrdered(){}
	Select_UnfinishedAndOrdered(Select* data){
        vector<Base*> base = data->getData();
        for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->isComplete() == false){   			
    	        out.push_back(base.at(i));    			
			}
		}			
	}
	void view(){
		int flag = 1;
    	for(int i = 0; i < out.size(); i++){
    		    cout << flag++ << ")" << endl;	     			
    			out.at(i)->display();
		}		
	}	
	vector<Base*> getData(){
		return out;
	}
};

#endif
