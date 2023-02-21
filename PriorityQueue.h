#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include "PriorityQueueNode.h"
#include <sstream>

class PriorityQueue {
private:
   PriorityQueueNode* pHead;
public:
   static void printPath(PriorityQueueNode* pathEnd);

   PriorityQueue();

   void insert(PriorityQueueNode*);

   PriorityQueueNode* pop();

   bool solutionPossible(int numCities);

   bool isEmpty();

};

#endif