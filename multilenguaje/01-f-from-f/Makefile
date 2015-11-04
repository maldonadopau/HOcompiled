default: f-main.e

f-main.e: f-main.o f-sum.o
	gfortran $^ -o $@

%.o: %.f90
	gfortran $^ -c -o $@
