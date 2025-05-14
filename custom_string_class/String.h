//Written by Joshua Moorehead on 10/30/22
//This program uses a class called String and various functions to use the object (a character array)

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

class String {

public:
	String(); //default constructor. sets data types to default values. (length=0)
	String(char*, int size); //alternate constructor. sets data types to specified values in the parameters.
	~String() {
		delete[] str;
	} // destructor
	int length(); //takes no parameters and returns the value of the length of the string (character array)
	void clear(); //takes no parameters and erases the contents of the string, so it is empty. (length gets updated to 0 too)
	bool empty(); //takes no parameters and returns a boolean value that is (1) if the string is empty or (0) if it has contents
	int find(String &substr, int startIndex); //parameters are a substring of atleast one character and not bigger than the string being checked (if the substring is invalid size the program exits) and the starting index for iteration to look for a matching substring. returns int value of index where substring is found (if not found returns -1)
	void print(); //takes no parameters and prints out the string to stdout using a for loop for the character array
	void append(String &rhs); //takes in another string and adds the string to the end of the current string
	void insert(int i, String &rhs); //takes in index of insertion and another string and inserts it into the original string at that index. if index is invalid, the program exits
	void equal(String &rhs); //takes in a string object and copies over the data to it. essentially a copy constructor
	bool equalequal(String &rhs); //takes in a string object and returns true iff the two strings are indentical in content and size. if not, it returns false. 

private:
	int strLength; //making critical data members private because they do not need to be visible to other objects
	char *str;

};

#endif 
