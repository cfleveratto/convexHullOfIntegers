#ifndef included_PointClass
#define included_PointClass

class Point {
  //CLASS INVARIENT (CI): this object holds two integers the
  //represent the x and y coordinate on a 2 dimensional
  //space.
 private:
  int x_coor;
  int y_coor;

 public: 
  //PRE: x and y are two positive integers
  //POST: CI satisfied.
  Point(int x, int y);
  
};

#endif
