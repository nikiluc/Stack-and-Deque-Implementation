//
//  deque.h
//  Project 3
//
//  Created by Luc N on 3/20/18.
//  Copyright © 2018 Luc N. All rights reserved.
//

#ifndef deque_h
#define deque_h

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <exception>
#include "nosuchobject.h"
#include "dlnode.h"



template <typename T>
class Deque {
    
public:
    Deque();
    Deque( const Deque<T>& ) throw ( bad_alloc );
    bool empty() const;
    unsigned size() const;
    void insertFront( const T& ) throw ( bad_alloc );
    void insertBack( const T& ) throw ( bad_alloc );
    T removeFront() throw ( NoSuchObject );
    T& front() const throw ( NoSuchObject );
    T removeBack() throw ( NoSuchObject );
    T& back() const throw ( NoSuchObject );
    const Deque<T> &operator=( const Deque<T>& ) throw ( bad_alloc );
    void printInternal() const;
    void clear();
    ~Deque();
    
private:
    unsigned sz;
    DLNode<T>* frontPtr;
    DLNode<T>* backPtr;
    
    void initialize();
    
}; // Deque class

//Default constructor
template <typename T>
Deque<T>::Deque()
{
    //cout << "Entered default constructor of Deque class." << endl;
    
    this->initialize();
    
} // END Deque::Deque()

//Copy constuctor that uses overloaded operator
template <typename T>
Deque<T>::Deque(const Deque<T>& deq) throw (bad_alloc) {
    
    //copy constructor
    //std::cout << "Inside copy constructor for class Stack\n";
    
    this->initialize();
    
    //cout << "calling overloaded assignment operator" << endl;
    *this = deq;
    
    

} // END Deque(const Deque<T>& deq)

//returns true or false depending on if the deque is empty
template <typename T>
bool Deque<T>::empty() const {
    
    return sz == 0;
    
} // END empty()

//returns size of deque
template <typename T>
unsigned Deque<T>::size() const {
    
    return sz;
    
}
/*
 Adds a DLNode from the front of the deque
 */
template <typename T>
void Deque<T>::insertFront(const T& val) throw (bad_alloc)  {
    
    DLNode<T> *newNode = new DLNode<T>(val, frontPtr, NULL);
    
    //if deque is empty
    if ((*this).empty()) {
        
        frontPtr = newNode;
        backPtr = newNode;
    }
    
    else {
    
    //set current first object previous pointer to
    //newest object
    frontPtr->previous = newNode;
    //newNode's next set to the second object
    newNode->next = frontPtr;
    //newNode is now first object
    frontPtr = newNode;
        
    }
    
    if (sz == 0) {
        backPtr = frontPtr;
    }
        
        sz++;
    
}

/*
 Adds a DLNode from the back of the deque
 */
template <typename T>
void Deque<T>::insertBack(const T& val) throw (bad_alloc)  {
    
    DLNode<T> *newNode = new DLNode<T>(val, NULL, backPtr);
    
    //if the deque is empty
    if ((*this).empty()) {
        
        frontPtr = newNode;
        backPtr = newNode;
    }
    
    else {
        //now last in deque
        backPtr->next = newNode;
        //set new DLNode previous pointer to backPtr
        newNode->previous = backPtr;
        //set backPtr to newest edition
        backPtr = newNode;
        
    }
    
    if (sz == 0) {
        backPtr = frontPtr;
    }
    
    sz++;
    
}
    
/*
 Removes a DLNode from the front of the deque and returns
 object stored in it
 */
template <typename T>
T Deque<T>::removeFront() throw (NoSuchObject) {
    
    if ((*this).empty())
        throw NoSuchObject("The Deque is empty,cannot remove front.");
        
        T returnValue = this->frontPtr->info;
        DLNode<T> *current = frontPtr->next;
        delete frontPtr;
    frontPtr = current;
 
    
    sz--;
    
    if (sz == 0)
        backPtr = NULL;
        
        return returnValue;
}

template <typename T>
T& Deque<T>::front() const throw ( NoSuchObject )
{
    if ((*this).empty()) {
        throw NoSuchObject("The Deque is empty, cannot return value of front.");
    }
    
    return this->frontPtr->info;
    
    
}
/*
 Removes a DLNode from the back of the deque
 and returns object stored in it
 */
template <typename T>
T Deque<T>::removeBack() throw (NoSuchObject) {
    
    
    if ((*this).empty()) {
        throw NoSuchObject("The Deque is empty, there is nothing to remove.");
        
    }
    
        
        T returnValue = this->backPtr->info;

        DLNode<T> *current = backPtr->previous;
    
    if (current == NULL) {
       
        this->removeFront();
        
        return returnValue;
    }
    
        delete backPtr;
    backPtr = current;

        current->next = NULL;
    
    sz--;
    
    
    if (sz == 0) {
        frontPtr = NULL;
        
    }
    
        
        return returnValue;
}

/*
 Returns a reference to the object at the back of the deque
*/
template <typename T>
T& Deque<T>::back() const throw ( NoSuchObject )
{
    //if deque is empty
    if ((*this).empty()) {
        throw NoSuchObject("The Deque is empty, cannot return value of back.");
    }
    //returns reference;
    return this->backPtr->info;
    
}
/*
Overloaded assignment operator that performs a deep copy from one deque to another.
 */
template <typename T>
const Deque<T>& Deque<T>::operator=( const Deque& deq) throw ( bad_alloc ) {
    
    //If there is nothing in the other deque
    if (deq.frontPtr == NULL) {
        
        frontPtr = backPtr = NULL;
    }
    
    else {
    
    //Clears deque on left side of assignment operator
    this->clear();
    
    //cout << "great" << endl;
    
        //front pointer points to a new copy made from the other deque
        frontPtr = new DLNode<T>(deq.frontPtr->info, deq.frontPtr, NULL);
        //pointer that goes down the deque (like current)
        DLNode<T> *sec = deq.frontPtr;
    
        //while there are nodes in the other deque, add them to this deque
        while (sec != NULL) {
            
            this->insertBack(sec->info);
        
            sec = sec->next;
            
        }
    }
    
    
    
    return *this;
    
    
}

//while deque is not empty remove each node in the deque
template <typename T>
void Deque<T>::clear()
{
    //cout << "Entered clear() method of Deque object." << endl;
    

    while (!empty())
        this->removeFront();
    frontPtr = backPtr = NULL;
    sz = 0;
}
//Destructor
template <typename T>
Deque<T>::~Deque()
{
    this->clear();
} // END Deque::~Deque()
    
//set sz to zero and pointers to NULL
template <typename T>
void Deque<T>::initialize()
{
    sz = 0;
        
    frontPtr = NULL;
    backPtr = NULL;
        
} // END Deque:<T>:initialize()
    
//Prints information about each node in deque
template <typename T>
void Deque<T>::printInternal() const
{
    DLNode<T>* current = frontPtr;
    int i = 0;
    cout << "front: " << frontPtr << endl;
    while ( current != 0 ) {
        cout << "Node " << i << endl;
        cout << "  address: " << current << endl;
        cout << "  object: " << current->info << endl;
        cout << "  next: " << current->next << endl;
        current = current->next;
        i++;
    } // while
} // Stack<T>::printInternal





#endif /* deque_h */
