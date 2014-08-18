#include<iostream>
#include "SortableArray.h"

using namespace std;

Array<int> getElements();

float calcAverage(Array<int> avnums);

int main()
{
  bool loop=true;
  int num, inArray;
  Array<int> nums(2);
  nums=getElements();
  Array<int> nums2=nums;
  float average=calcAverage(nums2);
  cout<< "The size of array is: "<<nums2.length()<<endl;
  cout<<"The average is: "<<average<<endl;

  cout << "Your array currently looks like this:\n";
  for(int i=0; i<nums2.length(); i++)
	  cout<<" a["<<i<<"] = "<<nums2[i]<<endl;
  cout<<endl;
  int index1, index2;
  cout<<"Enter a starting index & an ending index seperated by a space\n and i'll sort everything inbetween: "; 
  cin>>index1>>index2;
  nums2.sort(index1, index2);
  cout << "Your array now looks like this:\n";
  for(int i=0; i<nums2.length(); i++)
	cout<<" a["<<i<<"] = "<<nums2[i]<<endl;
  cout<<endl;

  while(loop)
  {
    cout<<"Enter a number and I'll sort the whole array & tell you if its in the array: ";
    cin>>num;
    inArray=nums2.bsearch(num);
    if(inArray==-1)
      cout<<"I'm sorry that number is not in the array\n";
    else
      cout<<"That number is at idex #: "<<inArray<<endl;

	cout << "Your array now looks like this:\n";
    for(int i=0; i<nums2.length(); i++)
	  cout<<" a["<<i<<"] = "<<nums2[i]<<endl;
    cout<<endl;

    cout<<"Try again? (1 for yes or 2 for no): ";
    cin>>num;
    (num==1)?loop=true:loop=false;
  }
  return 0;
}

Array<int> getElements()
{
  cout<<"getElements called."<<endl;
  Array<int> numbers(2);
  int i=0;
  cout<<"Enter a positive integer: ";
  cin>>numbers[i];
  while(numbers[i]!=-1)
  {
	  i++;
	  if(i==numbers.length())
		  numbers.changeSize(i*2);
	  cout<<"Enter a positive integer (enter -1 to stop): ";
	  cin>>numbers[i];
  }
  numbers.changeSize(i);
  return numbers;
}

float calcAverage(Array<int> avnums)
{
	cout<<"calcAverage called."<<endl;
    int sum=0;
	for(int i=0;i<avnums.length();i++)
		sum +=avnums[i];
	return sum/float(avnums.length());
}
