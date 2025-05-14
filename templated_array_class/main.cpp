//testing file
//josh m
//

#include <iostream>
#include <stdlib.h>
#include "Array.h"

using namespace std;

int main(int argc, char **argv) {

	int aSize(5);
	double *ptrArr = new double[aSize];
	init(ptrArr, aSize); //now array has user input values
	print(ptrArr, aSize);
	//at index 4, add 20
	int index(4);
	double num(20);
	cout << "............Inserting 20 into index 4..........." << endl;
	insert(ptrArr, aSize, index, num); //inserts 20 into index 4
	print(ptrArr, aSize);
	cout << endl;
	cout << "............Removing index 4 value..............." << endl;
	remove(ptrArr, aSize, index);
	print(ptrArr, aSize);
	cout << "...........Getting value at index 3............." << endl;
	cout << get(ptrArr, aSize, 3) << endl;
	cout << "...........Setting value at index 3 to 29.35............." << endl;
	set(ptrArr, aSize, 3, 29.35);
	print(ptrArr, aSize);
	cout << "...........Finding index of value 29.35............." << endl;
	cout << find(ptrArr, aSize, 29.35) << endl;
	cout
			<< "...........Checking if new array is equal to first array............."
			<< endl;
	double *array2 = new double[aSize];
	init(array2, aSize);
	print(array2, aSize);
	cout << endl;
	cout << equals(ptrArr, aSize, array2, aSize) << endl;

	cout << "...........Clearing array and setting size to 0............."
			<< endl;
	clear(ptrArr, aSize);
	print(ptrArr, aSize);
	cout << "Size of array: " << aSize << endl;

	return (0);
}

