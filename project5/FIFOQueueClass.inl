
#include <stdio.h>
#include "FIFOQueueClass.h"
#include <iostream>

//  FIFOQueueClass.cpp
//  project4A

using namespace std;

template< class T >
FIFOQueueClass< T >:: FIFOQueueClass()
{
  head = NULL;
  tail = NULL;
}

template< class T >
void FIFOQueueClass< T >:: enqueue(const T &newItem)  //insert new item at head
{
  
 if(head == NULL)
    {
      LinkedNodeClass< T >* newNode = new LinkedNodeClass< T >(NULL,newItem,NULL);
      head = newNode;
      tail = newNode;
    }
  
  else
  {
    tail = new LinkedNodeClass< T >(tail,newItem,NULL);
    tail->setBeforeAndAfterPointers();
  }
}

template< class T >
bool FIFOQueueClass< T >:: dequeue(T &outItem)
{
  LinkedNodeClass< T >* temp = head;
  
  if(temp != NULL)
  {
    outItem = head->getValue();
    head = temp->getNext();
    delete temp;
    
    if(head!= NULL)  //making sure we avoid seg faults
    {
      head->setBeforeAndAfterPointers();
    }
    
    return true;
  }
  
  else
  {
    return false;
  }
}

template< class T >
void FIFOQueueClass< T >:: print() const
{
  LinkedNodeClass< T >* temp = head;
  
 while(temp != NULL)
 {
   cout<< temp->getValue()<<" ";
   temp = temp->getNext();
 }
  cout<<endl;
}

//clears queue

template< class T >
void FIFOQueueClass< T >:: clear()
{
  LinkedNodeClass< T >* temp;
  
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







