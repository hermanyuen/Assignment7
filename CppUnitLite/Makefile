CXX=g++
CFLAGS=-I../include/CppUnitLite
CPPFLAGS=-std=c++20

OBJ = Failure.o Test.o TestRegistry.o TestResult.o WFailure.o
%.o: %.cpp
	$(CXX) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

libCppUnitLite.a: $(OBJ)
	ar rcs libCppUnitLite.a $(OBJ)
	ranlib libCppUnitLite.a

all: libCppUnitLite.a

clean:
	rm *.a
	rm *.o
