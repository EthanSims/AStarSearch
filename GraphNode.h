#ifndef GRAPH_NODE
#define GRAPH_NODE

#include <string>
#include <vector>
using namespace std;

struct GraphNode {
   string cityName;
   vector<GraphNode*> connectedCities;
   vector<int> connectedDistances;
};

#endif