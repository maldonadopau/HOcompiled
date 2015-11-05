default: c-main.e

c-main.e: c-main.o f-sum.o
	gcc $^ -o $@ -l gfortran

c-main.o: c-main.c
	gcc $^ -c -o $@

f-sum.o: f-sum.f90
	gfortran $^ -c -o $@
