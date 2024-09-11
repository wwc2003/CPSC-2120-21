/*
 * Name: William Cooper
 * Date Submitted:
 * Lab Section: 001
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List()
{
start = nullptr;
mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List()
{
    Node<T> *nodePtr = start;
    while (nodePtr != nullptr)
    {
        Node<T> *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

//Return the size of this list

template <class T>
int List<T>::size()
{
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty()
{
    return start == nullptr;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value)
{
  Node<T> * newValue = new Node<T>(value);
  newValue->next = start;
  start = newValue;
  ++mySize;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value)
{
  Node<T> * current = start;
  Node<T> * newValue = new Node<T>(value);
    if(start == nullptr)
    {
      start = new Node<T>(value);
      ++mySize;
    }
  else
    {
  while(current->next != nullptr)
    {
    current = current->next;
    }
    current->next = new Node<T>(value);
    ++mySize;
    }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{
if (j == 0) {
        insertStart(value);
        return;
    }

    int count = 0;
    Node<T> *current = start;
    Node<T> *newValue = new Node<T>(value);

    while (count != j - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }

    if (count != j - 1 || current == nullptr) {
        delete newValue;
        return;
    }

    Node<T> *temp = current->next;
    current->next = newValue;
    newValue->next = temp;
    ++mySize;
}


//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart()
{
  Node<T> * temp = start;
  start = start->next;
  delete(temp);
  --mySize;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
    if (start == nullptr)
        return;

    Node<T> *current = start;
    Node<T> *prev = nullptr;
    while (current->next != nullptr)
    {
        prev = current;
        current = current->next;
    }
    if (prev == nullptr)
    {
        delete start;
        start = nullptr;
    }
    else
    {
        prev->next = nullptr;
        delete current;
    }

    --mySize;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
    Node<T> *temp = start;
    Node<T> *current = start;
    int count = 0;
    while (count != j - 1)
    {
        current = current->next;
        count++;
    }
    temp = current->next;
    current->next = nullptr;
    delete temp;
    --mySize;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
  return start->value;


}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
    if (empty())
    {
        return T();
    }
    else
    {
        Node<T> *temp = start;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->value;
    }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
    Node<T> *temp = start;
    int count = 0;
    while (count != j)
    {
        temp = temp->next;
        count++;
    }
    return temp->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
    Node<T> *current = start;
    int counter = 0;

    while (current->next != nullptr && current->value != key)
    {
        counter++;
        current = current->next;
        if (current->next == nullptr)
        {
            counter = -1;
        }
    }


    return counter;
}