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
  Vertex* prev;
  double cost;
};

pair<double, stack<string> > getShortestRoute(string startName, string endName, list<Vertex*> vertices)
{
  pair<double, stack<string> > result;
  Vertex* originVertex = 0;
  Vertex* endVertex = 0;
  list<Vertex*>::iterator it;
  for (it = vertices.begin(); it != vertices.end(); it++) // iteratate list of all vertices
  {
    (*it)->isVisited = false; // un flag all nodes
	(*it)->prev = 0; // set all prev ptrs to NULL
	(*it)->cost = 0; // set all cost to 0
    if ((*it)->name == startName) originVertex = *it; // once startName is found set origin node* to it
	if ((*it)->name == endName) endVertex = *it; // once endName is found set end node* to it
  }
  if (!originVertex || !endVertex) return result; // if start or end name is not found return empty pair
  queue<Vertex*> vertexQueue; // create queue to store vertices to consider 
  originVertex->isVisited = true; // mark start vertex as "visited
  vertexQueue.push(originVertex);
  while(!vertexQueue.empty()) // while queue still has vertices to consider
  {
    Vertex& frontVertex = *(vertexQueue.front()); vertexQueue.pop(); // get reference to vertex at front of queue and remove it from queue
	for (it = frontVertex.adjacentVertices.begin(); it != frontVertex.adjacentVertices.end(); it++) // iterate to all nieghbors
    {
      Vertex& neighbor = **it;
      if (neighbor.isVisited) continue; // if neighbor has been visited skip
      neighbor.isVisited = true; // else flag neighbor
	  neighbor.cost = (1 + frontVertex.cost); // set neighbor's cost to 1+cost of vertex under consideration 
	  neighbor.prev = &frontVertex; // set neighbor's previous vertex to the vertex under consideration 
	  vertexQueue.push(&neighbor); // put neighbor in queue for further consideration 
	  if(neighbor.name == endName) 
	  {
	    while(!vertexQueue.empty()) vertexQueue.pop();
	    break;
	  }
    }
  }
  result.first = endVertex->cost;
  for (Vertex* vertex = endVertex; vertex != 0; vertex = vertex->prev)
    result.second.push(vertex->name);
  return result;
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
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    pair<double, stack<string> > result = getShortestRoute(fromCity, toCity, vertices);
    cout << "Total edges: " << result.first;  
    while (!result.second.empty()){cout << '-' << result.second.top(); result.second.pop();}
    cout << endl;
  }

  list<Vertex*>::iterator itVertex;
  for (itVertex = vertices.begin(); itVertex != vertices.end(); itVertex++)
    delete *itVertex;
}
