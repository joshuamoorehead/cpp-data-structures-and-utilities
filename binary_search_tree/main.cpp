//Written by Joshua Moorehead

#include <iostream>
#include "myStatLib.h"
//#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	int size(0);

	cout << "Please enter the size of your array: ";
	cin >> size;
	cout << endl;

	double myArr[size];

	readArray(myArr, size);
	cout << "The elements of the array are: " << endl;
	printArray(myArr, size);
	sort(myArr, size);
	cout << "The elements of the array in ascending order: " << endl;
	printArray(myArr, size);

	cout << "Minimum: " << min(myArr, size) << endl;
	cout << "Maximum: " << max(myArr, size) << endl;
	cout << "Mean: " << mean(myArr, size) << endl;
	cout << "Median: " << median(myArr, size) << endl;

	return 0;

}
