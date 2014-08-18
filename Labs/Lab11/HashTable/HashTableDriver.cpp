#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "HashTable.h"
#include "HashTable.h"

#include <cassert>
#include <cstring>

const char* tab = "\t";
const char* inputFile = "dvc-schedule.txt"; // Path of File

struct Record
{
  string course;
  string term;
  string instructor;
  int hashCode() const;
  bool operator==(const Record& a){return (course==a.course&&term==a.term)?true:false;}
};

int Record::hashCode() const
{
  int i, desiredIndex=0;
  string s(course + term); 
  for(i=0; i<s.length(); i++)
	desiredIndex += (int)s[i];
  desiredIndex *= desiredIndex;  
  return desiredIndex;
}


int main()
{
  HashTable<Record> hash1;
  Record r, s = {"COMSC-265", "Fall 2001", 	"Burns"};
  Record t = {"COMSC-265", "Fall 2001", ""};
  
  assert(hash1.empty());
  cout << "Size of hash table 1 is: " << hash1.size() << endl;

  char* token; // for parsing the inputfile
  char buf[1000];
  ifstream fin(inputFile);

  if(fin.is_open())
  {
    while (fin) // read the input file
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

	  r.term = term;
	  r.course = course;
	  r.instructor = instructor;
	  hash1.insert(r);
    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";

  assert(!hash1.empty());
  cout << "Size of hash table 1 is: " << hash1.size() << endl;
  assert(hash1.retrieve(t));
  cout << "t's new instructor is now: " << t.instructor 
	   << " - expect Montante bc of retrieve" << endl;
  assert(hash1.replace(s));
   assert(hash1.retrieve(t));
  cout << "t's new instructor is now: " << t.instructor 
	   << " - expect Burns bc of replace" << endl;

  HashTable<Record> hash2=hash1;
  cout << "Size of hash table 2 is: " << hash2.size()
	   << " expect same as table 1" << endl;
  hash1.clear();
  assert(hash1.empty());
  assert(hash1.size()==0);
  assert(hash2.remove(s));

  HashTable<Record> hash3; hash3=hash2;
  cout << "Size of hash table 3 is: " << hash3.size() 
	   << " - expect 1 less than table 2 bc of remove" << endl;

  hash2.clear();
  hash3.clear();
  cout << "Clear table 2 and 3" << endl
	   << "Size of hash table 1 is: " << hash1.size() << endl
       << "Size of hash table 2 is: " << hash2.size() << endl
       << "Size of hash table 3 is: " << hash3.size() << endl;
  return 0;
}
