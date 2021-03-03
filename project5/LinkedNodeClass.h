

#ifndef LinkedNodeClass_h
#define LinkedNodeClass_h

//  LinkedNodeClass.h
//  project4A


template < class T >
class LinkedNodeClass
{
private:
  LinkedNodeClass* prevNode;
  T nodeVal;
  LinkedNodeClass* nextNode;
  

public:
  LinkedNodeClass<T>(
                  LinkedNodeClass *inPrev, //Address of node that comes before this one
                  const T &inVal, //Value to be contained in this node
                  LinkedNodeClass *inNext //Address of node that comes after this one
                 );
  
  T getValue() const;
  LinkedNodeClass* getNext() const;
  LinkedNodeClass* getPrev() const;
  void setNextPointerToNull();
  void setPreviousPointerToNull();
  void setBeforeAndAfterPointers();

};

#include "LinkedNodeClass.inl"

#endif /* LinkedNodeClass_h */

//The list node class will be the data type for individual nodes of
//a doubly-linked data structure.



