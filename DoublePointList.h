#ifndef included_doubPointList
#define included_doubPointList
#include "DoublePointNode.h"
#include <iostream>

using namespace std;

class DoublePointList {
  //CLASS INVARIENT(CI): numElements = n such that n >= 0.
  //firstNode points to the first DoublePointNode object,
  //if any; is NULL otherwise.

  //lastNode points to the nth DoublePointNode object, if
  //any; is NULL otherwise.
  
 private:
  DoublePointNode * firstNode;  //holds a pointer to the
			      //first DoublePointNode object
  
  DoublePointNode * lastNode; //holds a pointer to the last
                            //DoublePointNode object.

  int numElements;      //holds the number of defined 
			//DoublePointNode objects in this
			//structure.
 
 public:

  //=============================================
  //             CONSTRUCTORS/DESTRUCTOR
  //=============================================
  
  //PRE: None.
  //POST: This object is defined and has a satisfied CI.
  //       firstNode = NULL, lastNode = NULL, and
  //       numElements = 0.
  DoublePointList ();

  //PRE: newNode = P, which is a defined DoublePointNode
  //     object with a satisfied CI.
  //POST: This object is defined and has a satisfied CI.
  //      firstNode and lastNode points to the address
  //      location of P. numElements = 1.
  DoublePointList (DoublePointNode newNode);

  //PRE: pPointList = P, which is a defined DoublePointList
  //      object whose CI is satisfied.
  //      P.numElements = n, where n is some arbritrary
  //      integer.
  //POST: This object is a deep copy of P making it defined
  //      with a satisfied CI.
  //      numElements = n, and the elements in the list are
  //      copies of the elements in P such that
  //      e1, e2, ..., en.
  //      firstNode points to the DoublePointNode object
  //      containing e1.
  //      lastNode points to the DoublePointNode object
  //      containing en.
  DoublePointList (const DoublePointList & pPointList);

  //PRE: This object is defined and has a satisfied CI.
  //POST: The DoublePointNode objects that firstNode and
  //lastNode pointed to were deleted from the heap.
  ~DoublePointList ();
  

  //=============================================
  //                   MODIFIERS
  //=============================================
  
  //PRE: This object is defined and satisfies the CI.
  //      numElements = n, and the elements in
  //      the list are e1, e2, ..., en. firstNode points to
  //      the DoublePointNode object containing e1. lastNode points
  //      to the DoublePointNode object containing en.
  //      pElement = p is defined.
  //POST: This object is defined and satisfies the CI.
  //      numElements = n+1, and the elements in
  //      the list are p, e1, e2, ..., en. firstNode points
  //      to the DoublePointNode object containing p. lastNode
  //      points to the DoublePointNode object containing en.
  void addToFront (DoublePointNode & pElement);
  
  //PRE: This object is defined and satisfies the CI.
  //      numElements = n, and the elements in
  //      the list are e1, e2, ..., en. firstNode points to
  //      the  DoublePointNode object containing e1. lastNode points
  //      to the DoublePointNode object containing en.
  //      pElement = p is defined.
  //POST: This object is defined and satisfies the CI.
  //      numElements = n+1, and the elements in the list
  //      are e1, e2, ..., en, p. firstNode points to the
  //      DoublePointNode object containing e1. lastNode points to
  //      the DoublePointNode object containing p.
  void addToBack (DoublePointNode & pElement);

  //PRE: This object is defined and satisfies the CI.
  //      numElements = n, and the elements in
  //      the list are e1, e2, ..., en. firstNode points to
  //      the DoublePointNode object containing e1. lastNode
  //      points to the DoublePointNode object containing en.
  //      aNum = p is defined such that p <= n.
  //POST: RV = E, which is the p-th DoublePointNode object in
  //      the list of elements.
  //DoublePointNode getNthNode (int aNum);

  //PRE: This object is defined and satisfies the CI.
  //      numElements = n, and the elements in
  //      the list are e1, e2, ..., en. firstNode points to
  //      the DoublePointNode object containing e1. lastNode
  //      points to the DoublePointNode object containing en.
  //POST: This object is defined and satisfies the CI.
  //       e1 is deleted from the elements in this object. 
  //       numElements = n-1, and the elements in
  //       the list are now e2, e3..., en. firstNode points
  //       to the DoublePointNode object containing e2. lastNode
  //       points to the DoublePointNode object containing en.
  //void deleteFirstNode ();

  //PRE: This object is defined and satisfies the CI.
  //      numElements = n, and the elements in
  //      the list are e1, e2, ..., en. firstNode points to
  //      the DoublePointNode object containing e1. lastNode
  //      points to the DoublePointNode object containing en.
  //POST: This object is defined and satisfies the CI.
  //       en is deleted from the elements in this object. 
  //       numElements = n-1, and the elements in
  //       the list are now e1, e2, e3..., e(n-1). firstNode
  //       points to the DoublePointNode object containing
  //       e1. lastNode points to the DoublePointNode object
  //       containing e(n-1).
  //void deleteLastNode ();

  //PRE: This object is defined and satisfies the CI.      
  //      numElements = n, and aNum = p is defined such that
  //      p <= n.  firstNode points to the
  //      DoublePointNode object containing e1. lastNode points to
  //      the DoublePointNode object containing en.  
  //POST: This object is defined and satisfies the CI.
  //      The element ep was deleted from the list such that
  //      numElements = n-1.
  //      firstNode points to the DoublePointNode object
  //      containing e1. lastNode points to the
  //      DoublePointNode object containing en where p != n;
  //      otherwise, lastNode points to e(n-1).
  //void deleteNthNode (int aNum);

  //PRE: pNode is defined and has a satisfied CI. 
  //POST: pNode was inserted into this object according to
  //increasing order of x coordinate  with ties settled by
  //increasing order of y coordinate. 
  void insertNode(DoublePointNode & pNode);

  //=============================================
  //                 OPERATORS
  //=============================================

  //PRE: pList = P, which is a defined DoublePointList object
  //      whose CI is satisfied.
  //      P.numElements = n, where n is some arbritrary
  //      integer.
  //POST: This object is a deep copy of P making it defined
  //      with a satisfied CI.
  //      numElements = n, and the elements in the list are
  //      copies of the elements in P such that
  //      e1, e2, ..., en.
  //      firstNode points to the DoublePointNode object
  //      containing e1. lastNode points to the
  //      DoublePointNode object containing en.
  DoublePointList & operator = (const DoublePointList & pList);

  //PRE: pList = P, which is a defined DoublePointList object
  //      whose CI is satisfied.
  //POST: RV = true if numElements == P.numElements and all
  //      the elements in this object are equally defined
  //      for all the elements in P in chronological order
  //      starting at the DoublePointNode object firstNode points
  //      too and ending at the DoublePointNode object
  //      lastNode points to.
  //      RV = false otherwise.
  bool operator == (const DoublePointList & pList);
   

  //=============================================
  //                   OUTPUT
  //=============================================

  //Overloaded << operator for outnput stream
  //PRE: pList is a defined DoublePointList whose CI is
  //      satisfied.
  //     stream is a defined writeable stream.
  //POST: stream contains the list of elements
  //       e1, e2, ..., en. That is all the DoublePointNode
  //       objects' data at firstNode through lastNode are
  //       added to the stream.
  //       RV is the changed stream.
  friend ostream & operator << (ostream & stream,
				const DoublePointList & pList);

};

#endif
