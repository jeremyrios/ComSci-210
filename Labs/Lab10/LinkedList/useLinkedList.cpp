#include<iostream>
#include "LinkedList.h"

using namespace std;

LinkedList<int> getElements();

float calcAverage(LinkedList<int> &nums);

int main()
{
  bool loop1=true, loop2=false;
  int playAgain;
  while(loop1)
  {
    int input, inArray;
    LinkedList<int> nums;
    nums = getElements();
    LinkedList<int> nums2 =  nums;
	if(nums2.length()>0)
	{
	  float avg = calcAverage(nums2);
	  cout << "The average is: " << avg << endl;
	  loop2=true;
	}
    while(loop2)
    {
      cout << "Enter a number and I'll tell you if its in the Linked List: ";
      cin >> input;
      inArray = nums2.find(input);
      if(!inArray)
        cout<<"I'm sorry that number is not in the Linked List\n";
      else
        cout << "That number is at idex #: " << nums2.getCurentIndex() << endl;
      cout << "Try again? (1 for yes or 2 for no): ";
      cin >> input;
      (input==1)?loop2=true:loop2=false;
    }
	int data, i=0;
	cout << "\nThis is the contents of your Linked list and their indexs" << endl;
	if (nums2.first(data)) do {cout << i++ << ": " << data << endl;}
	  while (nums2.getNext(data));  
    cout << "Start over and play again? (1 for yes or 2 for no): ";
    cin >> playAgain;
    (playAgain==1)?loop1=true:loop1=false;
  }
  return 0;
}

LinkedList<int> getElements()
{
  cout <<"getElements called."<< endl;
  LinkedList<int> numbers;
  int input=0;
  while(input!=-1)
  {
	cout<<"Enter a positive integer (enter -1 to stop): ";
	cin >> input;
	if(input!=-1)
      numbers.insert(input);
  }
  return numbers;
}

float calcAverage(LinkedList<int> &nums)
{
	cout << "calcAverage called." << endl;
    float sum=0, avg=0;
	int data;
    if (nums.first(data)) do {sum +=data;}
	  while (nums.getNext(data));  
	avg = sum/(nums.length());
	return avg;
}