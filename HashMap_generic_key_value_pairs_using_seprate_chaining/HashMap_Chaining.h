#pragma once
//#include "stdafx.h"

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
public:
	HashMap()
	{
		table = new HashNode<K, V>*[TABLE_SIZE];
		for (int i = 0; i<TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

	bool get(const K key, V &value)
	{
		unsigned long hash_index = genrate_key(key);
		HashNode<K, V> *entry = table[hash_index];
		while (entry != NULL)
		{
			if (entry->get_key() == key)
			{
				value = entry->get_value();
				return true;
			}
			entry = entry->get_next();
		}
		return false;
	}

	void put(const K key, const V value)
	{

		unsigned long hash_index = genrate_key(key);
		HashNode<K, V> *entry = table[hash_index];
		HashNode<K, V> *prev = NULL;

		while (entry != NULL && entry->get_key() != key)
		{
			prev = entry;
			entry = entry->get_next();
		}

		if (entry == NULL)//value not present
		{
			entry = new HashNode<K, V>(key, value);
			if (prev == NULL)//no element in hash
			{
				table[hash_index] = entry;
			}
			else//insert at last
			{
				prev->set_next(entry);
			}
		}
		else//element present, updating it
		{
			entry->set_value(value);
		}
	}
	void remove(const K key)
	{
		unsigned long hash_index = genrate_key(key);
		HashNode<K, V> *entry = table[hash_index];
		HashNode<K, V> *prev = NULL;

		while (entry != NULL && entry->get_key() != key)
		{
			prev = entry;
			entry = entry->get_next();
		}

		if (entry == NULL)//value not present
		{
			return;
		}
		else//element present, updating it
		{
			if (prev == NULL)
			{
				table[hash_index] = entry->get_next();
			}
			else
				prev->set_next(entry->get_next());

			delete entry;
		}
	}
	~HashMap()
	{
		//delete all inside HashNode in table
		for (int i = 0; i<TABLE_SIZE; i++)
		{
			HashNode<K, V> *entry;
			entry = table[i];
			while (entry != NULL)
			{
				HashNode<K, V> *prev = entry;
				entry = entry->get_next();
				delete prev;
			}
		}
		delete[]table;
	}
};
