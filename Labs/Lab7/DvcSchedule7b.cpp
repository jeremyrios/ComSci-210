#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include <cstring>

const char* tab = "\t";
const char* inputFile = "dvc-schedule.txt"; // Path of File

// the data element
struct SubjectCode
{
  string name;
  int count;
  SubjectCode():name(""), count(0){}
};

// the linked-list node
struct Node
{
  SubjectCode data;
  Node* next;
};

int main()
{
  Node* start=NULL;
  Node* p;
  Node* prev;

  char* token; // for parsing the inputfile
  char buf[1000];
  ifstream fin(inputFile);
  if(fin.is_open())
  {
    while (fin.good())// read the input file
    {
      string line;
      getline(fin, line); // read the line
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;
      string term(token = strtok(buf, tab)); // parse the line
      string section(token = strtok(0, tab));
      string course((token = strtok(0, tab)) ? token : "");
      string instructor((token = strtok(0, tab)) ? token : "");
	  string whenWhere((token = strtok(0, tab)) ? token : "");
	  if (course.find('-') == string::npos) continue; // skips an invalid line
      string subjectCode(course.begin(), course.begin() + course.find('-'));
	  if(start) // if linked list has at least one node
	  {
		int num = -1; // setinal value
		for (prev=0, p=start; p; prev=p, p=p->next) // traverse the list
		  if (p->data.name.compare(subjectCode)>=0) 
		  {
            num=p->data.name.compare(subjectCode); // set num = to string compare result
            break;
		  } 
		if(num==0) // 0 == exact match
          ++p->data.count; // incriment count 
		else if(num>0) //  new subCode goes before current node  
		  if(prev) // if there is a node before current node insert new node inbetween
		  {
	        prev->next = new Node;
			prev=prev->next;
		    prev->data.name = subjectCode;
		    ++prev->data.count;
		    prev->next = p;
		  }
		  else // else push a new node onto front of list
	      {
		    Node *temp; 
	        temp = new Node;
		    temp->data.name = subjectCode;
		    ++temp->data.count;
		    temp->next = start;
            start = temp; 
		  }
		else // else if no match found and at end of list add new node on to end of list
		{
	      prev->next = new Node;
		  prev=prev->next;
		  prev->data.name = subjectCode;
		  ++prev->data.count;
		  prev->next = 0;
		}
	  }
	  else // else if nothing in list create new node at start
	  {
        start = new Node;
		start->data.name = subjectCode;
        ++start->data.count;
		start->next=0;   
	  }
    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";

  cout << endl << "     Subject Code      Count \n\t--------------------\n";
  for(p=start; p; p=p->next)
  {
    cout << tab << p->data.name << tab << p->data.count << endl;
  }

  while (start) 
  { 
    p = start->next; 
    delete start; 
    start = p;
  }

  return 0;
}



