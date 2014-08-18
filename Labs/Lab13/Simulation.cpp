#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#include <cmath>
#include <cstdlib> 
#include <cstring>
#include <ctime> 

const char* tab = "\t";
const char* inputFile = "Simulation.txt"; // Path of File



struct Customer
{
  int arrivalTime;
  int serviceTime; //time that the customer's service starts, either by arriving when a server is idle, or by moving out of the wait queue
  int completionTime;
  char id;
  Customer():arrivalTime(0),serviceTime(0),completionTime(0),id(' '){}
  Customer(int t, char c):arrivalTime(t),serviceTime(0),completionTime(0), id(c){}
};

struct ServiceEvent
{
  int eventTime; // time for the event to take place
  int serverNumber; // 
  ServiceEvent(int t, int s):eventTime(t),serverNumber(s){}
  bool operator<(const ServiceEvent& a) const {return (eventTime<a.eventTime)?true:false;}
  void operator=(const ServiceEvent& a){eventTime=a.eventTime;serverNumber=a.serverNumber;}
};

// requires cmath and cstdlib (and srand to seed the random number generator)
int getRandomNumberOfServiceRequests(double averageRequestsPerMinute)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerMinute);
  for (double randomValue = (double)rand() / RAND_MAX; 
    (randomValue -= probOfnRequests) > 0.0; 
    probOfnRequests *= averageRequestsPerMinute / (double)++requests);
  return requests;
}


int main()
{
  srand (time(NULL));
  int n=0, newArrivals, turnedAway=0;
  int servers, lenWaitQ, minServTime, maxServTime;
  float avgArriveRate, avgTime=0, tapm=0;
  char exit;
  ifstream fin(inputFile);
  if(fin.is_open())
  {
    fin >> servers >> avgArriveRate >> lenWaitQ >> minServTime >> maxServTime;
	cout << endl
		 << tab << servers << " - Number of servers" << endl
		 << tab << avgArriveRate << " - Average arrival rate of customer calls/minute" << endl 
		 << tab << lenWaitQ << " - Maximum length of each wait queue" << endl 
		 << tab << minServTime << " - Minimum service time, in minutes" << endl
		 << tab << maxServTime << " - Maximum service time, in minutes" << endl;
  }
  else 
	cout << "Could not open " << inputFile << endl;

  vector<Customer> servedCustomers;
  vector<Customer> serverForCustomer(servers);
  vector<bool> customerBeingServed (servers, false);
  priority_queue<ServiceEvent> mypq; //store the service events that get scheduled each time service begins
  vector<queue<Customer>*> waitQueue(servers);
  
  for(int i=0; i<servers; i++)
    waitQueue[i] = new queue<Customer>;

  for (int time=0;; time++) 
  {
    while(!mypq.empty() && mypq.top().eventTime==time)
	{
      ServiceEvent c = mypq.top(); mypq.pop();
	  int cServer = c.serverNumber;
	  serverForCustomer[cServer].completionTime = time;
	  servedCustomers.push_back (serverForCustomer[cServer]);
	  customerBeingServed[cServer] = false;
	}
	newArrivals=0;
	do newArrivals=getRandomNumberOfServiceRequests(avgArriveRate); 
	  while(newArrivals<0);
    while(newArrivals>0)
	{
	  int i, shortest;

	  char a = (char)('A' + (n++ % 26));
	  	  
	  Customer c(time, a);
//cout << c.id << " " << c.arrivalTime << endl;
	  for(shortest=0, i=1; i<servers; i++)
	  {
//cout << (int)waitQueue[shortest]->size() << tab << (int)waitQueue[i]->size() << endl;
	    if((int)waitQueue[shortest]->size()>(int)waitQueue[i]->size())
          shortest=i;
	  }
	   //shortest=i;}
	  if((int)waitQueue[shortest]->size()<lenWaitQ)
	    waitQueue[shortest]->push(c);
	  else
        ++turnedAway;
	  --newArrivals;
	}
	for(int i=0; i<servers; i++)
	{
	  if(!customerBeingServed[i] && !waitQueue[i]->empty())
	  {
		  serverForCustomer[i] = waitQueue[i]->front();
		  waitQueue[i]->pop();
		  serverForCustomer[i].serviceTime=time;
		  int timeToComplete = rand() % maxServTime + minServTime;
		  ServiceEvent e(timeToComplete, i);
		  mypq.push(e);
	  }
	}

    cout << endl << endl << endl
		 << "Time: " << time << endl
         << "--------------------------------" << endl
         << "line now serving waiting queue" << endl
	     << "---- ----------- ---------------" << endl;
    for(int i=0; i<servers; i++)
	{
      cout << "  " << i << "       " << serverForCustomer[i].id << "      ";
	  for(queue<Customer> q (*(waitQueue[i])); !q.empty(); q.pop())
		  cout << q.front().id;
	  cout << endl;
	}
	
	if(!servedCustomers.empty())
	{
	  avgTime=0;
	  for(int i=0; i<servedCustomers.size(); i++)
		avgTime += (float)(servedCustomers[i].completionTime - servedCustomers[i].arrivalTime);
	  avgTime /= (float)servedCustomers.size();
	}
	if(time>0) 
	  tapm=(float)turnedAway/time;
    cout << "--------------------------------\n";
	cout.precision(3);
    cout << fixed  << "Avg time: " << avgTime << ". Turned away per minute: " << tapm << endl;
  




	cout << "Enter to continue or X to exit: ";
	cin.get(exit);
	if(exit=='x' || exit=='X')
	  break;
  }

  return 0;
}


/*
void printReport()


// Press ENTER to continue, X-ENTER to exit...

*/