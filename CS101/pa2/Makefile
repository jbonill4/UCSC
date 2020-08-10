//Jason Bonilla
//jbonill4
//PA2

ListClient:	ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o :	ListClient.c List.h
	gcc -c -std=c99 -Wall ListClient.c

List.o :	List.c List.h
	gcc -c -std=c99 -Wall List.c

clean :
	rm -f ListClient ListClient.o List.o
