default: f-main.e

f-main.e: f-main.o c-sum.o
	gcc $^ -o $@ -l gfortran

f-main.o: f-main.f90
	gfortran $^ -c -o $@

c-sum.o: c-sum.c
	gcc $^ -c -o $@
