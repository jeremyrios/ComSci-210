#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

#include <cstring>

const char* tab = "\t";

int main()
{
  map<string, map<string,int> > myMap; // Map of maps - <subjectCode,<course,count> >
  map<string,map<string,int> >::iterator it1; // iterator for myMap
  char* token; // for parsing the inputfile
  char buf[1000];
  ifstream fin("dvc-schedule-final.txt");
  if(fin.is_open())
  {
    while (fin.good()) // read the input file
    {
      string line;
      getline(fin, line); // read the line
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;
      string term(token = strtok(buf, tab)); // parse the line
      string section(token = strtok(0, tab));
      string course((token = strtok(0, tab)) ? token : ""); // get course
      string instructor((token = strtok(0, tab)) ? token : "");
	  string whenWhere((token = strtok(0, tab)) ? token : "");
	  if (course.find('-') == string::npos) continue; // skips an invalid line
      string subjectCode(course.begin(), course.begin() + course.find('-')); // get subjectCode

	  myMap[subjectCode][course]+=1; // the golden line
    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";
  for(it1=myMap.begin(); it1 != myMap.end(); it1++) // iterate outer map - <subjectCode,<course,count> >
  {
	cout << " " << it1->first << ", " << it1->second.size() << " Course(s) " << endl << " --------------------------------\n";
	for(map<string,int>::iterator it2=it1->second.begin(), ; it2 !=it1->second.end(); it2++) // iterate inner map - <course,count>
	{
	   string course(it2->first + ',')
       cout << tab << left << setw (13) << course << setw (4) << it2->second << " Classe(s)" << endl;
	}
	cout << endl << endl;
  }
  return 0;
}


