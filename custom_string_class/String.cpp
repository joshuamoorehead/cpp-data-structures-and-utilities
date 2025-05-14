//Written by Joshua Moorehead
//10/30/22 18:48:00

#include <iostream>
#include "String.h"

using namespace std;

String::String() {

	str = new char[NULL];
	strLength = 0;

}
String::String(char *str1, int size) {
	str = new char[size];
	strLength = size;
	for (int i = 0; i < size; i++) {
		str[i] = str1[i];
	} //using a deep copy
}
int String::length() {
	return strLength;
}
void String::clear() {
	delete str;
	str = new char[1];
	strLength = 0;
}
bool String::empty() {
	return (strLength == 0);
}
int String::find(String &substr, int startIndex) {
	if (startIndex > strLength - 1) //error checking if index is ok
		exit(1);
	for (int i = startIndex; i <= (strLength - substr.length()); i++) { //need a double loop to increment each index and check for matching substring
		int j = 0;
		while (str[i + j] == substr.str[j] && (j < substr.length())) {
			j++;
			if (j == substr.length())
				return i;

		}

	}
	return -1; //returning -1 if no match was found

}
void String::print() {
	for (int i = 0; i < strLength; i++) {
		cout << str[i];
	}
	cout << endl;
}
void String::append(String &rhs) { //to make more efficient, copied current object into new temp string then new object into temp, then delete str, then set str to that temp
	int newLength = strLength + rhs.length();
	char *temp = new char[newLength];
	for (int i = 0; i < strLength; i++) {
		temp[i] = str[i];
	}
	delete str;
	for (int i = strLength; i < newLength; i++) {
		temp[i] = rhs.str[i - strLength];
	}
	delete str;
	str = temp;
	strLength = newLength;
	delete temp;
}
void String::insert(int i, String &rhs) { //make more efficient, make new temp and copy things over, then point str at it. 3 for loops

	if (i > strLength - 1 || i < 0) {
		cout << "Invalid index. Goodbye." << endl;
		exit(1);
	}
	newLength = strLength + rhs.length();
	char *temp = new char[newLength];
	for (int j = 0; j < i; j++) {
		temp[j] = str[j];
	} //copying up until insert index
	for (int j = i; j < (i + rhs.length()); j++) {
		temp[j] = rhs.str[j - i];
	} //copying string into desired position
	for (int j = i + rhs.length(); j < newLength; j++) {
		temp[j] = str[j - rhs.length()];
	} //copying rest of temp into string now
	delete str;
	str = temp;
	strLength = newLength;
	delete temp;
}
void String::equal(String &rhs) {
	delete[] str; //no core dump here and prevents memory leak
	strLength = rhs.length();
	str = new char[strLength];
	for (int i = 0; i < rhs.length(); i++) {
		str[i] = rhs.str[i];
	}
}
bool String::equalequal(String &rhs) {
	if (strLength != rhs.length())
		return false;
	bool eq(true);
	for (int i = 0; i < strLength; i++) {
		if (str[i] != rhs.str[i])
			eq = false;
	}
	return eq;
}
