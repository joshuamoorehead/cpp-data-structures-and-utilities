//Written by Joshua Moorehead

#include <iostream>
#include "myStatLib.h"
//#include <fstream>

using namespace std;

double min(double arr[], int size) { //function assigns first value of array to min and checks if any are smaller and changes min value if one is
	double min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
double max(double arr[], int size) { //function assigns first value of array to max and checks if any are bigger and changes max value if one is
	double max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
double mean(double arr[], int size) { //function adds all values using for loop and divides by how many there are. average
	double sum(0);
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return (sum / size);
}
double median(double arr[], int size) {
	int middle = size / 2;
	if (size % 2 == 1)
		return arr[middle]; // if array size is odd the median is just the value at the size/two
	else
		return ((arr[middle - 1] + arr[middle]) / 2); // need to add up two most middle values and divide by two for median if array size is even	
}
void sort(double arr[], int size) { //going to use classic bubble sort
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void printArray(double arr[], int size) { //prints using for loop
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void readArray(double arr[], int size) { //reads input from cin that is include in iostream. can read from keyboard or file redirect. i messed around with fstream but did not need it so i commented all of it
	//fstream inputStream;
	//inputStream.open("inputs.in");
	for (int i = 0; i < size; i++) {
		//inputStream >> arr[i];
		cout << "Enter Value " << i << ": ";
		cin >> arr[i];
		cout << endl;
	}
	cout << endl;
	//inputStream.close();
}

