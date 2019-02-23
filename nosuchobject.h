//
//  nosuchobject.h
//  Project 3
//
//  Created by Luc N on 3/20/18.
//  Copyright © 2018 Luc N. All rights reserved.
//

#ifndef nosuchobject_h
#define nosuchobject_h

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
using std::logic_error;



/****************************************************************************
 *                                                                          *
 *                   class NoSuchObject declaration                         *
 *                                                                          *
 ****************************************************************************/


class NoSuchObject : public logic_error
{
public:
    NoSuchObject(string msg = "no such object");
    
}; //END definition class no_such_object

NoSuchObject::NoSuchObject(string msg) : std::logic_error(msg) {
    // nothing else to do
}





#endif /* nosuchobject_h */
