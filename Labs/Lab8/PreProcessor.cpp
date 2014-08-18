#include <fstream>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

#include <cstring>

int main()
{
  int error=0;

  stack<char> brackets;
  string filename;
  cout << "please enter input file name: ";
  getline( cin, filename );
  char* inputFile = (char*)malloc(sizeof(char)*(filename.length()+1));
  strcpy(inputFile, filename.c_str());

  ifstream fin(inputFile);
  if(fin.is_open())
  {
    for(int lineNum=1; fin.good(); lineNum++) // read the input file
    {
	  string line;
      getline(fin, line); // read the line
      for(int i=0; i<line.length(); i++)
	  {
	    if(line[i]=='{')
		{
		  if(brackets.empty()||brackets.top()!='('||brackets.top()!='[')
		    brackets.push(line[i]);
		  else 
		  {
			error = 6;
		    break;
		  }
		}
		else if(line[i]=='['||line[i]=='(')// left off here
		    brackets.push(line[i]);
		else if(line[i]=='/' && line[i+1]=='*')
		{
		  brackets.push(line[i]);
		  brackets.push(line[i+1]);
		}
		else if(line[i]==']')
		{
		  if(brackets.top()=='[')
		    brackets.pop();
		  else
		  {
			error = 1;
			break;
		  }
		}
		else if(line[i]==')')
		{
		  if(brackets.top()=='(')
		    brackets.pop();
		  else
		  {
			error = 2;
			break;
		  }
		}
		else if(line[i]=='}')
		{
			if(brackets.top()=='{')
		    brackets.pop();
		  else
		  {
			error = 3;
			break;
		  }
		}
		else if(line[i]=='*'&&line[i+1]=='/')
		{
		  if(brackets.top()=='*')
		  {
		    brackets.pop();
			brackets.pop();
		  }
		  else
		  {
			error = 4;
			break;
		  }
		}
	  }
	  if (error) break;
	}
	if(!error&&!brackets.empty())
	  error = 5;
    switch (error)
    {
	  case 0:
		cout << "No Errors" << endl;
	    break;
	  case 1:
		cout << "Error on Line number " << lineNum << ". Need to close " << brackets.top() << endl;
	    break;
	  case 2:
		cout << "Error on Line number " << lineNum << ". Need to close " << brackets.top() << endl;
	    break;
	  case 3:
		cout << "Error on Line number " << lineNum << ". Need to close " << brackets.top() << endl;
	    break;
	  case 4:
		cout << "Error on Line number " << lineNum << ". Need to close " << brackets.top() << endl;
	    break;
	  case 5:
		cout << "Error on Line number " << lineNum << ". Too many " << brackets.top() << endl;
	    break;
	  case 6:
		cout << "Error on Line number " << lineNum << ". Unable to put { without closing " << brackets.top() << endl;
	    break;
    }
  }
  else
	cout << "Unable to open input file" << endl;
}