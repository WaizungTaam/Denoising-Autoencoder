CC=g++
FLAG=-std=c++11
PATH_SRC=./src/
PATH_MATH=./src/math/
PATH_TEST=./test/
MATH=$(PATH_MATH)*
DA=$(PATH_SRC)dA.h $(PATH_SRC)dA.cc


all: dA_test.o

dA_test.o: $(MATH) $(DA) $(PATH_TEST)dA_test.cc
	$(CC) $(FLAG) $(MATH) $(DA) $(PATH_TEST)dA_test.cc -o dA_test.o