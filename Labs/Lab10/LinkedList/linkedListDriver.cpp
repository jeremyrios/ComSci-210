#include <iostream>
using namespace std;

#include <cassert>

#include "LinkedList.h"
#include "LinkedList.h"

int main()
{
    LinkedList<int> a;
	int peek, pop, data, i;
	
	assert(a.isEmpty()==true);
	assert(a.first(peek)==false);
	a.insert(100);
	assert(a.isEmpty()==false);
	assert(a.first(peek)==true);
	a.insert(200);
	a.insert(50);
	a.insert(20);


	LinkedList<int> b(a);
	b.insert(400);
	b.insert(66);
	cout << "contents of Linked list A with a lenth of " << a.length() << endl;
	for(i=0; !a.isEmpty(); i++)
	{
	  a.first(data);
	  cout << i << ": " << data << endl;
	  a.remove(data);
	}

    cout << "contents of Linked list B with a lenth of " << b.length() << endl;
	i=0;
    if (b.first(data)) do {cout << i++ << ": " << data << endl;}
	  while (b.getNext(data));  


	LinkedList<int> c; c = b;
    c.insert(37);
	c.insert(55);
	cout << "contents of Linked list C with a lenth of " << c.length() << endl;
	i=0;
    if (c.first(data)) do {cout << i++ << ": " << data << endl;}
	  while (c.getNext(data));  

    cout << "c[0]= " << c[0] << endl;
	cout << "c[2]= " << c[2] << endl;
	cout << "c[7]= " << c[7] << endl;
	cout << "c[5]= " << c[5] << endl;
	cout << "c[3]= " << c[3] << endl;
	cout << "c[4]= " << c[4] << endl;
	cout << "c[1]= " << c[1] << endl;
	a.makeEmpty();
	b.makeEmpty();
	c.makeEmpty();

	assert(a.isEmpty()==true);
	assert(b.isEmpty()==true);
	assert(c.isEmpty()==true);
	
  return 0;
}