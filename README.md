# convexHullOfIntegers
A C++ program that gets the name of two files, say file1 and
file2, as command line arguments and computes, using the
Quickhull algorithm, the convex hull of a set of integer
co-ordinated points in 2-dimensional space. file1 will
contain the input to the program and file 2 is where the
program writes the output.

# How To Compile and Run the program
execute the commands

1. make convexHull
2. ./convexHull.exe (inputFile) (outputFile)

# Assumptions
The numbers will be valid numbers,
the numbers are all positive, 
there are only two
numbers on each line, and 
the end of file character is
on a new line by itself. 

There are at least three non-collinear
points in the input file. 

# Expectations
The numbers are properly read in and stored in a linked list
written out to a file. It does not compute the convex hull.
