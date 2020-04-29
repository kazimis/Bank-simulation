/*
  Node.h
 * Class Definition: Generic Node of a singly linked list (template)
 *                   Designed and implemented as a non-ADT.
 *
 * Created on:April 29, 2020
 * Author:Sarajuddin Kazimi
 */

#pragma once
#include <cstdio>  // Needed for NULL
using namespace std;

template <class T>
class Node {
  public:
    T data;
    Node<T>* next;


    //Constructors
    //default Constructor
    //Description: create a node with next node = NULL
    Node();

    // parametarized constructors

    //Description:set data to aData and next node = NULL
    Node(T aData);

    //Description:set data to aData and next node = next
    Node(T aData, Node<T>* next);
}; // Node


//Default Constructor
//Description: create a node with next node = NULL
template <class T>
Node<T>::Node():next(NULL){
}

//Description:set data to aData and next node = NULL
//Post: data = aData, head and tail = NULL
template <class T>
Node<T>::Node(T aData ):data(aData),next(NULL){

}
//Description:set data to aData and next node = next
//Post: data = aData, next node = next
template <class T>
Node<T>::Node(T aData, Node<T>* next):data(aData),next(next){

}
