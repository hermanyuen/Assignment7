#include "TestHarness.h"

#include "DynamicArray.h"

//An array is a common structure for storing information.In many languages, one must specify the size of the array in advance of its use.
//Frequently, however, one does not know how much data will need to be stored.
//A common solution is to declare the array to be much larger than is expected to be necessary hoping it will be large enough.
//This is certainly not the most efficient solution.
//
//1.Design an array that expands as data is entered and contracts when it is removed.
// You will need to define a private data structure to support the array.
// Use one of the STL collection classes such as vector, list, or deque.Support the following access methods :
// 
//  // Overwrites an existing element, or adds a new element as necessary.
//  // If an element exists at index, the existing element is overwritten.
//  // If an element does not exist at the index, a new element is added. If necessary, the array
//  // must expand to accommodate the new element. 
//  void put(int index, int value);
//
//  // returns the element at index.
//  int get(int index) const;
//
//  // removes the element at the specified index. The array may contract.
//  void remove(int index);
//
//Provide two overloads of operator[]:
// * Provide a const member function overload which returns the data at the specified array index.
// * Provide a non - const member function overload which allows the data to be overwritten at the specified array index.
//
//2. Write an overloaded ostream operator to display the contents of the array.
//
//3. Describe why the compiler generated copy constructor and copy assignment operators are sufficient for DynamicArray.

//TODO: write some good unit tests!

TEST(putTest, DynamicArrayTest) {
	DynamicArray array(0);
	for (int i = 0; i < 6; ++i) {
		array.put(i, i);
	}
	
	CHECK_EQUAL(1, array.get(1));
	CHECK_EQUAL(2, array.get(2));
	CHECK_EQUAL(3, array.get(3));
	CHECK_EQUAL(4, array.get(4));
	CHECK_EQUAL(5, array.get(5));

}

TEST(removeTest, DynamicArrayTest1) {
	DynamicArray array(0);
	for (int i = 0; i < 7; ++i) {
		array.put(i, i);
	}
	array.remove(3);
	CHECK_EQUAL(1, array.get(1));
	CHECK_EQUAL(2, array.get(2));
	CHECK_EQUAL(4, array.get(3));
	CHECK_EQUAL(5, array.get(4));
	CHECK_EQUAL(6, array.get(5));
}

TEST(arrayTest, DynamicArray2) {
	DynamicArray array(0);
	for (int i = 0; i < 10; ++i) {
		array.put(i, i);
	}
	array[0] = 90;
	array[5] = 100;
	array[9] = 1;
	CHECK_EQUAL(90, array.get(0));
	CHECK_EQUAL(100, array.get(5));
	CHECK_EQUAL(1, array.get(9));
}