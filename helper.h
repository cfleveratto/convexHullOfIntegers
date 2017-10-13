#ifndef included_helper
#define included_helper
#include <fstream>
#include <iostream>
using namespace std;

#include "DoublePointList.h"
#include "DoublePointNode.h"
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
void readPoints(ifstream & stream, DoublePointList & pList);


//PRE:
//POST:
DoublePointList getConvexHull(DoublePointList & aList);

#endif
