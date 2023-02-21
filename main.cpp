#include <fstream>
#include <string>
#include <iostream>
#include "GraphNode.h"
#include "PriorityQueue.h"

using namespace std;

int main(int argc, char* argv[]) {
   // store commandline inputs
   ifstream inputFile(argv[1]);
   string startCity = argv[2];
   string endCity = argv[3];

   // read in file, store as graph
   string cityOne;
   string cityTwo;
   int distance;

   GraphNode* startCityNode;

   vector<GraphNode*> cities;
   while(inputFile >> cityOne) {
      inputFile >> cityTwo;
      inputFile >> distance;
      if(cityOne == "END" && cityTwo == "OF" && distance == 0) { // line reads: "END OF INPUT"
         break;
      } else {
         GraphNode* cityOneNode = new GraphNode();
         GraphNode* cityTwoNode = new GraphNode();

         // look if we already have either city in our graph
         for(int i = 0 ; i < cities.size() ; i++) {
            if(cities[i]->cityName == cityOne) {
               cityOneNode = cities[i];
            } else if(cities[i]->cityName == cityTwo) {
               cityTwoNode = cities[i];
            }
         }

         // if city not in graph yet, add it
         if(cityOneNode->cityName != cityOne) {
            cityOneNode->cityName = cityOne;
            cities.push_back(cityOneNode);
         }
         if(cityTwoNode->cityName != cityTwo) {
            cityTwoNode->cityName = cityTwo;
            cities.push_back(cityTwoNode);
         }

         cityOneNode->connectedCities.push_back(cityTwoNode);
         cityOneNode->connectedDistances.push_back(distance);

         cityTwoNode->connectedCities.push_back(cityOneNode);
         cityTwoNode->connectedDistances.push_back(distance);

         // check if either node is start city node
         if(cityOneNode->cityName == startCity) {
            startCityNode = cityOneNode;
         } else if(cityTwoNode->cityName == startCity) {
            startCityNode = cityTwoNode;
         }
      }
   }

   // initialize fringe using starting city
   PriorityQueue priorityQueue;
   PriorityQueueNode* workingNode = new PriorityQueueNode(startCityNode, nullptr, 0);
   priorityQueue.insert(workingNode);

   // iterate until we find the destination or we explore a tree with height equal to the amount of cities
   while (!priorityQueue.isEmpty() && workingNode->city->cityName != endCity) {
      workingNode = priorityQueue.pop(); // get next node

      // if node's depth exceeds the number of cities, it must not be the optimal solution
      if (workingNode->depth > cities.size()) {
         continue;
      }

      // add connected nodes to priority queue
      for (int i = 0 ; i < workingNode->city->connectedCities.size() ; i++) {
         PriorityQueueNode* nextNode = new PriorityQueueNode(workingNode->city->connectedCities[i], workingNode,
                                                             workingNode->city->connectedDistances[i]);

         priorityQueue.insert(nextNode);
      }
   }

   // print distance and route
   if (workingNode->city->cityName != endCity) {
      cout << "distance: infinity\nroute:\nnone";
   } else {
      cout << "distance: " << workingNode->netCost << " km\nroute:\n";
      PriorityQueue::printPath(workingNode);
   }



   return 0;
   
}