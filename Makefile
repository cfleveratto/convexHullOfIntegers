objects = printConvexHull.o helper.o DoublePointList.o \
          DoublePointNode.o Point.o

convexHull: $(objects)
	g++ $(objects) -o convexHull

printConvexHull.o: helper.h DoublePointList.h printConvexHull.cpp
	g++ -c printConvexHull.cpp

Point.o: Point.h Point.cpp
	g++ -c Point.cpp

helper.o: DoublePointList.h DoublePointNode.h helper.h helper.cpp
	g++ -c helper.cpp

DoublePointList.o: DoublePointList.h DoublePointNode.h \
        DoublePointList.cpp
	g++ -c DoublePointList.cpp

DoublePointNode.o: Point.h DoublePointNode.h \
                     DoublePointNode.cpp
	g++ -c DoublePointNode.cpp

clean:
	rm $(objects) *~ convexHull text.txt
