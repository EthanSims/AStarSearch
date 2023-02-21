#include "PriorityQueueNode.h"

/**
 * @brief Construct a new Priority Queue Node:: Priority Queue Node object
 * 
 * @param city pointer to graph node for city
 * @param pFrom pointer to parent node
 * @param fromCost cost/distance between this node and parent
 */
PriorityQueueNode::PriorityQueueNode(GraphNode* city, PriorityQueueNode* pFrom, int fromCost) {
   this->city = city;
   this->pNext = nullptr;
   this->pFrom = pFrom;
   this->fromCost = fromCost;
   if (pFrom == nullptr) { // this is the root of the search tree
      this->netCost = fromCost;
      this->depth = 1;
   } else {
      this->netCost = pFrom->netCost + fromCost;
      this->depth = this->pFrom->depth + 1;
   }
}