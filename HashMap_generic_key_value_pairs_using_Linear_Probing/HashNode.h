//#include "stdafx.h"
#include<iostream>
using namespace std;

template<class K, class V>
class HashNode
{
private:
	V _value;
	K _key;
	HashNode(const HashNode&) = delete;
	HashNode& operator=(const HashNode&) = delete;
public:
	HashNode(const K &Key, const int &Value) :_value(Value), _key(Key) {
	}
	K get_key()const
	{
		return _key;
	}
	V get_value()const
	{
		return _value;
	}
	void set_value(const V Value)
	{
		_value = Value;
	}
	void set_key(const K Key)
	{
		_key = Key;
	}
};
