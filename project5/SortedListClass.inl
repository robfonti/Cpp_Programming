

#include <stdio.h>
#include "SortedListClass.h"
#include <iostream>
#include "LinkedNodeClass.h"


//  SortedListClass.cpp
//  project4A


using namespace std;

//Copy ctr makes deep copy
template < class T >
SortedListClass< T >::SortedListClass(const SortedListClass< T > &rhs)
{
  //need to use sorted list class overloaded operator.
  operator=(rhs);
}

//Overloaded =

template < class T >
void SortedListClass< T >:: operator=(const SortedListClass< T > &rhs)
{

  //create all new nodes..same values new pointers.
  LinkedNodeClass< T >* temp;
  temp = rhs.head;
 
  LinkedNodeClass<T> *newHead;
  
  //for every node in list, dynamically allocate a new node and set it's pointers.  Just pull the value
  
  LinkedNodeClass<T>* prevNode;
  prevNode = NULL;
  LinkedNodeClass< T >* newNode;
  
  int counter = 0;

  //visit every node and pull value
  while(temp != NULL)
  {
    newNode = new LinkedNodeClass< T >(prevNode,temp->getValue(),NULL);
    prevNode = newNode;
    //temp initialized to head,runs through our existing list
    T val = temp->getValue();
    val = newNode->getValue();
    //set new node's pointers
    newNode->setBeforeAndAfterPointers();
    temp = temp->getNext();
    if(counter == 0)
    {
      newHead = newNode;
    }
    counter ++;
  }
  
  head = newHead;
  tail = prevNode;
}

template < class T >
SortedListClass< T >::SortedListClass()
{
  head = NULL;
  tail = NULL;
}



template < class T >
void SortedListClass < T >:: insertValue(const T &valToInsert)
{
  
  //First check to see if list is empty
  //If list is empty, head and tail will be the same after node insertion
  if(head == NULL)
  {
    LinkedNodeClass< T >* newNode = new LinkedNodeClass< T >(NULL, valToInsert, NULL);
    head = newNode;
    tail = newNode;
  }
  
  else //list is not empty
  {
    int testValue = head->getValue();
    LinkedNodeClass< T >* temp;
    temp = head;
  
    while(valToInsert >= testValue && temp != NULL)  //or equal to b/c we still want loop to run if vals are equal
      {
        if(temp != NULL)
        {
          temp = temp->getNext(); //update temp to next node
          if(temp!=NULL)
          {
            testValue = temp->getValue();
          }
         }
       }
  
      if(temp == NULL)
      {
        LinkedNodeClass< T >* newNode = new LinkedNodeClass< T >(tail,valToInsert,NULL);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
      }
     else
     {
       if(temp->getPrev() != NULL)
       {
         LinkedNodeClass< T >* newNode = new LinkedNodeClass< T >(temp->getPrev(),valToInsert,temp);
         newNode->setBeforeAndAfterPointers();
       }
       else
       {
         LinkedNodeClass< T >* newNode =  new LinkedNodeClass< T >(NULL,valToInsert,temp);
         newNode->setBeforeAndAfterPointers();
         head = newNode;
       }
     }
   }
}

template < class T >
void SortedListClass< T >::clear()
{
  LinkedNodeClass< T >* temp;
  
  while(tail != NULL)
  {
    temp = head;
    if(temp!=NULL)
    {
      head = temp->getNext();
      delete temp;
    }
    else
    {
      tail = NULL;
      delete temp;
    }
  }
}

//Prints list from lowest to highest node vals
template < class T >
void SortedListClass< T >::printForward() const
{
  LinkedNodeClass< T >* temp;
  bool atEnd = false;
  temp = head;
  cout<<"Forward List Contents Follow: "<<endl;
  if(temp == NULL)
  {
    atEnd = true;
    cout<<"  End Of List Contents"<<endl;
  }
  while (atEnd == false)
  {
    std::cout <<"  "<<temp->getValue()<<endl;
    temp = temp->getNext();
    if(temp == NULL)
    {
      atEnd = true;
    }
  }
  std::cout << std::endl;
}

//Prints list from highest to lowest node vals
template < class T >
void SortedListClass< T >::printBackward() const
{
  LinkedNodeClass< T >* temp;
  bool atEnd = false;
  temp = tail;
  cout<<"Backward List Contents Follow:  "<<endl;
  if (temp == NULL)
  {
    atEnd = true;
    cout<<"  End Of List Contents"<<endl;
  }
  while(atEnd == false)
  {
    cout<<"  "<<temp->getValue()<<endl;
    temp = temp->getPrev();
    if(temp == NULL)
    {
      atEnd = true;
    }
  }
  cout<<endl;
}
template < class T >
bool SortedListClass< T >:: removeFront(T &theVal)
{
  LinkedNodeClass< T >* temp;
  temp = head;
  if(temp != NULL)
  {
    theVal = temp->getValue();
    head = temp->getNext();
    head->setPreviousPointerToNull();
    delete temp;
    head->setBeforeAndAfterPointers();
  
    return true;
  }
  
  else
  {
    return false;
  }
}

template < class T >
bool SortedListClass< T >:: removeLast(T &theVal)
{
  LinkedNodeClass< T >* temp;
  temp = tail;
  if(temp != NULL)
  {
    theVal = temp->getValue();
    tail = tail->getPrev();
    tail->setNextPointerToNull();
    delete temp;
    tail->setBeforeAndAfterPointers();
    
    return true;
  }
  else
  {
    return false;
  }
}

//Returns number of elements in list
template < class T >
T SortedListClass< T >::getNumElems() const
{
  int counter = 0;
  LinkedNodeClass< T >* temp;
  temp = head;
  while(temp != NULL)
  {
    counter++;
    temp = temp->getNext();
  }
  
  return counter;
}

template < class T >
bool SortedListClass< T >:: getElemAtIndex(const int Index, T &outVal)
{
  int counter = 0;  //to determine if index exceeds # of nodes
  LinkedNodeClass< T >* temp;
  temp = head;
  
  while(temp != NULL)
  {
    counter++;
    temp = temp->getNext();
  }
  
  temp = head;
  if(Index<counter)
  {
    for(int i=0; i<Index; i++)
    {
      temp = temp->getNext();
    }
    outVal = temp->getValue();
    return true;
  }
  else
  {
    return false;
  }
}

