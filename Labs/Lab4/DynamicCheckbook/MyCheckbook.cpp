#include <iostream>
#include <iomanip>
#include "Checkbook.h"

using namespace std;



int menu();

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, GET_CHECKS = 4, QUIT = 5;

int main()
{
  float balance;
  cout << "Enter the inital balance: $";
  cin >> balance;
  DynamicCheckbook cb(balance);
  float amount;
  int choice=0;
  bool checkAccepted  = false;
  bool loop = true;

  cout << fixed << setprecision(2);
  
  while(loop)
  {
	choice = menu();
	switch(choice)
    {
	  case CHECK:
	    cout << "Enter Check amount: $";
	    cin >> amount;
	    if(cb.writeCheck(amount))
	    {
		  cout << "Check accepted." << endl;
		  checkAccepted = true;
	    }
	    else
		  cout << "Your balance is not high enough for that check." << endl;
	    break;

	  case DEPOSIT:
	    cout << "Enter deposit ammount: $";
	    cin >> amount;
	    if(cb.deposit(amount))
	      cout << "Deposit accepted." << endl;
		else
		  cout << "You must enter a valid amount to deposit" << endl;
	    break;

	  case BALANCE:
	    amount = cb.getBalance();
	    cout << "Your balance is: $" << amount << endl;
		break;
  
      case GET_CHECKS:
	    if(cb.getNumChecksWritten())
	    {
		  Check* c= cb.getChecks();
	      cout << endl << "Your last checks are:" << endl;
	      for(int i=0; i<cb.getNumChecksWritten(); i++)
			  cout << "Check #: " << c[i].checkNumber << " for $" << c[i].amount << endl;
		  cout << endl << "You must free the dynamic array when you are" << endl
			   << "done with it in order to prevent memory leak\n\n";
	    }
		else 
		  cout << "You have not written any valid checks yet \n\n";
		break;

	  case QUIT:
	    loop = false;
		break;
	}
  }

  return 0;
}

int menu()
{
  int choice;
  cout << endl
       << "1)  Write a check"                << endl
	   << "2)  Make a deposit"               << endl
	   << "3)  Get the balance"              << endl
	   << "4)  Get Checks"                    << endl
	   << "5)  Quit"                         << endl
	   << "Enter a number betweeen 1 and 5: ";
  cin >> choice;
  return choice;
}