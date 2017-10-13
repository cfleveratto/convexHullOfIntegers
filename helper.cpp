#include "helper.h"

//PRE: stream is an exisiting ifstream.
//     pList is a defined DoublePointList object and has
//      a satisfied CI.  
//     pList.firstNode = NULL, pList.lastNode = NULL, and
//      pList.numElements = 0.
//POST: integers were read in from stream such that xi and yi
//     for all i up to n which is the number of pairs read
//     in from input are in increasing order by x with ties
//     settled by increasing order of y.
//     pList.firstNode points to the pair (x1, y1) and
//     pList.lastNode points to the pair (xn, yn).
//     pList.numElements = n.
void readPoints(ifstream & stream, DoublePointList & pList) {
  while(!stream.eof()) {
    int firstInt, secondInt; //these will hold the integers
			     //read on each line.
    stream >> firstInt >> secondInt;
    //ASSERT: two intgers were read in from stream.

    Point newPair(firstInt, secondInt);
    //ASSERT: a new Point object was created.
    
    DoublePointNode newNode(newPair);
    //ASSERT: newNode.data = newPair;
    //        newNode.next = newNode.previous = NULL
    cout << "NewNode" << newNode << endl;
    cout << "Entering insertNode Function" << endl;
    pList.insertNode(newNode);
    //ASSERT: newNode was inserted into pList as a
    //DoublePointNode object according to increasing order
    //of x coordinate  with ties settled by 
    //increasing order of y coordinate.
    //No repititions occured.
    cout << "exiting insertNode Function" << endl;
  }
  stream.close();
  cout << "finished reading" << endl;
  
}


      
    
	  
      
