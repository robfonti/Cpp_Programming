
#ifndef FIFOQueueClass_h
#define FIFOQueueClass_h
#include "LinkedNodeClass.h"

//  FIFOQueueClass.h
//  project4A

template <class T>
class FIFOQueueClass
{
private:
  LinkedNodeClass< T >* head;
  LinkedNodeClass< T >* tail;
  
public:
  //Default Constructor. Initialized empty queue
  FIFOQueueClass();
  
  //Inserts the value provided (newItem) into the queue.
  void enqueue(const T &newItem);
  
  //Attempts to take the next item out of the queue. If the
  //queue is empty, the function returns false and the state
  //of the reference parameter (outItem) is undefined. If the
  //queue is not empty, the function returns true and outItem
  //becomes a copy of the next item in the queue, which is
  //removed from the data structure.
  bool dequeue(T &outItem);
  
  //Prints out the contents of the queue
  void print() const;
  
  //Clears the queue to an empty state without mem leaks
  void clear();
  
};

#include "FIFOQueueClass.inl"
#endif /* FIFOQueueClass_h */
