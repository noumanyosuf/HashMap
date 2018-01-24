// HashMap.cpp : Defines the entry point for the console application.
//Hash_Map_generic_type key_value_pairs_using_separate chaining

//#include "stdafx.h"
#include<iostream>
#include"Quadratic_probing.h"
using namespace std;

int main()
{
	HashMap<int,int,128> hmap;
	hmap.put(1, 10);
	hmap.put(11, 110);
	hmap.put(2, 20);
	hmap.put(5, 50);

	int value;
	if (hmap.get(1, value))
		cout << "Featched value is " << value << endl;
	else
		cout << "Not found in hash" << endl;

	hmap.remove(2);

	if (hmap.get(2, value))
		cout << "Featched value is " << value << endl;
	else
		cout << "Not found in hash" << endl;
	
	return 0;
}
