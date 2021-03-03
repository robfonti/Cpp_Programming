
/*

#include <stdio.h>
#include "LIFOStackClass.h"
#include <iostream>

//  LIFOStackClass.cpp
//  project4A

using namespace std;

LIFOStackClass:: LIFOStackClass()
{
  head = NULL;
  tail = NULL;
}

//Adds to stack
void LIFOStackClass:: push(const int &newItem)
{
  if(head == NULL)
  {
    LinkedNodeClass* newNode = new LinkedNodeClass(NULL,newItem,NULL);
    head = newNode;
    tail = newNode;
  }
  
  else
  {
    tail = new LinkedNodeClass(tail,newItem,NULL);
    tail->setBeforeAndAfterPointers();
  }
}

//we pop from the top of the stack

bool LIFOStackClass:: pop(int &outItem)
{
  LinkedNodeClass* temp = tail;
  temp = tail;
  if(temp != NULL)
  {
    outItem = temp->getValue();
    tail = tail->getPrev();
    if (tail != NULL)
    {
      tail->setNextPointerToNull();
    }
    delete temp;
    if(tail != NULL)
    {
      tail->setBeforeAndAfterPointers();
    }
    
    return true;
  }
  else
  {
    return false;
  }
}


void LIFOStackClass:: print() const
{
  LinkedNodeClass* temp = head;
  
  while(temp != NULL)
  {
    cout<< temp->getValue()<<" ";
    temp = temp->getNext();
  }
  cout<<endl;
}

void LIFOStackClass:: clear()
{
  LinkedNodeClass* temp=head;
  
  while(head != NULL)
  {
    temp = head;
    
    if(temp!=NULL)
    {
      head = temp->getNext();
      if(temp == NULL)
      {
        delete head;
      }
    }
    else
    {
      tail = NULL;
      delete temp;
    }
  }
}

 */
