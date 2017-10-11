objects = printConvexHull.o

convexHull: $(objects)
	g++ $(objects) -o convexHull

printConvexHull.o: printConvexHull.cpp
	g++ -c printConvexHull.cpp

clean:
	rm $(objects) *~ convexHull
