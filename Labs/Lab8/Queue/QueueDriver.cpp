#include <iostream>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h"

int main()
{

    Queue<int> a;
	int peek, pop;
	assert(a.isEmpty()==true);
	assert(a.peek(peek)==false);
	a.push(100);
	assert(a.isEmpty()==false);
	assert(a.peek(peek)==true);
    assert(peek==100);
    assert(a.pop(pop)==true);
	assert(pop==100);
	assert(a.isEmpty()==true);
	assert(a.peek(peek)==false);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);

    Queue<int> b = a;
    assert(b.isEmpty()==false);
	assert(b.peek(peek)==true);
    assert(peek==1);
    assert(b.pop(pop)==true);
    assert(b.peek(peek)==true);
    assert(peek==2);
    assert(b.pop(pop)==true);

    Queue<int> c; c = b;
	assert(c.peek(peek)==true);
    assert(peek==3);
    assert(c.pop(pop)==true);
	assert(c.peek(peek)==true);
    assert(peek==4);
    assert(c.pop(pop)==true);
	assert(c.isEmpty()==true);
	assert(c.peek(peek)==false);

	a.makeEmpty();
	b.makeEmpty();
	c.makeEmpty();

	assert(a.isEmpty()==true);
	assert(b.isEmpty()==true);
	assert(c.isEmpty()==true);
  return 0;
}