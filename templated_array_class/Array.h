//Written by Joshua Moorehead
//On 10/3/2022 22:54
//This program will have functions that demonstrate some of the uses of pointers and pointer arrays using dynamic memory allocation.

#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

//ERROR CHECKING: Functions that search or modify array always check if the given index is in bounds first.

void insert(double *&arr, int &size, int index, double num); //adds a double at given position of array and
//updates the size
void remove(double *&arr, int &size, int index); // same as insert except removes value
double get(double *arr, int size, int index); //returns index value at given index
void set(double *arr, int size, int index, double num); //sets element value at given index
void clear(double *&arr, int &size); //deallocates memory used for array and sets size to 0
int find(double *arr, int size, double num); //finds index where given value is found. returns -1 if not found
bool equals(double *arr1, int size1, double *arr2, int size2); //returns true if contents of two given arrays of same size are equal
void init(double *arr, int size); // makes array initialized from user input
void print(double *arr, int size); //prints array using for loop

#endif
