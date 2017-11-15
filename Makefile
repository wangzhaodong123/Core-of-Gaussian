all:core_of_gaussian

core_of_gaussian:core_of_gaussian.o
	g++ -o core_of_gaussian core_of_gaussian.o
core_of_gaussian.o:core_of_gaussian.cpp
	g++ -c core_of_gaussian.cpp
clean:
	rm -f core_of_gaussian.o core_of_gaussian
