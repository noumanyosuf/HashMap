#pragma once
//#include "stdafx.h"

#include<iostream>
using namespace std;

template<class K, size_t TABLE_SIZE>
class GenrateKey {
public:
	unsigned long operator()(const K &key)const
	{
		//return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;.
		return (unsigned long)(key % TABLE_SIZE);
	}
};
