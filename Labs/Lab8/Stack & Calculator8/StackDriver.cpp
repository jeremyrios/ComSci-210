#include <iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{

    Stack<int> a;
	int peek ;
	assert(a.isEmpty()==true);
	assert(a.peek(peek)==false);
	a.push(100);
	assert(a.isEmpty()==false);
	assert(a.peek(peek)==true);
    assert(peek==100);
    assert(a.pop()==true);
	assert(a.isEmpty()==true);
	assert(a.peek(peek)==false);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);

    Stack<int> b = a;
    assert(b.isEmpty()==false);
	assert(b.peek(peek)==true);
    assert(peek==4);
    assert(b.pop()==true);
    assert(b.peek(peek)==true);
    assert(peek==3);
    assert(b.pop()==true);

    Stack<int> c; c = b;
	assert(c.peek(peek)==true);
    assert(peek==2);
    assert(c.pop()==true);
	assert(c.peek(peek)==true);
    assert(peek==1);
    assert(c.pop()==true);
	assert(c.isEmpty()==true);
	assert(c.peek(peek)==false);


  return 0;
}