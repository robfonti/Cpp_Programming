

#include <stdio.h>
#include "LinkedNodeClass.h"
#include <iostream>

//  LinkedNodeClass.cpp
//  project4A


template < class T >
LinkedNodeClass< T >:: LinkedNodeClass(LinkedNodeClass* inPrev,
                                           const T &inVal,
                                           LinkedNodeClass* inNext)
{
  prevNode = inPrev;
  nextNode = inNext;
  nodeVal = inVal;
}

template< class T >
T LinkedNodeClass< T >:: getValue() const
{
    return nodeVal;
}

template< class T >
LinkedNodeClass< T >* LinkedNodeClass< T >:: getNext() const
{
  if(nextNode != NULL)
  {
    return nextNode;
  }
  else
  {
    return NULL;
  }
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >:: getPrev() const
{
  return prevNode;
}

template< class T >
void  LinkedNodeClass< T >::setNextPointerToNull()
{
  nextNode = NULL;
}

template< class T >
void LinkedNodeClass< T >::setPreviousPointerToNull()
{
  prevNode = NULL;
}


//Sets pointers to appropriate locations
//useful after adding/deleting node
//conditional to avoid seg faults

template< class T >
void LinkedNodeClass< T >::setBeforeAndAfterPointers()
{
  if (prevNode != NULL)
  {
    prevNode->nextNode = this;
  }
 
  if(nextNode != NULL)
  {
    nextNode->prevNode = this;
  }
}

