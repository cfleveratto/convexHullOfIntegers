#ifndef included_PointClass
#define included_PointClass

#include <iostream>
using namespace std;

class Point {
  //CLASS INVARIENT (CI): this object holds two integers the
  //represent the x and y coordinate on a 2 dimensional
  //space.
 private:
  int x_coor;
  int y_coor;

 public:

  //PRE: None
  //POST: Sets x_coor and y_coor to -1.
  Point();
  
  //PRE: x and y are two positive integers
  //POST: CI satisfied.
  Point(int x, int y);

  //==========================================================
  //                  OVERLOADED OPERATORS
  //==========================================================

  //PRE: pPoint = P, which is a defined Point
  //      object whose CI is satisfied.
  //      P.x_coor = i, and  P.y_coor = j where i and j are
  //      integers. 
  //POST: This object is defined and satisfies the CI.
  //      x_coor = i, y_coor = j;
  Point & operator = (const Point & pPoint);

  //PRE: pPoint = P, which is a defined Point object
  //      whose CI is satisfied.
  //POST: RV = true iff data.x_coor < pPoint.data.x_coor and
  //      data.y_coor < pPoint.data.y_coor.
  bool operator < (const Point & pPoint);

  //PRE: pPoint is defined and has a satisfied CI.
  //POST: RV = true iff the data members in this object do
  //not equal the data members in pPoint. False, otherwise.
  bool operator != (const Point & pPoint);
  
  //==========================================================
  //                         OUTPUT
  //==========================================================
  
  // Overloaded << operator for output stream
  // PRE: pPoints contains an a pair of integers (x, y)
  //      stream is a defined writeable stream.
  // POST: stream contains (x, y).
  //       RV is the changed stream.
  friend ostream & operator << (ostream & stream,
				const Point & pPoint);
};

#endif
