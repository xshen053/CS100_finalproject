# Task Scheduler
 
  Authors: [Xiaxi Shen](https://github.com/xshen053), [Han Yu](https://github.com/BFLion), [Vibhu Sangar Vinoth Kannan](https://github.com/VibhuSVK), [Justin Fernandez](https://github.com/j9950)

## Project Description
* Designing and developing a task scheduler is interesting to us because most of us use some task scheduler software nowadays, such as Microsoft Todo. Therefore, we are curious about the mechanism of how to create a task scheduler. What’s more, the function of the present task scheduler is limited. So if we want to add some new function or features, we can only do them ourselves. Realizing such a task scheduler can not only help us solidify what we learned in CS100, but can also help us improve our ability of time management.
  
 
* The languages/tools/technologies we used.
    * [C++](https://www.cplusplus.com/) - Using this middle level language, we will create a console interface in which the client has the ability to input commands from the keyboard to utilize the system while also displaying the inputs on screen.
    
    * [Vscode](https://code.visualstudio.com/) - We will use VScode to edit files like Readme.
    
    * [Visual Studio](https://cmake.org/) - We will use Visual Studio as an ide to develop the software.
    
    * [Git](https://git-scm.com/) - We will use Git as the version control tool to coordinate work, keep track of changes in our code, and keep our project up to date. 
    
    * [Valgrind](https://valgrind.org/) - We will use the Valgrind framework to construct dynamic analysis tools to help us with memory debugging and detecting memory leaks.



 * The input of our project would be task names, task descriptions, category labels, dates and times. Task names and descriptions will be anything the user enters, and user can also add category labels.
 * The output of our project would  be a list ordered by date and priority displayed for the user to review.



## Class Diagram
![avatar](https://github.com/cs100/final-project-xshen053-hyu146-jfern025-vvino005/raw/master/originalUML.png)

## Diagram description

By far, we use composite pattern to implment our task. This is implemented in the construction of the Project and the Tasks class being subclasses to the Abstract Class Component. 
   


 

