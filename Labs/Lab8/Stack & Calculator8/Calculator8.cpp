#include<iostream>
#include <string>
using namespace std;

#include<cstdlib>

#include "Stack.h"

int main()
{
  bool loop = true, stillGettingInput;
  double a, b, c;
  string buffer;
  Stack<double> mystack1, mystack2;
  cout << "Please enter numbers one at a time followed by an operation (+,-,*,/) \n"
	   << "or enter Q or q to quit" << endl;
  while(loop)
  
    stillGettingInput = true;
   
    while(stillGettingInput)
    {
      cin >> buffer;
      cin.ignore(1000,10);
      if(!((buffer=="Q"||buffer=="q")||buffer=="+"||buffer=="-"||buffer=="*"||buffer=="/"))
      {
        mystack1.push(atof(buffer.c_str()));
        mystack2 = mystack1;
      }
      else if(buffer=="Q"||buffer=="q")
      {
        stillGettingInput = false;
        loop = false;
	  }
      else if((int)mystack1.size()>=2)
      {
        stillGettingInput = false;
        if(buffer=="+")
        {
          mystack1.peek(a); mystack1.pop();
		  mystack1.peek(b); mystack1.pop();
		  mystack1.push(a+b);
          mystack2 = mystack1;
        }
        else if(buffer=="-")
        {
          mystack1.peek(a); mystack1.pop();
		  mystack1.peek(b); mystack1.pop();
		  mystack1.push(a-b);
          mystack2 = mystack1;
        }
        else if(buffer=="*")
        {
		  mystack1.peek(a); mystack1.pop();
		  mystack1.peek(b); mystack1.pop();
		  mystack1.push(a*b);
          mystack2 = mystack1;
        }
        else if(buffer=="/")
        {
		  mystack1.peek(a); mystack1.pop();
		  mystack1.peek(b); mystack1.pop();
		  mystack1.push(a/b);
          mystack2 = mystack1;
        }
      }
	  else
	  {
		cout << "Im sorry but there must be more than 1 number in stack to perform an operation!\n"
			 << "Please enter at least one more number and then try again\n\n";
	  }
	  if (loop)
	  {
		double value;
        while (!mystack1.isEmpty())
        {
		  mystack1.peek(value);
          cout << " " << value;
          mystack1.pop();
        }  
	    cout << ' ';
        mystack1 = mystack2;
	  }
    }
  }
  return 0;
}