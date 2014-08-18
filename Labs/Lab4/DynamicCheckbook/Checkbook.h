#ifndef Checkbook_h
#define Checkbook_h

struct Check
{
  int checkNumber;
  float amount;
};

class DynamicCheckbook
{
  public:
	DynamicCheckbook();
    DynamicCheckbook(float initBalance);
    void setBalance(float amt){balance = amt;}

    float getBalance() const {return balance;}
    float getLastDeposit()const {return lastDeposit;}
	int getNumChecksWritten() const {return numChecksWritten;}

	bool writeCheck(float amt); //returns false if amount is greater than balence 
    bool deposit(float amt);
    Check* getChecks() const;

  private:
    Check* checks;
    float balance;
    int numChecks; // the number of checks (allocated memory) in the array
    int numChecksWritten; // the number of checks actually written in the array
    float lastDeposit;
    void doubleArray();
};

#endif