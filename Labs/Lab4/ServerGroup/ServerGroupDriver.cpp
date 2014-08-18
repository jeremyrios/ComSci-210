#include <iostream>

#include "ServerGroup.h"
#include "ServerGroup.h"

using namespace std;

#include <cassert>

int main()
{
  cout << "\n//////////////TESTING/////////////////\n\n";
  ServerGroup s1(6), s2;
  cout << "Declare Server Group S1(6), S2" << endl << endl;
  for(int i=0; i<6; i++)
    cout << "Sever S1: " << (i+1) << ": " << s1.getServers(i) << endl; 
  cout << "Special Server S1: " << s1.getSpServer() << endl << endl;
  assert(s1.serverFree()); // asserts a server is free at this time 
  assert(s1.spServerFree()); // asserts spServer is free at this time

  cout << "Populate Server Group S1" << endl << endl;
  s1.setServers(0,9); //sets servers (server#-1, seconds) 
  s1.setServers(1,7);
  s1.setServers(2,2);
  s1.setServers(3,3);
  s1.setServers(4,5);
  s1.setServers(5,8);
  s1.setSpServer(1); // sets sp server (seconds)
  for(int i=0; i<6; i++)
    cout << "Sever S1: " << (i+1) << ": " << s1.getServers(i) << endl; 
  cout << "Special Server S1: " << s1.getSpServer() << endl << endl;

  s2 = s1;
  cout << "Set S2 = S1" << endl <<endl;
  for(int i=0; i<6; i++)
    cout << "Sever S2: " << (i+1) << ": " << s2.getServers(i) << endl; 
  cout << "Special Server S2: " << s2.getSpServer() << endl << endl;
  assert(!s2.serverFree()); // asserts no servers are free at this time 
  assert(!s2.spServerFree()); // asserts spServer is not free at this time

  s2.decServers(); cout << "dec server group S2 servers\n\n";

  for(int i=0; i<6; i++)
    cout << "Sever S2: " << (i+1) << ": " << s2.getServers(i) << endl; 
  cout << "Special Server S2: " << s2.getSpServer() << endl << endl;


  ServerGroup s3 = s2;
  cout << "Declare Server Group S3 = S2" << endl << endl;
    for(int i=0; i<6; i++)
    cout << "Sever S3: " << (i+1) << ": " << s3.getServers(i) << endl; 
  cout << "Special Server S3: " << s3.getSpServer() << endl << endl;
  assert(!s3.serverFree()); // asserts no servers are free at this time 
  assert(s3.spServerFree()); // asserts spServer is free at this time

  s3.decServers(); cout << "dec server group S3 servers\n\n";

  for(int i=0; i<6; i++)
    cout << "Sever S3: " << (i+1) << ": " << s3.getServers(i) << endl; 
  cout << "Special Server S3: " << s3.getSpServer() << endl << endl;
  assert(s3.serverFree()); // asserts a server is free at this time 
  assert(s3.spServerFree()); // asserts spServer is free at this time
  s3.useServer(8); // sets free server to 8 seconds (av trans time)
  s3.usespServer(8); // sets free special server to 8 seconds (av trans time)
  assert(s3.getServers(2)==8); // makes sure previous function calls worked
  assert(s3.getSpServer()==8);

 
  cout << "////////////END OF TEST///////////////\n\n";
  return 0;
}

