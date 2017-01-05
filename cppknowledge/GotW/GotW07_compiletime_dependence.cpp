/*
 * GotW07_compiletime_dependence.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: songjiguo
 */

/*a forward declaration only introduces a name. It lets you do things that require only the name,
 * such as declaring a pointer to it*/

class widget;  // "widget" names a class
widget* p;     // ok: allocates sizeof(*) space typed as widget*
widget  w;     // error: wait, what? how big is that? does it have a
               //        default constructor?


/*Guideline: Prefer to #include <iosfwd> when a forward declaration of a stream will suffice.*/


