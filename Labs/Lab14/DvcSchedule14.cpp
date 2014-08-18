#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <cstring>

const char* tab = "\t";
const char* inputFile ("dvc-schedule.txt"); // Path of File

struct Record
{
  string name;
  int count;
  bool operator<(const Record &a) const {return (name<a.name)?true:false;}
};

ostream& operator<<(ostream& output, const Record& r) 
{
    output.width(6); output << left << r.name << tab << tab << r.count;
    return output;  // allows for cout of record
}

bool compare(const Record &a, const Record &b) {return (a<b);}

int main()
{
  vector<Record> SubjectCodes;

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

	  //cout << term << '|' << section << '|' << course << '|' << instructor << '|' << whenWhere << '|' << subjectCode << endl;
	  
	  if(SubjectCodes.size())
	  {
		for(int i=0; i<SubjectCodes.size(); i++)
		{
          if(SubjectCodes[i].name == subjectCode)
		  {
		    SubjectCodes[i].count++; //cout << SubjectCodes[i] << "\r";      testing 
			break;
		  }
		  if(i==SubjectCodes.size()-1)
		  {
	        Record r;
		    r.name = subjectCode;
		    r.count = 1;
		    SubjectCodes.push_back(r); //cout << endl << r << "\r";             testing
	      }
		}
	  }
	  else
	  {
	    Record r;
		r.name = subjectCode;
		r.count = 1;
		SubjectCodes.push_back(r); //cout << r << "\r";                     testing
	  }
    }
    fin.close();
  }
  else 
    cout << "Unable to open input file\n";

  sort (SubjectCodes.begin(), SubjectCodes.end(), compare); // sorted using algorithm sort                                                                       
  cout << endl << "     Subject Code      Count \n\t--------------------\n";
  for(int i=0; i<SubjectCodes.size(); i++)
  {
    cout << tab << SubjectCodes[i] << endl;
  }
  return 0;
}


