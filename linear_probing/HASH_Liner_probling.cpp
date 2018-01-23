#include<iostream>
using namespace std;

class DataItem
{
	public:
	int data;
	int key;
	
	DataItem(int k,int v)
	{
	key=k;data=v;
	}	
};

class HashTable
{
	public:
	int len;
	DataItem *arr[10];	
	
	int hashcode(int key)
	{
		return key%len;
	}
	
	void insert(int key,int value)
	{
		int index=hashcode(key);
		
		while(arr[index]!=NULL)
		{
			index++;
			index=hashcode(index);
		}
		DataItem *temp=new DataItem(key,value);
		arr[index]=temp;
	}
	
	void search(int key)
	{
		int index=hashcode(key);
		while(arr[index]!=NULL)
		{
			if(arr[index]->key==key)
			{
				cout<<"Found! : key = "<<arr[index]->key<<", data = "<<arr[index]->data<<endl;
				return;
			}
			index++;
			index=index%len;
		}
		cout<<"Key not found in table!"<<endl;
		return;
	}
	
	void delete_item(int key)
	{
		int index=hashcode(key);
		while(arr[index]!=NULL)
		{
			if(arr[index]->key==key)
			{
				cout<<"Deleting! : key = "<<arr[index]->key<<", data = "<<arr[index]->data<<endl;
				arr[index]->key=-1;
				arr[index]->data=0;
				return;
			}
			index++;
			index=index%len;
		}
		cout<<"Key not availble."<<endl;
	}
	
	void display()
	{
		for(int i=0;i<len;i++)
		{
			if(arr[i]!=NULL)
			{
				cout<<"Key = "<<arr[i]->key<<", Data = "<<arr[i]->data<<endl;
			}
			else
			{
				cout<<" key = --, Data = --"<<endl;
			}
		}
	}
	
	
	void try_fun()
	{
		DataItem * d = new DataItem(1,20);
		arr[0]=d;
		DataItem * d2 = new DataItem(2,40);
		arr[1]=d2;
		DataItem * d3 = new DataItem(4,20);
		arr[2]=d3;
		display();
		
	}
};

main()
{
	HashTable ht;
//	ht.insert(1,10);
//	ht.insert(9,90);
//	ht.insert(8,80);
//	ht.insert(8,70);
//	ht.insert(8,60);
//	ht.display();
ht.try_fun();
}




