//Josh Moorehead
//
#include <iostream>
#include <stdlib.h> //for the exit function
#include "Array.h"

using namespace std;

void insert(double *&arr, int &size, int index, double num) { //adds a double at given position of array and updates the size using call by reference
	if (size + 1 < index) { //error checking if out of bounds 
		cout << "Index out of bounds... Exiting program." << endl;
		exit(1);
	}
	size++; //after passing error checking, can add one to size. 
	double *temp = new double[size];
	//transferring content from arr to temp
	for (int i = 0; i < size - 1; i++)
		temp[i] = arr[i];
	//moving indexes over by 1 
	for (int i = size; i > index; i--) {
		temp[i] = arr[i - 1];
	}
	//with open position at index given, we insert the value
	temp[index] = num;
	delete[] arr; //must delete pointer to old array to avoid memory leak
	arr = temp; //pointing at temp array now
}

void remove(double *&arr, int &size, int index) { // same as insert except removes value
	if (size < index) { //error checking if out of bounds 
		cout << "Index out of bounds... Exiting program." << endl;
		exit(1);
	}
	size--; //once passed error check, can decrement
	double *temp = new double[size];
	//removing value from arr by shifting everything left by 1 starting at index given
	for (int i = index; i <= size; i++) {
		arr[i] = arr[i + 1];
	}
	//transferring content from arr to temp. stops before the last index of arr
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	delete[] arr; //must delete pointer to old array to avoid memory leak
	arr = temp; //pointing at temp array now
}
double get(double *arr, int size, int index) { //returns index value at given index
	if (size < index) { //error checking if out of bounds 
		cout << "Index out of bounds... Exiting program." << endl;
		exit(1);
	}
	return arr[index];

}
void set(double *arr, int size, int index, double num) { //sets element value at given index
	if (size < index) { //error checking if out of bounds 
		cout << "Index out of bounds... Exiting program." << endl;
		exit(1);
	}
	arr[index] = num;
}
void clear(double *&arr, int &size) { //deallocates memory for array and sets size to 0

	delete[] arr;
	size = 0;
}
int find(double *arr, int size, double num) { //finds index where given value is found. returns -1 if not found
	int index(-1);
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			index = i;
			break;
		}
	}
	return index;
}

bool equals(double *arr1, int size1, double *arr2, int size2) { //returns true if contents of two given arrays of same size are equal
	if (size1 != size2) { //logic checking array sizes are equal
		cout << "The arrays are not the same size so they cannot be compared."
				<< endl;
		exit(1);
	}
	bool isEqual(true);
	//Because the contents do not have to be in order to be the same, we have to sort the arrays first
	//I am going to use bubble sort from smallest to greatest
	for (int i = 0; i < size1 - 1; i++) {
		for (int j = 0; j < size1 - i - 1; j++) {
			if (arr1[j] > arr1[j + 1]) { // ARRAY 1 SORT
				double temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
			if (arr2[j] > arr2[j + 1]) { // ARRAY 2 SORT
				double temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
	//Now using for loop to compare the arrays for equality
	for (int i = 0; i < size1; i++) {
		if (arr1[i] != arr2[i])
			isEqual = false;
	}
	return isEqual;
}
void init(double *arr, int size) { // makes array initialized from user input
	for (int i = 0; i < size; i++) {
		cout << "Enter Value " << i << ": ";
		cin >> arr[i];
		cout << endl;
	}
}
void print(double *arr, int size) { //prints array using for loop
	cout << "Your array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

