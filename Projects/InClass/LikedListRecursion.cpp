#include <iostream>
using namespace std;

const int N = 10;

struct Node
{
  int value;
  Node* next;
};

void printList(Node* node)
{
  if(!node) return;
  cout << node->value << endl;
  printList(node->next);
}

int main()
{
  Node* start = 0;
  for(int i=0; i<N; i++)
  {
	  Node* node = new Node;
	  node->value=i;
	  node->next=start;
	  start=node;
  }

  printList(start);

  while(start)
  {
	  Node* temp=start->next;
	  delete start;
	  start=temp;
  }
  return 0;
}