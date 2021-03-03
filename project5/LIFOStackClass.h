/*

#ifndef LIFOStackClass_h
#define LIFOStackClass_h
#include "LinkedNodeClass.h"

//Last in first out stack class
//LIFO.h
//project4A

class LIFOStackClass
{
private:
  LinkedNodeClass* head;
  LinkedNodeClass* tail;
  
public:
  //Default Constructor initializes to empty stack
  LIFOStackClass();
  
  //Inserts the value provided (newItem) into the stack.
  void push(const int &newItem);
  
  //Attempts to take the next item out of the stack. If the
  //stack is empty, the function returns false and the state
  //of the reference parameter (outItem) is undefined. If the
  //stack is not empty, the function returns true and outItem
  //becomes a copy of the next item in the stack, which is
  //removed from the data structure.
  bool pop(int &outItem);
  
  //Prints out the contents of the stack
  void print() const;
  
  //Clears the stack to an empty state w/o mem leaks
  void clear();
};

#endif /* LIFOStackClass_h */
