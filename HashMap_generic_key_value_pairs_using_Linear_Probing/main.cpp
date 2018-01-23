// Linearhasing.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "HashMap_LinearProbing.h"
using namespace std;
int main()
{
	HashMap<int, int, 100> m;
	m.put(1, 10);
	m.put(2, 20);
	m.put(3, 30);
	int value;
	if (m.get(1, value))
		cout << "found " << value << endl;
	else
		cout << "Not found" << endl;
	m.remove(1);
	if (m.get(1, value))
		cout << "1 found " << value << endl;
	else
		cout << "Not found" << endl;

	return 0;
}

