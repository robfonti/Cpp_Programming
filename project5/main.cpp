//
//  main.cpp
//  project4A
//
//  Created by Rob Fonti on 11/12/17.
//  Copyright © 2017 Rob Fonti. All rights reserved.
//

#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"
//#include "constants.h"
//#ifndef ...."ANDREW_TEST.h"



//  main.cpp
//  project4A
//  Created by Robert Fonti from 11/10 - 11/19 2017

//This program sets a framework of data structures, namely
//1. A Sorted Doubly Linked List
//2. A queue
//3. A stack
//These data structures will prove very useful for simulation

using namespace std;

LinkedNodeClass<int>* head = NULL;

void insertAtHead(float inVal)
{
  LinkedNodeClass<int> *newNode;
  newNode = new LinkedNodeClass<int>(NULL,inVal,head);
  head = newNode;
}

void print() 
{
  LinkedNodeClass<int>* temp;
  temp = head;
  while (temp != 0)
  {
    std::cout << temp->getValue() << " ";
    temp = temp->getNext();
  }
  std::cout << std::endl;
}



int main()
{

  int NUM_VALS_TO_TEST = 10;
  
  for(int i=0; i<NUM_VALS_TO_TEST; i++)
  {
    insertAtHead(2*i);
  }
  
  print();
  
  std::cout<<"Testing value ctr"<<std::endl;
  
  //Testing sorted list
  
  SortedListClass<int> sortedList1;
  
  
  sortedList1.insertValue(23);
  sortedList1.insertValue(7);
  sortedList1.insertValue(23);
  sortedList1.insertValue(95);
  sortedList1.insertValue(27);
  sortedList1.insertValue(25);
  sortedList1.insertValue(29);
  sortedList1.insertValue(11);
  sortedList1.insertValue(16);
  sortedList1.insertValue(113);
  sortedList1.insertValue(89);
  
  
  sortedList1.printForward();
  sortedList1.printBackward();
  
  std::cout<<"Number of elements in list = "<<sortedList1.getNumElems()<<std::endl;
  int outval;
  sortedList1.getElemAtIndex(0, outval);
  std::cout<<"index 0 contains value = "<<outval<<std::endl;
  sortedList1.getElemAtIndex(3,outval);
  std::cout<<"index 3 contains value = "<<outval<<std::endl;
  sortedList1.getElemAtIndex(100,outval);
  std::cout<<"index 100 contains value = "<<outval<<std::endl;
  
  
  int theVal;
  sortedList1.removeFront(theVal);
  sortedList1.printForward();
  sortedList1.printBackward();
  
  sortedList1.getElemAtIndex(0, outval);
  std::cout<<"index 0 contains value = "<<outval<<std::endl;
  
  std::cout<<"the val = "<<theVal<<std::endl;
  
  
  sortedList1.removeLast(theVal);
  sortedList1.printForward();
  sortedList1.printBackward();
  std::cout<<"The val = "<<theVal<<std::endl;
  
  std::cout<<"Number of elements in list = "<<sortedList1.getNumElems()<<std::endl;
  
  //sortedList1.clear();
  
  //sortedList1.printForward();
  //sortedList1.printBackward();
  
  std::cout<<"Number of elements in list = "<<sortedList1.getNumElems()<<std::endl;
  
  //testing overloaded operator
  cout<<"Now testing overloaded operator."<<endl;
  SortedListClass<int> sortedList2 = sortedList1;
  cout<<"printing sorted list 1 "<<endl;
  sortedList1.printForward();
  
  cout<<"printing sorted list 2"<<endl;
  sortedList2.printForward();
  
  cout<<"Now modifying sorted list 2 and printing out both lists again"<<endl;
  sortedList2.insertValue(999);
  
  
  cout<<"printing sorted list 1 "<<endl;
  sortedList1.printForward();
  
  cout<<"printing sorted list 2"<<endl;
  sortedList2.printForward();
  
  
  
  
  //Testing queue
  
  FIFOQueueClass <int> testQueue;
  
  testQueue.enqueue(4);
  testQueue.enqueue(8);
  testQueue.enqueue(2);
  testQueue.enqueue(15);
  
  testQueue.print();
  
  int outInt;
  
  testQueue.dequeue(outInt);
  std::cout<<"outInt = "<<outInt<<std::endl;
  testQueue.print();
  
  testQueue.dequeue(outInt);
  std::cout<<"outInt = "<<outInt<<std::endl;
  testQueue.print();
  
  testQueue.dequeue(outInt);
  std::cout<<"outInt = "<<outInt<<std::endl;
  testQueue.print();
  
  testQueue.dequeue(outInt);
  std::cout<<"outInt = "<<outInt<<std::endl;
  testQueue.print();
  
  testQueue.dequeue(outInt);
  std::cout<<"outInt = "<<outInt<<std::endl;
  testQueue.print();
  
  testQueue.dequeue(outInt);
  std::cout<<"outInt = "<<outInt<<std::endl;
  testQueue.print();

  testQueue.clear();
  testQueue.print();
  
  //Testing Stack
  /*
  LIFOStackClass testStack;
  
  testStack.push(10);
  testStack.push(11);
  testStack.push(12);
  testStack.push(9);
  testStack.push(8);
  
  testStack.print();
  
  int outPop;
  
  testStack.pop(outPop);
  testStack.print();
  cout<<"outPop = "<<outPop<<endl;
  
  testStack.pop(outPop);
  testStack.print();
  cout<<"outPop = "<<outPop<<endl;
  
  testStack.pop(outPop);
  testStack.print();
  
  cout<<"outPop = "<<outPop<<endl;
  testStack.pop(outPop);
  testStack.print();
  cout<<"outPop = "<<outPop<<endl;
  testStack.pop(outPop);
  testStack.print();
  cout<<"outPop = "<<outPop<<endl;
   
  
  
  cout<<"Now Clearing Stack..."<<endl;
  testStack.clear();
  testStack.print();
  */
  
  
  
  
  return 0;
}
