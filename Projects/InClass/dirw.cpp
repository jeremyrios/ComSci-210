#include <iostream>
#include <string>
using namespace std;

#include <windows.h>

void fun(string dir)
{
  WIN32_FIND_DATA fdata; // Windows defined data type
  HANDLE dhandle;        // Windows defined data type

  char buf[MAX_PATH];
  _snprintf(buf, sizeof(buf), "%s/*.*", dir.c_str()); 
  dhandle = FindFirstFile(buf, &fdata);

  if(dhandle != INVALID_HANDLE_VALUE)
  {
    while(FindNextFile(dhandle, &fdata))
    {
      if (fdata.dwFileAttributes == 16 && fdata.cFileName[0] != '.') 
	  {
	    fun(string(dir + '/' + fdata.cFileName));
	  }
      else if (fdata.dwFileAttributes != 16)
		cout << "  FILE: " << string(dir + '/' + fdata.cFileName) << endl;
    }
  }
  FindClose(dhandle);
}

int main()
{
  string dir = string("c:");
  fun(dir);


  return 0;
}