

#ifndef dlnode_h
#define dlnode_h


#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <exception>



using std::string;
using std::endl;
using std::cout;



/****************************************************************************
 *                                                                          *
 *                      class DLNode declaration                            *
 *                                                                          *
 ****************************************************************************/

template <typename T>
class DLNode
{
public:
    T info;
    DLNode<T> *next;
    DLNode<T> *previous;
    
    DLNode(T = T(), DLNode<T> *next = NULL, DLNode<T> *previous = NULL);
    
}; //END declaration class DLNode

//Explicit constructor for DLNode
template <typename T>
DLNode<T>::DLNode(T infoValue, DLNode<T> *nextPtr, DLNode<T> *prevPtr)
{
    info = infoValue;
    next = nextPtr;
    previous = prevPtr;
}





#endif /* dlnode_h */
