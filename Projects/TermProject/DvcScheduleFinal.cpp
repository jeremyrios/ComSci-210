#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

#include <cstring>

const char* tab = "\t";
const char* inputFile = "dvc-schedule-final.txt"; // Input File

int main()
{
  map<string, map<string,int> > myMap; // Map of maps - <subjectCode,<course,count> >
  map<string,map<string,int> >::iterator it1; // iterator for myMap
  map<string,int>::iterator it2; // iterator for inner map - <course,count>
  char* token; // for parsing the inputfile
  char buf[1000];
  ifstream fin(inputFile);
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

	  it1=myMap.find(subjectCode); // look for subjectCode in myMap
      if(it1 != myMap.end()) // if true found subjectCode match
	  {
		it2 = it1->second.find(course); // look for course in inner map
		if(it2 != it1->second.end()) // if true found course match
          it2->second++;
		else // did not find courses match
          it1->second[course]=1; // insert new course 
      }
      else // did not find subjectCode match
	    myMap[subjectCode][course]=1; // insert new subjectCode and new course

    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";
  for(it1=myMap.begin(); it1 != myMap.end(); it1++) // iterate outer map - <subjectCode,<course,count> >
  {
	cout << " " << it1->first << ", " << it1->second.size();
    if(it1->second.size()>1) // if more than 1 course
	  cout << " Courses " << endl;
	else
      cout << " Course " << endl;
	cout << " --------------------------------\n";
	for(it2=it1->second.begin(); it2 !=it1->second.end(); it2++) // iterate inner map - <course,count>
	{
	   string course(it2->first + ',');
       cout << tab << left << setw (13) << course << setw (4) << it2->second;
	   if(it2->second>1) // if more than 1 classes
	     cout << " Classes" << endl;
	   else
	     cout << " Class" << endl;
	}
	cout << endl << endl;
  }
  return 0;
}


