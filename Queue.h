
/*Queue.h

* Class Definition: Generic Design and implementaion of an ADT queue using a circular array.
* Class Invariant:  FIFO order


* Created on:April 20, 2020
* Author:Sarajuddin Kazimi
*/
#pragma once
#include "EmptyDataCollectionException.h"
#include <cstdio>
#include<iostream>
using namespace std;

template <class T>
class Queue {
  private:
    static unsigned const INITIAL_SIZE = 6;
    T* arr;
    unsigned size;        // number of elements in the queue
    unsigned capacity;    // number of slots in the array
    unsigned frontindex;  // index the topmost element
    unsigned backindex;   // index where the next element will be placed

  public:

    // Desc:  Constructor(O(1))
	  //Post: size is zero, capacity=INITIALZ_SIZE,frontindex = backindex=0
    Queue();


    // Desc: Returns true if Queue is empty. (O(1))
    bool isEmpty() const;


    // Desc: Inserts x at the "back" of this Queue. (O(1))
    //Post: size of queue incremented by one. Capacity is doubled if queue is full
    //      and backindex and frontindex are updated. backindex is incremented.
    void enqueue(const T& x);


    // Desc: Removes the element at the "front". (O(1))
    //  Pre: Queue not empty.
    //       Throws EmptyDataCollectionException if Queue empty.
    //Post: size is decremented by one, frontmost element is removed.the capacity
    //      is halved when array is less than 1/4 full and frontindex, frontindex
    //      and backindex.frontindex is incremented.
    void dequeue() throw(EmptyDataCollectionException);


    // Desc: Returns the element at the "front". (O(1))
    //  Pre: Queue not empty.
    //       Throws EmptyDataCollectionException if Queue empty.
    // Post: Queue is unchanged.
    T& peek() const throw(EmptyDataCollectionException);


    //Destructor
    //Description: Delete the allocated memory and all memory is released.
    ~Queue();


    //Description: Helper function. Prints the content of a queue
    friend ostream & operator<< (ostream & os, const Queue & aQueue){
      	//freind function to class. We can get data directly.
        unsigned start = aQueue.frontindex;//starting index
        unsigned counter = 0;//counter to count number of elements
        while(counter<aQueue.size){
          os<<aQueue.arr[start]<<endl;
          start = (start+1)%aQueue.capacity;
          counter++;
        }
      	return os;

    }

};





// Desc:  Constructor(O(1))
//Post: size is zero, capacity=INITIALZ_SIZE,frontindex = backindex=0
template <class T>
Queue<T>::Queue():size(0),capacity(INITIAL_SIZE),frontindex(0),backindex(0),arr(new T [INITIAL_SIZE]){
} // constructor



// Desc: Returns true if Queue is empty. (O(1))
template <class T>
bool Queue<T>::isEmpty() const {
  return size == 0;
} // isEmpty



// Desc: Inserts x at the "back" of this Queue. (O(1))
//Post: size of queue incremented by one. Capacity is doubled if queue is full
//      and backindex and frontindex are updated. backindex is incremented.
template <class T>
void Queue<T>::enqueue(const T& x) {
    size++;
    //if array is full.
    if(size>capacity){
        T* newArr = new T[capacity*2];

        //index to traverse the arr and newArr
        unsigned indexArr = frontindex;
        unsigned indexnewArr =0;

        //copy the elements from old array to new one
        while(indexnewArr<capacity){
            newArr[indexnewArr ++] = arr[indexArr++];
            if(indexArr==capacity){indexArr=0;}//check bound
        }
        //delete old array and update arr
        delete[] arr;
        arr = newArr;

        //update backindex and front index;
        backindex=indexnewArr;
        frontindex = 0;

        //double the capacity
        capacity = capacity*2;
    }
    arr[backindex] = x;

    //increment back index and check the bound(make it circular)
    if(++backindex == capacity){
        backindex=0;
    }
} // enqueue



// Desc: Removes the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
//Post: size is decremented by one, frontmost element is removed.the capacity
//      is halved when array is less than 1/4 full and frontindex, frontindex
//      and backindex.frontindex is incremented.
template <class T>
void Queue<T>::dequeue() throw(EmptyDataCollectionException) {
      //throw exception if empty
      if(size ==0){
          throw EmptyDataCollectionException("Queue is empty");
      }
      size--;//size is decremented
      //if array size is 1/4 full allocated new array
      if(capacity > INITIAL_SIZE && size < capacity/4){
        T* newArr = new T[capacity/2];

        //index to traverse the arr and newArr
        int indexArr = frontindex;
        int indexnewArr =0;

        //copy the elements from old array to new one
        while(indexnewArr < size+1){
            newArr[indexnewArr ++] = arr[indexArr++];
            if(indexArr==capacity){indexArr=0;}
        }
        //delete old array
        delete[] arr;
        //update arr pointer
        arr = newArr;
        //update backindex and front index
        frontindex =0 ;
        backindex=indexnewArr;
        capacity = capacity/2;
    }
    //check the bound of array(make it cicular)
    if(++frontindex == capacity){
      frontindex=0;
    }
} // dequeue



// Desc: Returns the element at the "front". (O(1))
//  Pre: Queue not empty.
//       Throws EmptyDataCollectionException if Queue empty.
// Post: Queue is unchanged.

template <class T>
T& Queue<T>::peek() const throw(EmptyDataCollectionException) {
    //throw exception if empty
    if(size ==0){
        throw EmptyDataCollectionException("Queue is empty");
    }
      return arr[frontindex];
} // peek

//Destructor
//Description: Delete the allocated memory and all memory is released.
template <class T>
Queue<T>::~Queue(){
  delete[] arr;
}
