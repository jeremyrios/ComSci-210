#include<iostream>
#include<list>
using namespace std;

int main()
{
  list<float> a;
  list<float>::iterator it, rit;
  cout << "size = " << a.size() << endl;
  a.push_front(100.f);
  a.push_back(200.f);
  cout << "size = " << a.size() << " expect 2" << endl;
  cout << "front = " << a.front() << " expect 100" <<endl;
  cout << "back = " << a.back() << " expect 200" <<endl;

  for(rit= a.begin();rit!=a.end(); rit++) // how to traverse iterator list
	cout << *rit << endl;

  for(it= a.begin();it!=a.end(); it++) // how to traverse iterator list
	cout << *it << endl;

 /*
  it = a.begin();
  for(int i=0; i<10; i++, it++)
    cout << *it << endl;
*/
  cout << endl << "mod = " << 1234567%40 << endl;
  return 0;
}