# HashMap

C++ implementation of HashTable is shown in the following files.

I have implemented both open hashing and close hashing.

#Introduction :
In open hashing, the tabel size is fixed and hash key,value pair is stored in that fized sized tabel.
Whereas in closed hashing,the table size is fixed but incase of key collision,new node is created and added at point of hash index ofcollision.
There are 3 types of open hashing.
1.Linear hashing : where at time of collision,value is stored at next possible free location.
2.Quadratic hashing : where at time of collision,value is stored at i*i(th) location,i being the iterator.
3.Double hashing : this method used double hashing to store value at time of collison.
