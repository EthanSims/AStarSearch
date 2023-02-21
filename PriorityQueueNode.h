#ifndef PRIORITY_QUEUE_NODE
#define PRIORITY_QUEUE_NODE
#include "GraphNode.h"

struct PriorityQueueNode {
   GraphNode* city;
   int netCost;
   PriorityQueueNode* pNext;
   PriorityQueueNode* pFrom;
   int fromCost;
   int depth;

   PriorityQueueNode(GraphNode* city, PriorityQueueNode* pFrom, int fromCost);
};

#endif