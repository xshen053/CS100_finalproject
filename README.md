# Task Scheduler
 
  Authors: [Xiaxi Shen](https://github.com/xshen053), [Han Yu](https://github.com/BFLion), [Vibhu Sangar Vinoth Kannan](https://github.com/VibhuSVK), [Justin Fernandez](https://github.com/j9950)

## Project Description

    * Designing and developing a task scheduler is interesting to us because most of us use some task scheduler software nowadays, such as Microsoft Todo. Therefore, we are curious about the mechanism of how to create a task scheduler. What’s more, the function of the present task scheduler is limited. So if we want to add some new function or features, we can only do them ourselves. Realizing such a task scheduler can not only help us solidify what we learned in CS100, but can also help us improve our ability of time management.
  
 
The languages/tools/technologies we used.
    * [C++](https://www.cplusplus.com/) - Using this middle level language, we will create a console interface in which the client has the ability to input commands from the keyboard to utilize the system while also displaying the inputs on screen.
    * [Vscode](https://code.visualstudio.com/) - We will use VScode to edit files like Readme.
    * [Visual Studio](https://cmake.org/) - We will use Visual Studio as an ide to develop the software.
    * [Git](https://git-scm.com/) - We will use Git as the version control tool to coordinate work, keep track of changes in our code, and keep our project up to date. 
    * [Valgrind](https://valgrind.org/) - We will use the Valgrind framework to construct dynamic analysis tools to help us with memory debugging and detecting memory leaks.


 > * What will be the input/output of your project? What are the features that the project provides?
 >   * The input of our project would be task names, task descriptions, category labels, dates and times. Task names and descriptions will be anything the user enters, and user can also add category labels.
 >   * The output of our project would  be a list ordered by date and priority displayed for the user to review.



## Class Diagram
![avatar](https://github.com/cs100/final-project-xshen053-hyu146-jfern025-vvino005/raw/master/uml.PNG)

## Diagram description

By far, we use composite pattern to implment our task. This is implemented in the construction of the Project and the Tasks class being subclasses to the Abstract Class Component. 
   


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with a reader (using Calendly). Your entire team must be present. This meeting will occur on week 8 but NOT during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
