/*
Author: Placido Macosso
Last Revised Date: 2016/02/10

This is the Course class, 
here is where all the tasks to get the course information will be implemented
*/

#include "Course.h"

Course::Course(string s, string nu, string na, string i, int e)
{
   subj  = s;
   num   = nu;
   name  = na;
   instr = i;
   enrol = e;
}

Course::~Course(){}

string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }
Book*  Course::getBook(int i) { return books.getBook(i); }
int    Course::getNumBooks()  { return books.getSize(); }

void   Course::addBook(Book* b)  
{ 
  books.add(b);
}
