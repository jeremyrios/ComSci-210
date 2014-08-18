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
  Node* q;

  char* token; // for parsing the inputfile
  char buf[1000];
  ifstream fin(inputFile);
  if(fin.is_open())
  {
    while (fin.good())
 // read the input file
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

	  if(start)
	  {
		for (p=start; p; p=p->next)
          if (p->data.name == subjectCode)
            break;
        if(p)
          ++p->data.count;
        else
		{
		  Node *temp;
	      temp = new Node;
		  temp->data.name = subjectCode;
		  ++temp->data.count;
		  temp->next = start;
          start = temp;          //cout << tab << "testing 3" << endl;	// tester
		}
	  }
	  else
	  {
        start = new Node;
		start->data.name = subjectCode;
        ++start->data.count;
		start->next=0;    //cout << tab << "testing 2" << endl;	// tester
	  }
    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";


  for (p=start; p; p=p->next)
  {
    for (q=p->next; q; q=q->next)
    {
      if (p->data.name.compare(q->data.name) > 0)
      {
        SubjectCode temp;
		temp.name = p->data.name;
		temp.count = p->data.count;
        p->data.name = q->data.name;
		p->data.count = q->data.count;
        q->data.name = temp.name;
		q->data.count = temp.count; //cout << tab << "testing 1" << endl;	// tester
   } } }                                                                       


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



