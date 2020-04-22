/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: April 2020
 *
 */

#pragma once
#include<iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"
#include <cstdio>
using namespace std;



template <class T>
class PriorityQueue {

    private:
        // singly-linked list
        Node<T>* head;
        int len;

    public:

        // Desc: Default Constructor. (O(1)). Intitialzes head to NULL and len to zero.
        PriorityQueue();


        // Desc: Copy Constructor. (O(N))
        PriorityQueue(const PriorityQueue& rhs);


        // Desc: Destructor. (O(N))
        //Post: All allocated memory by the class is released.
        ~PriorityQueue();


        // Desc: Returns true if Priority Queue empty. (O(1))
        bool isEmpty() const;


        // Desc: Returns length of the Priority Queue. (O(1))
        int getLength() const;


        // Desc: Inserts x in sorted order. (O(N))
        //  Pre: Priority Queue is sorted.
        // Post: Priority Queue remains sorted. len is increased by one.
        void enqueue(const T& x);


        // Desc: Removes the element with "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        //Post:  length is decreased by one. PriorityQueue remains sorted
        void dequeue() throw(EmptyDataCollectionException);


        // Desc: Returns the element with the "highest" priority. (O(1))
        //  Pre: Priority Queue not empty.
        //       Throws EmptyDataCollectionException if Priority Queue empty.
        // Post: Priority Queue is unchanged.
        T& peek() const throw(EmptyDataCollectionException);



        //Description: 'Inline function. Prints the content of PriorityQueue P
        friend ostream & operator<< (ostream & os, const PriorityQueue & P){
            //freind function to class. We can get data directly.
            Node<T>* current= P.head;
            while(current){
              os<<current->data<<endl;
              current = current->next;
            }
            return os;
        }

}; // PriorityQueue




// Desc: Default Constructor. (O(1)). Intitialzes head to NULL and len to zero.
template <class T>
PriorityQueue  <T>::PriorityQueue():head(NULL),len(0){
}


// Desc: Copy Constructor. (O(N))
template <class T>
PriorityQueue <T>::PriorityQueue(const PriorityQueue& rhs){
    //if PriorityQueue rhs is empty
    if(rhs.head == NULL){
        head = NULL;
        len = 0;
    //if PriorityQueue rhs is not empty copy the content
    }else{
        //copy the head
        head = new Node <T>(rhs.head->data,rhs.head->next);
        Node <T>* current = head;//new PriorityQueue node tracker
        Node <T>* nextNode = rhs.head->next;//rhs node tracker
        len = rhs.len;
        //copy the rest.
        while(nextNode){
            current->next = new Node <T>(nextNode->data,nextNode->next);
            current = current->next;
            nextNode = nextNode->next;
        }
    }
}


// Desc: Destructor. (O(N))
//Post: All allocated memory by the class is released.
template <class T>
PriorityQueue<T>::~PriorityQueue(){
    //traverse till the end of list
    while(head){
        Node <T>* temp = head->next;
        delete head;
        head = temp;
    }
    len = 0;
}


// Desc: Returns true if Priority Queue empty. (O(1))
template <class T>
bool PriorityQueue<T>::isEmpty() const{
    return(head==NULL);
}



// Desc: Returns length of the Priority Queue. (O(1))
template <class T>
int PriorityQueue <T>::getLength() const{
    return len;
}



// Desc: Inserts x in sorted order. (O(N))
//  Pre: Priority Queue is sorted.
// Post: Priority Queue remains sorted.len is increased by one.
template <class T>
void PriorityQueue <T>::enqueue(const T& x){
    //if PriorityQueue is empty
    if(head == NULL){
        head = new Node<T>(x, NULL);
    //if not empty
    }else{
        //node trackers
        Node <T>* current = head;
        Node <T>* prevNode = NULL;
        bool notFound = true;

        //traverse the list
        while(current && notFound){
            //if appropriate slot found for x
            if(x < current->data){
                //at the beginning
                if(current == head){
                    head = new Node<T>(x,current);
                //add in the middle
                }else{
                    prevNode->next = new Node <T> (x,current);
                }
                notFound =false;
            }
            prevNode = current;
            current=current->next;
        }
        //if the end of list is reached then add the end of list.
        if(notFound){
            prevNode->next = new Node <T> (x, NULL);
        }
    }
    len++;
}


// Desc: Removes the element with "highest" priority. (O(1))
//  Pre: Priority Queue not empty.
//       Throws EmptyDataCollectionException if Priority Queue empty.
//Post:  length is decreased by one. PriorityQueue remains sorted
template <class T>
void PriorityQueue <T>::dequeue() throw(EmptyDataCollectionException){
    //trhow exception
    if(head == NULL){
        throw EmptyDataCollectionException("PriorityQueue is empty");
    }
    Node <T> * temp = head->next;
    delete head;
    head = temp;
    len--;

}



// Desc: Returns the element with the "highest" priority. (O(1))
//  Pre: Priority Queue not empty.
//       Throws EmptyDataCollectionException if Priority Queue empty.
// Post: Priority Queue is unchanged.
template <class T>
T& PriorityQueue<T>:: peek() const throw(EmptyDataCollectionException){
    //thrhow exception
     if(head == NULL){
        throw EmptyDataCollectionException("PriorityQueue is empty");
     }
    return head->data;
}
