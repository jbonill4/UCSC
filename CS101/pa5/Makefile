
//-----------------------------------------------------------------
//Jason Bonilla
//jbonill4
//Makefile
//PA5
//------------------------------------------------------------------

FindComponents : FindComponents.o List.o Graph.o
	gcc -o FindComponents FindComponents.o List.o Graph.o

FindComponents.o : FindComponents.c List.h Graph.h
	gcc -c -std=c99 -Wall FindComponents.c 

GraphTest: GraphTest.o List.o Graph.o
	gcc -o GraphTest GraphTest.o List.o Graph.o

GraphTest.o : GraphTest.c List.h Graph.h
	gcc -c -std=c99 -Wall GraphTest.c

Graph.o:	Graph.c Graph.h
	gcc -c -std=c99 -Wall Graph.c
List.o:	List.c List.h
	gcc -c -std=c99 -Wall List.c

clean:
	rm -f FindComponents GraphTest FindComponents.o GraphTest.o List.o Graph.o
