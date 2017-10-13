#ifndef INCLUDED_NODES
#define INCLUDED_NODES
#include "Point.h"

#include <iostream>
using namespace std;

class DoublePointNode {
  //CLASS INVARIENT(CI): data is a defined Point object.

  //next points to a defined Point object iff this object is
  //not the last Node; NULL otherwise.

  //previous points to a defined DoublePointNode object iff
  //this object is not the first Node; NULL otherwise. 

 private:

  Point data; //holds a Point object for this Node
  
  DoublePointNode * next; //holds a pointer to the next
			  //DoublePointNode object, if any;
			  //otherwise it is NULL.
  
  DoublePointNode * previous; //holds a pointer to the previous
			      //DoublePointNode object, if any;
			      //otherwise it is NULL.
  
 public:

  //=============================================
  //             CONSTRUCTORS/DESTRUCTOR
  //=============================================
  
  //PRE: pElement = k, which is defined Point bject
  //POST: This object is defined and has a satisfied CI.
  //       data = k, next = NULL, previous = NULL.
  DoublePointNode (Point pElement);

  //PRE: pElement = k, which is a defined Point object
  //      newNode = P, which is a defined DoublePointNode
  //      object with a satisfied CI.
  //POST: This object is defined and has a satisfied CI.
  //       data = k, next points to P, and previous = NULL.
  //DoublePointNode (Point pElement, DoublePointNode newNode);

  //PRE: pNode = P, which is a defined DoublePointNode object
  //      whose CI is satisfied.
  //      P.data = k, where k is a defined Point object.
  //POST: This object is defined and satisfies the CI.
  //      data = k, next points to the DoublePointNode object
  //      that P originally pointed to, and previous points
  //      to the DoublePointList object P originally pointed
  //      to, if any; otherwise, NULL.
  DoublePointNode (const DoublePointNode & pNode);

  //PRE: This object is defined and has a satisfied CI.
  //POST: The objects that next and previous point to, if
  //any, are deleted from the heap. 
  ~DoublePointNode ();

  //==============================================
  //                  ACCESSORS
  //==============================================
  
  Point getData() const;
  DoublePointNode * getNextPointer();
  DoublePointNode * getPreviousPointer();

  //==============================================
  //                  SETTERS
  //==============================================

  void setNextPointer(DoublePointNode * nextNode);
  void setPrevPointer(DoublePointNode * prevNode);
  
  // =============================================
  //                 OPERATORS
  // =============================================

  //PRE: pNode = P, which is a defined DoublePointNode
  //      object whose CI is satisfied.
  //      P.data = k, where k is a defined Point object.
  //POST: This object is defined and satisfies the CI.
  //      data = k, next points to the DoublePointNode object
  //      that P orgianlly pointed to, and previous points
  //      to the DoublePointList object P originally pointed
  //      to, if any; otherwise, NULL. 
  DoublePointNode & operator = (const DoublePointNode & pNode);

  
  //PRE: pNode = P, which is a defined DoublePointNode object
  //      whose CI is satisfied.
  //POST: RV = true iff data == P.data and previous.data ==
  //      P.previous.data and nextwhere previous != NULL.
  //      RV = false, otherwise.
  //bool operator == (const DoublePointNode & pNode);

  // =============================================
  //                   OUTPUT
  // =============================================
  
  //Overloaded << operator for output stream
  //PRE: pNode contains Point object A that is defined and
  //       has a satisfied CI. 
  //      stream is a defined writeable stream.
  //POST: stream contains A and the data of the DoublePointNode
  //       contained at next where next != NULL.
  //       RV is the changed stream.
  friend ostream & operator << (ostream & stream,
				const DoublePointNode & pNode);

};

#endif
