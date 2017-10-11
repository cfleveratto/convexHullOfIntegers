#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage: ./airlineRoutes file1 file2\n";
  }
  else {
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    cout << inFile << endl;
    cout << outFile << endl;
    if ((inFile != NULL) && (outFile == NULL)) {
      //ASSERT: inFIle exists and outFile does not.
      cout << "Success" << endl;
    }
    else {
      cout << "ERROR: Please check that the input file "
	   << "exists and that the output file does not.\n";
    }
  }
}
