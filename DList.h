/*
Author: Placido Macosso && Douglas Raymond 
Last Revised Date: 2016/03/04

This is the course array class, 
here is where the taks dealing with the array of courses will be implemented
*/
#include "Course.h"

#ifndef DLIST_H
#define DLIST_H

class DList {
 class Node //Giving DList access
 {
  friend class DList;
  private:
   Node* next;
   Node* prev;//doubly linked
   Course* data; 
 };
  public:
   DList();
   ~DList();
   Course* getCourse(int);
   void add(Course*);
   void remove(Course*);
   Course* find(string);
   string incFormat();
   string decFormat();
   int  getSize();


  private:
   Node* head;
   int size;
};

#endif
