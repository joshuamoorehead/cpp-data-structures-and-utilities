//10/30/22 22:58
//front-end for String Class

#include <iostream>
#include "String.h"
using namespace std;

int main(int argc, char **argv) {
	char m1[] = "Hello World";
	char m2[] = "Append";
	char m3[] = "INSERT";

	String str1(m2, sizeof(m2) - 1);
	String str2(m1, sizeof(m1) - 1);
	String str3(m1, sizeof(m1) - 1);
	String str4;
	String substr(m2, sizeof(m2) - 1);
	String substr2(m3, sizeof(m2) - 1);

	cout << endl << "Test of constructors, print, and length" << endl;
	cout << "str1 has length: " << str1.length() << endl;
	str1.print();
	cout << "str2 has length: " << str2.length() << endl;
	str2.print();
	cout << "str3 has length: " << str3.length() << endl;
	str3.print();
	cout << "str4 has length: " << str4.length() << endl;
	str4.print();

	cout << endl << "Test of equal" << endl;
	str4.equal(str3);
	cout << "str4 length: " << str4.length() << endl;
	cout << "str4: ";
	str4.print();

	cout << "Test of append" << endl;
	str3.append(substr);
	cout << "str3: ";
	str3.print();
	cout << "Length of str3: " << str3.length() << endl;

	cout << "Test of insert" << endl;
	str3.insert(0, substr2);
	cout << "str3: ";
	str3.print();
	cout << "Length of str3: " << str3.length() << endl;

	cout << "Test of find" << endl;
	cout << "Found at: " << str3.find(substr, 5) << endl;
	cout << "Found at: " << str3.find(substr2, 5) << endl;

	cout << argc << end;

	return 0;
}
