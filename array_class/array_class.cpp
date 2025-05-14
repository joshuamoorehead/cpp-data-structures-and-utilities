//Written by Joshua Moorehead

#include <iostream>
using namespace std;

//Function prototypes with arguments
void GetParameters(double &start, double &end, int &partitions);
double LeftRiemann(double start, double end, int partitions);
double RightRiemann(double start, double end, int partitions);
double FunctionCompute(double x);
double ExactIntegral(double start, double end);

int main(int argc, char **argv) {
	cout
			<< "Hello! In this program we will be calculating Riemann sums for the function: y = x^2"
			<< endl;
	double start(0);
	double end(1);
	int partitions(1);

	GetParameters(start, end, partitions);

	cout << "Interval: [" << start << ", " << end << "]" << endl;
	cout << "Partitions: " << partitions << endl;
	cout << "Left Riemann Sum: " << LeftRiemann(start, end, partitions) << endl;
	cout << "Right Riemann Sum: " << RightRiemann(start, end, partitions)
			<< endl;
	cout << "Exact Integral: " << ExactIntegral(start, end) << endl;

	return 0;

}
//Function description
void GetParameters(double &start, double &end, int &partitions) {

	cout
			<< "Enter start point of integration, end point of integration, and the number of partitions between them:";

	cin >> start >> end >> partitions;
}

double LeftRiemann(double start, double end, int partitions) { //need to sum up all rectangles using a for loop and a function call and a little math
	double length = (end - start) / partitions;
	double sum(0);

	for (int i = 0; i < partitions; i++) {
		double area = (FunctionCompute(start)) * length;
		sum += area;
		start += length;
	}
	return sum;
}
double RightRiemann(double start, double end, int partitions) {

	double length = (end - start) / partitions;
	double sum(0);

	for (int i = 0; i < partitions; i++) {
		start += length; //subtle difference between left and right riemann sums. need to move over x position first
		double area = (FunctionCompute(start)) * length;
		sum += area;

	}
	return sum;
}

double FunctionCompute(double x) { //in this case the function is y = x^2
	return (x * x);
}

double ExactIntegral(double start, double end) { //calculating exact integral (x^3/3)
	double diff = ((end * end * end) / 3) - ((start * start * start) / 3);
	return diff;
}

