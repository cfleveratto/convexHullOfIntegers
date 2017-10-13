#include "DoublePointNode.h"

DoublePointNode::DoublePointNode () {
  Point Empty;
  data = Empty;
  next = NULL;
  previous = NULL;
}

//PRE: pElement = k, which is defined Point bject
//POST: This object is defined and has a satisfied CI.
//       data = k, next = NULL, previous = NULL.
DoublePointNode::DoublePointNode (Point pElement) {
  data = pElement;
  next = NULL;
  previous = NULL;
}

//PRE: pNode = P, which is a defined DoublePointNode object
//      whose CI is satisfied.
//      P.data = k, where k is a defined Point object.
//POST: This object is defined and satisfies the CI.
//      data = k, next points to the DoublePointNode object
//      that P originally pointed to, and previous points
//      to the DoublePointList object P originally pointed
//      to, if any; otherwise, NULL.
DoublePointNode::DoublePointNode (const DoublePointNode & pNode) {
  cout << "Entered Copy Constructor\n";
  data = pNode.data;
  next = pNode.next;
  previous = pNode.previous;
  cout << "After assignment" << *this;
  cout << "Exited Copy COnstrutore\n";
}

//PRE: This object is defined and has a satisfied CI.
//POST: The objects that next and previous point to, if
//any, are deleted from the heap. 
DoublePointNode::~DoublePointNode () {
  if (next != NULL) {
    delete next;
  }
}

//==============================================
//                  ACCESSORS
//==============================================
  
Point DoublePointNode::getData() const {
  return(data);
}
DoublePointNode * DoublePointNode::getNextPointer() {
  return(next);
}
DoublePointNode * DoublePointNode::getPreviousPointer() {
  return(previous);
}


void DoublePointNode::setNextPointer(DoublePointNode * nextNode) {
  next = nextNode;
}

void DoublePointNode::setPrevPointer(DoublePointNode * prevNode) {
  previous = prevNode;
}

//PRE: pNode = P, which is a defined DoublePointNode
//      object whose CI is satisfied.
//      P.data = k, where k is a defined Point object.
//POST: This object is defined and satisfies the CI.
//      data = k, next points to the DoublePointNode object
//      that P orgianlly pointed to, and previous points
//      to the DoublePointList object P originally pointed
//      to, if any; otherwise, NULL. 
DoublePointNode & DoublePointNode::operator = (const DoublePointNode & pNode) {
  cout << "Entered Assignment operator for NOde" << endl;
  data = pNode.data;
  if (pNode.next != NULL) {
    *next = *(pNode.next);
  }
  if (pNode.previous != NULL) {
    *previous = *(pNode.previous);
  }
  return(*this);
}

//Overloaded << operator for output stream
//PRE: pNode contains Point object A that is defined and
//       has a satisfied CI. 
//      stream is a defined writeable stream.
//POST: stream contains A and the data of the DoublePointNode
//       contained at next where next != NULL.
//       RV is the changed stream.
ostream & operator << (ostream & stream,
		       const DoublePointNode & pNode) {
  stream << pNode.data;
  stream << pNode.next << endl;
  stream << pNode.previous << endl;
  return (stream);
}
