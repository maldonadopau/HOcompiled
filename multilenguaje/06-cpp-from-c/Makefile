default: c-main.e

c-main.e: c-main.o cpp-sum.o
	gcc $^ -o $@

c-main.o: c-main.c
	gcc $^ -c -o $@

cpp-sum.o: cpp-sum.cpp
	g++ $^ -c -o $@
