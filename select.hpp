#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <iostream> 
#include <cstring>

class Select{
public:
    virtual ~Select() = default;
    
    virtual bool select(int row) const = 0;
    virtual int get_rows_size() const = 0;
};

class Select_ByDueDate: public Select{
protected:
    int column;
    bool* Rows;
    int size;
    
public:
    ~Select_ByDueDate(){}
    Select_ByDueDate(){}
    
    virtual bool select(int row) const{
       return Rows[row];
    }

    virtual int get_rows_size() const{
       return size; 
    } 
    
};

class Select_ByPriority: public Select{
protected:
    int column;
    bool* Rows;
    int size;
    
public:
    ~Select_ByPriority(){}
    Select_ByPtiority(){}
    
    virtual bool select(int row) const{
       return Rows[row];
    }

    virtual int get_rows_size() const{
       return size; 
    } 
    
};

class Select_ByCategory: public Select{
protected:
    int column;
    bool* Rows;
    int size;
    
public:
    ~Select_ByCategory(){}
    Select_ByCategory(){}
    
    virtual bool select(int row) const{
       return Rows[row];
    }

    virtual int get_rows_size() const{
       return size; 
    } 
    
};

class Select_Finished: public Select{
protected:
    int column;
    bool* Rows;
    int size;
    
public:
    ~Select_Finished(){}
    Select_Finished(){}
    
    virtual bool select(int row) const{
       return Rows[row];
    }

    virtual int get_rows_size() const{
       return size; 
    } 
    
};

class Select_Unfinished: public Select{
protected:
    int column;
    bool* Rows;
    int size;
    
public:
    ~Select_Unfinished(){}
    Select_Unfinished(){}
    
    virtual bool select(int row) const{
       return Rows[row];
    }

    virtual int get_rows_size() const{
       return size; 
    } 
    
};
