#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Vertex
{
  string name;

  bool isVisited;
  list<Vertex*> adjacentVertices;
};

queue<string> doBreadthFirstSearch(string startName, list<Vertex*> vertices)
{
  queue<Vertex*> vertexQueue;
  queue<string> searchOrder;

  Vertex* originVertex = 0;
  list<Vertex*>::iterator it;
  for (it = vertices.begin(); it != vertices.end(); it++) // iteratate list of all vertices
  {
    (*it)->isVisited = false; // un flag all nodes
    if ((*it)->name == startName) originVertex = *it; // once startName is found set origin node* to it
  }
  if (!originVertex) return searchOrder; // if orgin node* is still Null than given list is empty or no such city exist. retun an empty list

  originVertex->isVisited = true; // else flag origin node
  searchOrder.push(originVertex->name); // push name on to result queue to return
  vertexQueue.push(originVertex);  // push Origin node onto reconsider queue

  while (!vertexQueue.empty()) // While reconsider queue is not empty
  {
    Vertex& frontVertex = *(vertexQueue.front()); vertexQueue.pop(); // pop top node off reconsider queue
    for (list<Vertex*>::iterator it = frontVertex.adjacentVertices.begin(); it != frontVertex.adjacentVertices.end(); it++) // iterate to all connecting node(s)
    {
      Vertex& neighbor = **it;
      if (neighbor.isVisited) continue; // if neighbor has been visited skip
      neighbor.isVisited = true; // else flag neighbor
      searchOrder.push(neighbor.name); // push neighbor's name on to result queue to return
      vertexQueue.push(&neighbor); // push neighbor's node onto reconsider queue
  } }

  return searchOrder;
}

queue<string> doDepthFirstSearch(string startName, list<Vertex*> vertices)
{
  
  stack<Vertex*> vertexStack;
  queue<string> searchOrder;

  Vertex* originVertex = 0;
  list<Vertex*>::iterator it;
  for (it = vertices.begin(); it != vertices.end(); it++) // iteratate list of all vertices
  {
    (*it)->isVisited = false; // un flag all nodes
    if ((*it)->name == startName) originVertex = *it; // once startName is found set origin node* to it
  }
  if (!originVertex) return searchOrder; // if orgin node* is still Null than given list is empty or no such city exist. retun an empty list

  vertexStack.push(originVertex);  // push Origin node onto reconsider stack
  while (!vertexStack.empty()) // While reconsider stack is not empty
  {
    Vertex& frontVertex = *(vertexStack.top()); vertexStack.pop(); // pop top node off reconsider stack
	if(frontVertex.isVisited) continue; // if node has been visited skip
	frontVertex.isVisited = true; // else flag node
	searchOrder.push(frontVertex.name); // push node's name on to result queue to return
	for(list<Vertex*>::reverse_iterator rit=frontVertex.adjacentVertices.rbegin(); rit!=frontVertex.adjacentVertices.rend(); ++rit)
	{
	  Vertex& neighbor = **rit;
	  if (neighbor.isVisited) continue; // if neighbor has been visited skip
	  vertexStack.push(&neighbor); // push neighbor's node onto reconsider stack
	}
  }
  return searchOrder;
}

int main()
{
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  list<Vertex*> vertices;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
	fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    getline(fin, toCity);
	toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    Vertex* toVertex, *fromVertex;
    list<Vertex*>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++) // "to" city
      if ((*it)->name == fromCity)
        break;
    if (it == vertices.end()) // not in list yet
    {
      // store the vertex if it is new
      fromVertex = new Vertex;;
      fromVertex->name = fromCity;
      vertices.push_back(fromVertex);
    }
    else fromVertex = *it; 

    for (it = vertices.begin(); it != vertices.end(); it++) // "from" city
      if ((*it)->name == toCity)
        break;
    if (it == vertices.end()) // not in list yet
    {
      // store the vertex if it is new
      toVertex = new Vertex;;
      toVertex->name = toCity;
      vertices.push_back(toVertex);
    }
    else toVertex = *it; 

    // store bi-directional edges
    fromVertex->adjacentVertices.push_back(toVertex);
    toVertex->adjacentVertices.push_back(fromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // BFS result
    cout << "BFS";
    queue<string> q = doBreadthFirstSearch(startCity, vertices);
    while(!q.empty())
    {
      cout  << '-'<< q.front();
      q.pop();
    }
    cout << endl;

    cout << "DFS";
    q = doDepthFirstSearch(startCity, vertices);
    while(!q.empty())
    {
      cout  << '-'<< q.front();
      q.pop();
    }
    cout << endl;;
  }

  list<Vertex*>::iterator itVertex;
  for (itVertex = vertices.begin(); itVertex != vertices.end(); itVertex++)
    delete *itVertex;
}
