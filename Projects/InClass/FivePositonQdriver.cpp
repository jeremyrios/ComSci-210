#include <iostream>
#include <string>

#include "FivePositonQ.h"
#include "FivePositonQ.h"

using namespace std;

#include <cassert> 

const string AL = "AL";
const string BOB = "BOB";
const string CHAD = "CHAD";
const string DAVE = "DAVE";
const string ED = "ED";
const string FRED = "FRED";

int main()
{
  FivePositonQ<string> q;
  assert(q.addNewItem(AL));
  assert(q.addNewItem(BOB));
  assert(q.addNewItem(CHAD));
  assert(q.addNewItem(ED));
  assert(!q.addNewItem(FRED));

  return 0;
}