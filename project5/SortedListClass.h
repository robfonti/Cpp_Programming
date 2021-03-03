
#include "LinkedNodeClass.h"

#ifndef SortedListClass_h
#define SortedListClass_h

//  SortedListClass.h
//  project4A

template< class T >
class SortedListClass
{
private:
  LinkedNodeClass< T >* head;
  LinkedNodeClass< T >* tail;

public:
  //Default Constructor. Will properly initialize a list to
  //be an empty list, to which values can be added.
  SortedListClass();
  
  //Eventually will add copy constructor
  
  SortedListClass(const SortedListClass< T > &rhs);
  
  //Clears the list to an empty state w/o leaks
  void clear();
  
  //Allows the user to insert a value into the list. If the node value
  //being inserted is the same as another node in the list
  //the new node is placed after the older one
  void insertValue(const T &valToInsert);
  
  void printForward() const;
  void printBackward() const;
  
  //Removes the front item from the list and returns the value that
  //was contained in it via the reference parameter. If the list
  //was empty, the function returns false to indicate failure, and
  //the contents of the reference parameter upon return is undefined.
  //If the list was not empty and the first item was successfully
  //removed, true is returned, and the reference parameter will
  //be set to the item that was removed.
  bool removeFront(T &theVal);
  
  //same concept as removeFront, but from the back
  bool removeLast(T &theVal);
  
  //Returns the number of nodes contained in the list.
  T getNumElems() const;
  
  //Provides the value stored in the node at index provided in the
  //0-based "index" parameter. If the index is out of range, then outVal
  //remains unchanged and false is returned. Otherwise, the function
  //returns true, and the reference parameter outVal will contain
  //a copy of the value at that location.
  bool getElemAtIndex(const int index,T &outVal);
  
  //Overload the = operator
  void operator=(const SortedListClass< T > &rhs);
  
  
};

#include "SortedListClass.inl"
#endif /* SortedListClass_h */
