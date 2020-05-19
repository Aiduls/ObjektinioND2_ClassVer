main: func.o
	g++ -o main main.cpp func.o
test_unit: test_unit.o func.o
	g++ -o test_unit test_unit.cpp func.o
func:
	g++ -c func.cpp
	
clean:
	rm *.o main *.txt test_unit
run:
	./main
run_tests: 
	./test_unit