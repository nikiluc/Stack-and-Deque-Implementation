//
//  stack.h
//  Project 3
//
//  Created by Luc N on 3/20/18.
//  Copyright © 2018 Luc N. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <exception>
#include "nosuchobject.h"
#include "node.h"

using std::bad_alloc;

template <typename T>
class Stack
{
public:
    Stack();
    Stack( const Stack<T>& s ) throw ( bad_alloc );
    bool empty() const;
    unsigned size() const;
    T& top() const throw ( NoSuchObject );
    T pop() throw ( NoSuchObject );
    void push( const T& ) throw ( bad_alloc );
    const Stack<T>& operator=( const Stack<T>& ) throw ( bad_alloc );
    void printInternal() const;
    void clear();
    ~Stack();
    
private:
    unsigned sz;
    Node<T>* topPtr;
    
    void initialize();
    
}; // Stack<T> class
//Prints out contents of the Stack
template <typename T>
void Stack<T>::printInternal() const
{
    Node<T>* current = topPtr;
    int i = 0;
    cout << "top: " << topPtr << endl;
    while ( current != 0 ) {
        cout << "Node " << i << endl;
        cout << "  address: " << current << endl;
        cout << "  object: " << current->getObject() << endl;
        cout << "  next: " << current->getNextPtr() << endl;
        current = current->getNextPtr();
        i++;
    } // while
}
// Stack<T>::printInternal
//Default constructor
template <typename T>
Stack<T>::Stack() {
    
    //default constructor
    //std::cout << "Inside default constructor for class Stack\n";
    this->initialize();
}

//Copy constructor that uses overloaded assignment operator
template <typename T>
Stack<T>::Stack( const Stack<T>& s ) throw ( bad_alloc ) {
    
        //copy constructor
        //std::cout << "Inside copy constructor for class Stack\n";
        
        this->initialize();
        
        //cout << "calling overloaded assignment operator" << endl;
        *this = s;
    
}
//returns true or false depending on if stack is empty
template <typename T>
bool Stack<T>::empty() const {
    
    return (sz == 0);
        
}
//returns size of stack
template <typename T>
unsigned Stack<T>::size() const {
    
    return sz;
    
}
    
//Overloaded assignment operator that copies stacks
template <typename T>
const Stack<T>& Stack<T>::operator=( const Stack<T>& stack) throw ( bad_alloc )
{
    //overloaded assignment operator
        
    if (this != &stack)
    {
        //no self-assignment, so OK to continue
        //std::cout << "Inside overloaded assignment operator for class Stack\n";
            
        //make sure any existing contents of the left hand side list are deallocated
        this->clear();
            
        //should have been done by clear, but no harm repeating
        sz = 0;
        topPtr = NULL;
            
        Node<T> *otherCurrent = stack.topPtr;
            
        if (otherCurrent == NULL)
        {
            cout << "other Stack is empty, nothing to do" << endl;
        }
        else
        {
            // first need to copy otherStack contents to temporary Stack object
            Stack<T> * tempStack = new Stack<T>;
            while (otherCurrent != NULL)
            {
                tempStack -> push(otherCurrent->getObject());
                otherCurrent = otherCurrent->getNextPtr();
            }
                
                // now "move" contents of temporary Stack to Stack being copied to
                // result is Stack with same contents in same order
            while(!tempStack -> empty())
            {
                this->push(tempStack -> pop());
            }
        }
            
            
    } // END if (this != &rhsStack)
        
    return *this;
        
} // END Stack::operator=(const Stack &rhsStack)
//Returns reference to item on top of Stack
template <typename T>
T& Stack<T>::top() const throw ( NoSuchObject ) {
    
    if (topPtr == NULL) {
        throw NoSuchObject("ERROR - in Stack<T>::top(), Stack is empty, nothing to do\n");
    }
    
    return this->topPtr->getObject();
    
    
}
//Removes item from top of the stack
template <typename T>
T Stack<T>::pop() throw ( NoSuchObject ) {
        
    T returnValue;
    
    
        if ( topPtr == NULL )
        {
                // nothing to do
            throw NoSuchObject("ERROR - in Stack<T>::pop(), list is already empty\n");
        }
        else if ( topPtr->getNextPtr() == NULL )
        {
                // only one object on the list
            returnValue = topPtr->getObject();
            delete topPtr;
            topPtr = NULL;
            sz = 0;
        }
        else
        {
            // more than one object on the list
            returnValue = topPtr->getObject();
            Node<T> *current = topPtr;
            topPtr = topPtr->getNextPtr();
            delete current;
            sz--;
        }
    
    return returnValue;
}
//Pushes new nodes onto the stack
template <typename T>
void Stack<T>::push( const T& info) throw ( bad_alloc ) {
    
    Node<T> *temp;
    
    try
    {
        if (topPtr == NULL)
        {
            //this is the first element
           // std::cout << "adding first node to linked list\n";
            
            topPtr = new Node<T>(info);
        }
        else
        {
            //list has some contents already
//#ifdef DEBUG_LL_PUSH_FRONT
           // std::cout << "adding nodes to non-empty linked list\n";
//#endif
            temp = new Node<T>(info);
            
            temp->setNextPtr(topPtr);
            
            topPtr = temp;
        }
        
        sz++;
    }
    catch(std::bad_alloc &ba1)
    {
        std::cout << "Inside Stack<T>::push() unable to allocate memory\n";
        throw;
    }

}

//Clears the entire stack
template <typename T>
void Stack<T>::clear() {
    
    int i = 0;
    T valueRemoved;
    
   // std::cout << "\tStack::clear() preparing to remove " << sz;
   // std::cout << " Nodes from the linked list\n";
    
    while (!this->empty())
    {
        i++;
        valueRemoved = this->pop();
        
        // testing and diagnostic output
        //cout << valueRemoved << " just pop'ed from Stack" << endl;
    }
    
    //std::cout << "\tStack::clear() removed " << i << " Nodes from the list\n";
    //std::cout << "\tStack::clear() new count is: " << sz << std::endl;
}
    
//Sets top pointer to NULL and size to 0;
template <typename T>
void Stack<T>::initialize() {
        
    topPtr = NULL;
    sz = 0;
    //cout << "Done initialization" << endl;
    
    }
    
template <typename T>
Stack<T>::~Stack<T>() {
    //destructor
    //std::cout << "Stack::~Stack() Entered destructor for class Stack\n";
    if (topPtr == NULL)
    {
        //nothing to do
        //std::cout << "Stack::~Stack() Stack is empty, nothing to do\n";
    }
    else
    {
        
        //unsigned long oldCount = sz;
        //std::cout << "calling member function clear() ";
        //std::cout << "to deallocate memory for all objects on the list\n";
        
        clear();
        
       //std::cout << "number of elements on the list was: " << oldCount << std::endl;
       // std::cout << "number of elements on list now is:  " << sz << std::endl;
        
    }
    
   // std::cout << "Stack::~Stack() Exiting destructor for class Stack\n";
}
        

        
    
        
    




#endif /* stack_h */
