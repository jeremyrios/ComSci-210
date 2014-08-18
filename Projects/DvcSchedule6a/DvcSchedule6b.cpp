#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <cstring>

const char* tab = "\t";
const char* inputFile = "dvc-schedule.txt"; // Input File

struct Course
{
  string name;
  int count;
  Course():name(""), count(0){}
};

ostream& operator<<(ostream& output, const Course &c) // const
{
    if(c.count>1)
	{
	  output << left << c.name << ", " << c.count << " classes";
      return output;  // allows for cout of record
	}
	else
	{
	  output << left << c.name << ", " << c.count << "  class";
      return output;  // allows for cout of record
	}
}

bool operator>(const Course &a, const Course &b){return (a.name>b.name)?false:true;}

bool compareCourse(const Course &a, const Course &b) {return (a>b);}

struct SubjectCode
{
  string name;
  vector<Course> courses; 
};

bool operator>(const SubjectCode &a, const SubjectCode &b){return (a.name>b.name)?false:true;}

bool compareSubjectCode(const SubjectCode &a, const SubjectCode &b) {return (a>b);}


int main()
{
  vector<SubjectCode> subjectCodes;
  int i=0,j=0;
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
      string course((token = strtok(0, tab)) ? token : "");
      string instructor((token = strtok(0, tab)) ? token : "");
	  string whenWhere((token = strtok(0, tab)) ? token : "");
	  if (course.find('-') == string::npos) continue; // skips an invalid line
      string subjectCode(course.begin(), course.begin() + course.find('-'));

	  if(subjectCodes.size())
	  {
	    for(i=0; i<subjectCodes.size(); i++)
		{
          if(subjectCodes[i].name == subjectCode)
			break;
		}
        if(i<subjectCodes.size()) // found subjectCode match
		{
		  for(j=0; j<subjectCodes[i].courses.size(); j++)
		  {
            if(subjectCodes[i].courses[j].name == course)
			  break;
		  }
		  if(j<subjectCodes[i].courses.size())
            ++subjectCodes[i].courses[j].count;
		  else // did not find subjectCode.courses match. must create new course and push
		  {
		    Course c;
		    c.name = course;
		    ++c.count;
		    subjectCodes[i].courses.push_back(c);
		  }
		}
        else // did not find subjectCode match. must create new subjectCode and push
		{
	      SubjectCode sc;
		  sc.name = subjectCode;
		  Course c;
		  c.name = course;
		  ++c.count;
		  sc.courses.push_back(c);
          subjectCodes.push_back(sc);
	    }
	  }
	  else
	  {
		SubjectCode sc;
		sc.name = subjectCode;
		Course c;
		c.name = course;
		++c.count;
		sc.courses.push_back(c);
        subjectCodes.push_back(sc); //cout << r << endl << endl;    testing
	  }
    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";
  sort(subjectCodes.begin(), subjectCodes.end(), compareSubjectCode); // sorted using algorithm sort 
  for(int i=0; i<subjectCodes.size(); i++)
  {
    sort(subjectCodes[i].courses.begin(), subjectCodes[i].courses.end(), compareCourse); // sorted using algorithm sort   
  }
  for(int i=0; i<subjectCodes.size(); i++)
  {
	cout << tab << subjectCodes[i].name << ", " << subjectCodes[i].courses.size();
    if(subjectCodes[i].courses.size()>1)
	{
	  cout << " courses " << endl;
	}
	else
      cout << " course " << endl;
	for(j=0; j<subjectCodes[i].courses.size(); j++)
	{
       cout << tab << tab << subjectCodes[i].courses[j] << endl;
	}
  }
  return 0;
}



