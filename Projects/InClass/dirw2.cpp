#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include <windows.h>

int main()
{
  string dir = string("c:");

  WIN32_FIND_DATA fdata;
  HANDLE dhandle;

  char buf[MAX_PATH];
  _snprintf(buf, sizeof(buf), "%s/*.*", dir.c_str());
  dhandle = FindFirstFile(buf, &fdata);

  if(dhandle != INVALID_HANDLE_VALUE)
  {
    while(FindNextFile(dhandle, &fdata))
    {
      if (fdata.dwFileAttributes == 16 && fdata.cFileName[0] != '.') cout << "FOLDER: " << string(dir + '/' + fdata.cFileName) << endl;
      else if (fdata.dwFileAttributes != 16) cout << "  FILE: " << string(dir + '/' + fdata.cFileName) << endl;
  } }
  FindClose(dhandle);

  return 0;
}