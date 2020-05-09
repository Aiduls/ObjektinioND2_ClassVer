App: ND2_v1.5.o func.o
	g++ ND2_v1.5.o func.o -o3 App

ND2_v1.5.o: ND2_v1.5.cpp Header.h
	g++ -c ND2_v1.5.cpp Header.h

func.o: func.cpp Header.h
	g++ -c func.cpp Header.h

clean: rm *.o *.gch App