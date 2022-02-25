#include <iostream>
#include <string>
using namespace std;

void displaymenu(){ 
    cout << "===================================================== \n";
    cout << " \t\tMENU \t \n ";
    cout << "===================================================== \n";
    cout << " 1.Add task to task board\n";
    cout << " 2.View all task on task board\n";
    cout << " 3.Edit a task on task board\n";
    cout << " 4.Delete a task on task board\n";
    cout << " 5.Change account settings\n";
    cout << " 6.Log out\n";
}
void addTask(){
    cout << "you have selected to add a task: \n";
}

void displayTask(){
    cout << "you have selected to view all tasks: \n";
}

void editTask(){
    cout << "Select a task to edit: \n";
}

void deleteTask(){
    cout << "choose a task to delete: \n";
}

void accountSettings(){
    cout << "select a setting to change: \n";
}

void logOut(){
    cout << "you have chosen to log out\n";
}


int main(){
 
    string st[20];
    int itemcount = 0;
 
    //function to display Menu
    displaymenu();
    int option;
    string confirm;
    do{ 
        cout<<"select an option(1-6):";
        cin >> option;
        switch (option){
            case 1: addTask(); 
            break;
            case 2: displayTask();
            break;
            case 3: editTask(); 
            break;
            case 4: deleteTask(); 
            break;
            case 5: accountSettings();
            break;
            case 6: logOut();
            break;
            default: cout<<"invalid option"; 
            break;
        }
        cout << "Press y to continue:";
        cin >> confirm;
    } while (confirm == "y" || confirm == "Y");
    
    return 0;
    
}