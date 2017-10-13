#include <iostream>
#include <fstream>
#include "DoublePointList.h"
#include "helper.h"

using namespace std;

//PRE: the terminal contains commandline arguments
//POST: the convex hull of a sequence of integer
//pairs are printed out in clockwise manner with no
//repeitions iff there is an existing inputfile and a
//nonexisting outputfile. Otherwise, error message is
//printed.  
int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage: ./airlineRoutes file1 file2\n";
  }
  else {
    ifstream inFile(argv[1]);
    ifstream checkFile(argv[2]);
    if ((inFile != NULL) && (checkFile == NULL)) {
      //ASSERT: inFIle exists and checkFile does not.
      checkFile.close();
      ofstream outFile(argv[2]); //this will be the file the
				 //convex hull is written
				 //to.
      DoublePointList pointsList; //this will hold all the
				  //Points read in.
      readPoints(inFile, pointsList);
      //ASSERT: integers were read in from inFile and made
      //into Point objects that are stored in pointsList.

      //DoublePointList convexHull = getConvexHull(pointsList);
      //ASSERT: convexHull holds the points in clockwise
      //direction that make up the convex hull with no
      //repetiting points.

      //outFile << convexHull << endl;
      //ASSERT: the DoublePointNodes that are contained in
      //convexHull are written to outFile.

      outFile.close();
    }
    else {
      cout << "ERROR: Please check that the input file "
	   << "exists and that the output file does not.\n";
    }
  }
}
