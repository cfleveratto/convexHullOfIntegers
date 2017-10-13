#include "DoublePointList.h"

//=============================================
//             CONSTRUCTORS/DESTRUCTOR
//=============================================
  
//PRE: None.
//POST: This object is defined and has a satisfied CI.
//       firstNode = NULL, lastNode = NULL, and
//       numElements = 0.
DoublePointList::DoublePointList () {
  firstNode = NULL;
  lastNode = NULL;
  numElements = 0;
}

//PRE: pNode is defined and has a satisfied CI. 
//POST: pNode was inserted into this object according to
//increasing order of x coordinate  with ties settled by
//increasing order of y coordinate. 
void DoublePointList::insertNode(DoublePointNode & pNode) {
  if (firstNode == NULL) {
    //ASSERT: Linked List is empty.
    addToFront(pNode);
  }
  else {
    DoublePointNode * currentNode; //this will point to the
                                    //current Node being
				    //checked.
    DoublePointNode * previousNode; //this will hold a pointer
				    //to the previous Node
				    //checked.
    currentNode = firstNode; //sets checkNode to head of
				   //
    bool foundPlace = false;
    while ((currentNode != NULL) && !foundPlace) {
      //ASSERT: the end of the linked list was not reached.
      if (currentNode->getData() < pNode.getData()) {
	//ASSERT:pNode is greater than the current Nodes data.
	previousNode = currentNode;
	currentNode = currentNode->getNextPointer();
      }
      else if (currentNode->getData() != pNode.getData()) {
	foundPlace = true;
	numElements += 1;
	if (currentNode->getPreviousPointer() != NULL) {
	  //ASSERT: it is not the root
	  DoublePointNode * newNode = new DoublePointNode;
	  *newNode = pNode;
	  newNode->setNextPointer(currentNode);
	  newNode->setPrevPointer(currentNode->getPreviousPointer());
	  currentNode->setPrevPointer(newNode);
	  previousNode->setNextPointer(newNode);
	}
	else {
	  //ASSERT: It is the root
	  addToFront(pNode);
	  // pNode.setNextPointer(currentNode);
	  // DoublePointNode * newNode = new DoublePointNode(pNode);
	  // currentNode.setPrevPointer(newNode);
	}
      }
      else {
	foundPlace = true;
	cout << "This is a repeated coordinate. "
	     << "Skipping this pair.\n";
      }
    }
    if(!foundPlace) {
      addToBack(pNode);
    }
      
  }
  cout << *this << endl;
}

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
DoublePointList::DoublePointList (const DoublePointList & pPointList) {
  *firstNode = *(pPointList.firstNode);
  *firstNode = *(pPointList.lastNode);
  numElements = pPointList.numElements;
}

//PRE: This object is defined and has a satisfied CI.
//POST: The DoublePointNode objects that firstNode and
//lastNode pointed to were deleted from the heap.
DoublePointList::~DoublePointList () {
  cout << "Entered deconstructor for List\n";
  if (firstNode != NULL) {
    delete firstNode;
  }
}

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
void DoublePointList::addToFront (DoublePointNode pElement) {
  if (firstNode != NULL) {
    DoublePointNode * newNode = new DoublePointNode;
    pElement.setNextPointer(firstNode);
    *newNode = pElement;
    firstNode->setPrevPointer(newNode);
  }
  else {
    DoublePointNode * newNode = new DoublePointNode;
    *newNode = pElement;
    firstNode = newNode;
    lastNode = newNode;
  }
  numElements += 1;
}
  
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
void DoublePointList::addToBack (DoublePointNode pElement) {
  DoublePointNode * newNode = new DoublePointNode;
  *newNode = pElement;
  lastNode->setNextPointer(newNode);
  newNode->setPrevPointer(lastNode);
  lastNode = newNode;
  numElements += 1;
}

//Overloaded << operator for outnput stream
//PRE: pList is a defined DoublePointList whose CI is
//      satisfied.
//     stream is a defined writeable stream.
//POST: stream contains the list of elements
//       e1, e2, ..., en. That is all the DoublePointNode
//       objects' data at firstNode through lastNode are
//       added to the stream.
//       RV is the changed stream.
ostream & operator << (ostream & stream,
		       const DoublePointList & pList) {
  DoublePointNode * currentNode = pList.firstNode;
  //this will hold pointer of
  //node as its  loops
  //through linked list.
  int nodeNum = 1; //this will hold the currentNum;
  while (currentNode != NULL) {
    stream << 'P' << nodeNum << " = "
	   << *currentNode;
    currentNode = currentNode->getNextPointer();
    nodeNum++;
  }
  stream << endl;
  stream << "FirstNode memoery location" <<pList.firstNode << endl;
  stream << "lastNode memory location " << pList.lastNode << endl;
  return (stream);
}
