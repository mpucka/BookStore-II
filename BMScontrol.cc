/*
Author: Placido Macosso
Last Date: 2016/02/10

This is the control class, here is where all the operations will be made

*/

#include <iostream>
#include "BMScontrol.h"

using namespace std;

//In this constructor the view, books and course will be dynamically allocated 
BMScontrol::BMScontrol()
{
	view =    new UImanager();
	courses = new DList();
        books =   new BookArray();
}

//In this destructor the view, books and course will be deallocated 
BMScontrol::~BMScontrol()
{

  delete view;
  delete courses;
  delete books;
}

void BMScontrol::launch()
{
  int    choice;

  string code;
  Course* newCourse = 0;

  while (1) {
    choice = -1;
    code   =  "";
    view->mainMenu(&choice);
    if (choice == 0) {
      break;
    }
    //Adding the courses
    else if (choice == 1) {
      
     // initializing the course object 
      //Course* newCourse = 0;

        view->getCourseData(&newCourse);
        courses->add(newCourse);

    }
    //printing the courses
    else if (choice == 2) {
        view->printCourses(courses); //remove the & operator because is already a pointer
    }

    else if (choice == 3) {//deleting a course
         view->getCourseCode(code);

        if (courses->find(code)){//checking if it can find the course code
          Course* c = courses->find(code);
          courses->remove(c);
   }

  }
    //Adding a text book
    else if (choice == 4) {
    
    //inittializing the book object
         Book* newBook= 0; 
         string n;

         view->getCourseCode(code);
    
         if (courses->find(code)){//checking if it can find the course code
         view->addTextbook(&newBook);
         Course* c = courses->find(code);
         c->addBook(newBook);
    }
    else 
       cout<<"Course not found\n";

    }
    //Printing the textbooks
    else if (choice == 5) {
         string n;

         view->getCourseCode(code);
    
        if (courses->find(code)){
            Course* c = courses->find(code);
            view->printCourseBook(c);
    }
        else 
            cout<<"Course not found\n";
    }
 
    view->pause();
  }
}
