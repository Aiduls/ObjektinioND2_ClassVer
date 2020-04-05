CC=g++

all: Application
	
Application: main.o func.o
	$(CC) ND2_v1.0.o func.o -o Application

main.o: ND2_v1.0.cpp Header.h
	$(CC) -c ND2_v1.0.cpp Header.h

func.o: func.cpp Header.h
	$(CC) -c func.cpp Header.h

clean:
	rm *.o *.gch Application
