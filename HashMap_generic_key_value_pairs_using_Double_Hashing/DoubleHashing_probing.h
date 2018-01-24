#pragma once
#include<iostream>
#include"HashNode.h"
#include"GenrateKey.h"
using namespace std;


template<class K, class V, size_t TABLE_SIZE>
class HashMap
{
private:

	HashNode<K, V> **table;
	GenrateKey<K, TABLE_SIZE> genrate_key;
	int size;
	HashNode<K, V> *dummy;
public:
	HashMap()
	{
		table = new HashNode<K, V>*[TABLE_SIZE];
		for (int i = 0; i<TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
		dummy = new HashNode<K, V>(-1, -1);
	}

	unsigned long Hash_function2(K key)
	{
		//cout << endl;
		//cout << " - HashFuncation2 returns" << (unsigned long)(key % (int)(TABLE_SIZE)) << endl;
		return (unsigned long)(key % (int)(TABLE_SIZE));
	}

	void put(const K key, const V value)	{
		HashNode<K, V> *temp = new HashNode<K, V>(key, value);
		unsigned long hash_index = genrate_key(key);
		int i = 0;
		while (table[hash_index] != NULL && table[hash_index]->get_key() != key)
		{
			i++;
			hash_index = hash_index + i*Hash_function2(key);
			hash_index %= TABLE_SIZE;		
		}
		if (table[hash_index] == NULL || table[hash_index]->get_value() == -1)
			size++;
		//cout << "put:hash_index is " << hash_index;
		table[hash_index] = temp;
	}
	void remove(const K key)	{
		unsigned long hash_index = genrate_key(key);
		int i = 0;
		while (table[hash_index] != NULL)
		{
			if (i == TABLE_SIZE)break;
			if (table[hash_index]->get_key() == key)
			{
				table[hash_index] = dummy;
				size--;
				return;
			}
			i++;
			hash_index = hash_index + i*Hash_function2(key); 
			hash_index %= TABLE_SIZE;	
		}
		//cout << "returning from get" << hash_index << endl;
		return;
	}
	bool get(const K key, V &value)
	{
		unsigned long hash_index = genrate_key(key);
		int i = 0;
		while (table[hash_index] != NULL)
		{
			if (i == TABLE_SIZE)break;
			if ((K)table[hash_index]->get_key() == key)
			{
				value = table[hash_index]->get_value();
				return true;
			}
			i++;
			hash_index = hash_index + i*Hash_function2(key);
			hash_index %= TABLE_SIZE;
		}
		return false;
	}
	void display()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != NULL && table[i]->get_value() != -1)
				cout << "Index " << i << " : " << table[i]->get_key() << "-" << table[i]->get_value() << endl;
			else
				cout << "Index " << i << " : " << "  x		x" << endl;
		}
	}

};