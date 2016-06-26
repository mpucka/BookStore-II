#include <iostream>
#include <string>
#include "DList.h"
#include "sstream"

//the DList constructor
DList::DList():head(0){
  size = 0;
}

//Destructor to dynamically deallocate and clean
DList::~DList()
{
   Node* currNode=head;
   Node* nextNode=0;

   while (currNode!=0){
       nextNode = currNode->next;
       delete currNode->data;
       delete currNode;
       currNode = nextNode;
 }
}

//function to find the specific code
Course* DList::find(string code)
{
   Node* currNode = head;
    
   while (currNode != 0)
   {
     if (currNode->data->getCode()==code){
         return currNode->data;

   }
   currNode=currNode->next;
   }
   
   return 0;
  
}

void DList::add(Course* c)
{
   //Creating a new node
   Node* newNodeC = new Node; //dyanamically allocating new course node
   newNodeC->data=c;
   newNodeC->next=0;
   newNodeC->prev=0;

   //pointers placeholder
   Node* currNode=head;
   Node* prevNode=0;
   size++;

   //if list is empty
   if (head==0)
   {
    head = newNodeC;
    //cout<<"head is the adress of the new course node\n";
    return;
   }

   while(currNode!=0)
   { //check if the given course code is less than the current code
     if(c->getCode() < currNode->data->getCode())
      ////we found the spot to add the new course
        break;
   
    //advance the placeholders so there's no infinite loop
    prevNode=currNode;
    currNode=currNode->next;
   }
   
  //adding to the front  
   if (prevNode==0) //redundant
   { 
    head=newNodeC;
   }
   else
   {
   //adding to the middle and back
          if (currNode == 0)	//adding to back
	  {
		  prevNode->next = newNodeC;
	  }
	  else                 //adding to middle
	  {
		  prevNode->next = newNodeC;
		  currNode->prev = newNodeC;
	  }

   }//the general case
   newNodeC->next= currNode; 
   newNodeC->prev= prevNode;  
}

void DList::remove(Course* c)
{

   Node* currNode=head;
   size--; 

   while (currNode !=0){
       if (currNode->data->getCode() == c->getCode())
           break;
   
   //prevNode = currNode;
   currNode = currNode->next; 
 }    

   //Removing from beggining
   if (currNode==head){
       head=currNode->next;
       if(head!=0)
          head->prev=0;//setting a head with prev as null
       delete currNode->data;
       delete currNode;
       return;
  }

    //Removing from the end
   if (currNode->next==0){
       currNode->prev->next= 0;
       delete currNode->data;
       delete currNode;
       return;
  }
   //General case
   currNode->next->prev=currNode->prev;
   currNode->prev->next=currNode->next; 
   delete currNode;
}

//function to get the specific course
Course* DList::getCourse(int i)
{
  Node* currNode = head;
  int count = 0;

  while (currNode!=0 && count < i)
  {
    count++;
    currNode=currNode->next;
  }

  return currNode->data;
}


int DList::getSize() {return size;}


//function to print in the increasing format
string DList::incFormat()
{
   Node* currNode = head;
   string str="";
 
   if (head==0)
   { 
     cout <<"No textbooks available \n";

   }

   while (currNode !=0){
      Course* c = currNode->data;
      int enrol = c->getEnrol();
      string str2;
      stringstream ss;
      ss << enrol;
      str2 = ss.str();
      str +="\nCourse:     " + c->getCode() + "  " + c->getName()+"  ";
      str +="\nInstructor:  " + c->getInstr() + "  "; 
      str += "\nEnrolment:  " + str2 + "  ";
      str +="\nTextbooks:  ";
      currNode = currNode->next;
	 }
   return str;
}

//function to print in the decreasing format
string DList::decFormat()
{
   Node* currNode = head;
   Node* prevNode = 0;

   string str = "";

   while (currNode != 0)
   {
      prevNode = currNode;
      currNode = currNode->next;
   }

   currNode = prevNode;

   while (currNode != 0)
   {
      Course* c = currNode->data;
      int enrol = c->getEnrol();
      string str2;
      stringstream ss;
      ss << enrol;
      str2 = ss.str();
      str += "\nCourse:     "  +  c->getCode()  + "  " + c->getName() + "  ";
      str += "\nInstructor:  " +  c->getInstr() + "  ";
      str += "\nEnrolment:  "  +  str2 + "  ";
      str += "\nTextbooks:  ";
      currNode = currNode->prev;
}

  return str;
}
