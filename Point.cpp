#include "Point.h"

//PRE: None
//POST: Sets x_coor and y_coor to -1.
Point::Point() {
  x_coor = -1;
  y_coor = -1;
}

//PRE: x and y are two positive integers
//POST: CI satisfied.
Point::Point(int x, int y) {
  x_coor = x;
  y_coor = y;
}

//PRE: pPoint = P, which is a defined Point
//      object whose CI is satisfied.
//      P.x_coor = i, and  P.y_coor = j where i and j are
//      integers. 
//POST: This object is defined and satisfies the CI.
//      x_coor = i, y_coor = j;
Point & Point::operator = (const Point & pPoint) {
  x_coor = pPoint.x_coor;
  y_coor = pPoint.y_coor;
}

//PRE: pPoint = P, which is a defined Point object
//      whose CI is satisfied.
//POST: RV = true iff x_coor < pPoint.x_coor and
//      y_coor < pPoint.y_coor.
bool Point::operator < (const Point & pPoint) {
  bool lessThan = false;
  if (x_coor < pPoint.x_coor) {
    lessThan = true;
  }
  if ((x_coor == pPoint.x_coor) &&
      (y_coor < pPoint.y_coor)) {
    lessThan = true;
  }
  return(lessThan);
}


//PRE: pPoint is defined and has a satisfied CI.
//POST: RV = true iff the data members in this object do
//not equal the data members in pPoint. False, otherwise.
bool Point::operator != (const Point & pPoint) {
  bool notEqual = true;
  if ((x_coor == pPoint.x_coor) &&
      (y_coor == pPoint.y_coor)) {
    notEqual = false;
  }
  return(notEqual);
}

// Overloaded << operator for output stream
// PRE: pPoints contains an a pair of integers (x, y)
//      stream is a defined writeable stream.
// POST: stream contains (x, y).
//       RV is the changed stream.
ofstream & operator << (ofstream & stream,
		       const Point & pPoint) {
  stream << '(' << pPoint.x_coor << ", "
	 << pPoint.y_coor << ')' << endl;
  return (stream);
}
