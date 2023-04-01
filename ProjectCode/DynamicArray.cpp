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

#if 0
int DynamicArray::mySize = 0;

#else
namespace
{
	std::vector<int> array;
	int mySize;
}
#endif


DynamicArray::DynamicArray(int nElements) : mySize(nElements) {
	//this->mySize = nElements;
	array.assign(nElements, -1);
}

//DynamicArray::DynamicArray(const DynamicArray& array) {
//
//}

DynamicArray::~DynamicArray() {

}

int DynamicArray::operator[] (int index) const{
	return DynamicArray::get(index);
}

int& DynamicArray::operator[] (int index) {
	return array[index];
	//return array.at(index);
}

void DynamicArray::put(int index, int value) {
	array.insert(array.begin() + index, value);
	++mySize;
}
int DynamicArray::get(int index) const {
	return array.at(index);
}
void DynamicArray::remove(int index) {
	array.erase(array.begin() + index);
	--mySize;
}
