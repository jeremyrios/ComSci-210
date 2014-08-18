#include <iostream>
#include <iomanip>
#include "Checkbook.h"

using namespace std;

int menu();

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, QUIT = 4;

int main()
{
  float balance;
  cout<<"Enter the inital balance: $";
  cin>>balance;
  Checkbook<float> cb(balance);
  float amount;
  int choice;
  bool checkAccepted  = false;

  cout<<fixed<<setprecision(2);
  choice = menu();
  while(choice!=QUIT)
  {
	if(choice==CHECK)
	{
	  cout<<"Enter Check amount: $";
	  cin>>amount;
	  if(cb.writeCheck(amount))
	  {
		cout<<"Check accepted."<<endl;
		checkAccepted = true;
	  }
	  else
	  {
		  cout<<"Your balance is not high enough for that check."<<endl;
	  }
	}
	else if(choice==DEPOSIT)
	{
	  cout<<"Enter deposit ammount: $";
	  cin>>amount;
	  cb.deposit(amount);
	  cout<<"Deposit accepted."<<endl;
	}
	else
	{
	  amount = cb.getBalance();
	  cout<<"Your balance is: $"<<amount<<endl;
	}
	choice=menu();
  }
  if(checkAccepted)
  {
	  cout<<"Your last check was: $"<<cb.getLastCheck()<<endl;
	  CheckInfo<float> ci;
	  ci = cb.getLastChecks();
	  if(ci.numChecks>1)
	  {
		cout<<"Your last checks are:"<<endl;
	    for(int i=0; i<ci.numChecks; i++)
			cout<<"$"<<ci.checks[i]<<endl;
	  }
  }
  return 0;
}

int menu()
{
  int choice;
  cout<<endl
      <<"1    Write a check"<<endl
	  <<"2    Make a deposit"<<endl
	  <<"3    Get the balance"<<endl
	  <<"4    Quit"<<endl
	  <<"Enter a number betweeen 1 and 4: ";
  cin>>choice;
  return choice;
}