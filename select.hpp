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
    virtual void clear() = 0;
};


class Select_GetList: public Select{
protected:
    vector<Base*> out;
public:
	Select_GetList(const vector<Base*> data){
    	for(int i = 0; i < data.size(); i++){
                out.push_back(data.at(i)); 		
		}		
	}
	vector<Base*> getData(){                                 //get vector that stores data already sorted
		return out;
	}
	virtual void view(){}
        void clear(){
	    for(int i = 0; i < out.size(); i++){
	        delete out.at(i);
	    }
	}
	
};

//add sort of duedate to current sorting
class Select_ByDueDate: public Select{
protected:
    vector<Base*> base;
    vector<Base*> out;
	
public:
    ~Select_ByDueDate(){}
    Select_ByDueDate(Select* data){                               //data is an array already sorted by duedate
    	base = data->getData();
	    for(int i = 0; i < base.size(); i++){   	
	    	out.push_back(base.at(i));
		}
		sort(out.begin(), out.end(), cmp);	
	delete data;
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
        void clear(){
            for(int i = 0; i < out.size(); i++){
                delete out.at(i);
            }
        }
	
	
};


class Select_ByPriority: public Select{
protected:
    vector<Base*> out;
    vector<Base*> base;
public:
    ~Select_ByPriority(){}
    Select_ByPriority(Select* data){
    	base = data->getData();
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "high"){
                out.push_back(base.at(i));
			}    		
		}
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "medium"){
                out.push_back(base.at(i));
			}    		
		}	
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getPriority() == "low"){
                out.push_back(base.at(i));
			}    		
		}
        for(int i = 0; i < base.size(); i++){
                if(base.at(i)->getPriority() != "low" && base.at(i)->getPriority() != "medium" && base.at(i)->getPriority() != "high"){
                out.push_back(base.at(i));
                       }
                }
	
        delete data;	
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
        void clear(){
            for(int i = 0; i < out.size(); i++){
                delete out.at(i);
            }
        }
	
    
};

class Select_ByClassification: public Select{
protected:
	vector<Base*> base;
    vector<Base*> out;
public:
    ~Select_ByClassification(){}
    Select_ByClassification(Select* data, string type){
    	base = data->getData();
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->getType() == type){
    	        out.push_back(base.at(i));
			}
		}        
       delete data;	
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
        void clear(){
            for(int i = 0; i < out.size(); i++){
                delete out.at(i);
            }
        }
    	
};

class Select_Finished: public Select{
protected:
    vector<Base*> out;
    vector<Base*> base;
public:
    ~Select_Finished(){}
    Select_Finished(Select* data){
    	base = data->getData();
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->isComplete() == true){   			
    	        out.push_back(base.at(i));    			
			}
		}
        delete data;	
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
        void clear(){
            for(int i = 0; i < out.size(); i++){
                delete out.at(i);
            }
        }
	

    
};

class Select_Unfinished: public Select{
protected:
    vector<Base*> out;
	vector<Base*> base;
public:
    ~Select_Unfinished(){}
    Select_Unfinished(Select* data){
    	base = data->getData();
    	for(int i = 0; i < base.size(); i++){
    		if(base.at(i)->isComplete() == false){   			
    	        out.push_back(base.at(i));    			
			}
		}
	delete data;
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
        void clear(){
            for(int i = 0; i < out.size(); i++){
                delete out.at(i);
            }
        }
	

    
};


#endif
