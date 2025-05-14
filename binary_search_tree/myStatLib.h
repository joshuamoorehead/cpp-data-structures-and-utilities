/*
 * Written by Joshua Moorehead
 * Sep 15, 2022 23:38
 * This program will take in user input to create an array of type double, and it will calculate some simple values and sort the array.
 * The inputs: array size and values
 * The outputs: minimum value, maximum value, mean value, median value, the sorted array elements
 * */

#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

//header file with function declarations to keep my code simpler and functional. It saves time by allowing me to import declarations 

double min(double arr[], int size); //parameters for each function are simply the array and its size
double max(double arr[], int size);
double mean(double arr[], int size);
double median(double arr[], int size);
void sort(double arr[], int size);
void readArray(double arr[], int size);
void printArray(double arr[], int size);

#endif
