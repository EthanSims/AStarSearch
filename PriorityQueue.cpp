#include <iostream>
#include "PriorityQueue.h"

using namespace std;

/**
 * @brief Prints optimal path from the root of the search tree to the destination city
 * 
 * @param pathEnd node representing the end of the path
 */
void PriorityQueue::printPath(PriorityQueueNode* pathEnd) {
   // if destination node is the root of the tree, the start city is the end city
   if (pathEnd->pFrom == nullptr) {
      cout << pathEnd->city->cityName << " to " << pathEnd->city->cityName << ", 0 km\n";
      return;
   }

   PriorityQueueNode* pWorking = pathEnd;
   vector<string> pathStrings;
   pathStrings.reserve(pathEnd->depth - 1);
   // iterate up along path to root node
   for (int i = 0; i < pathEnd->depth - 1 ; i++) {
      // store string in form of: "PreviousCity to CurrentCity, distance km"
      stringstream current;
      current << pWorking->pFrom->city->cityName << " to " << pWorking->city->cityName << ", " << pWorking->fromCost << "km\n";
      pathStrings.push_back(current.str());
      pWorking = pWorking->pFrom;
   }

   // print contents of pathStrings in reverse order (since they were inserted backwards)
   for (int i = pathStrings.size() - 1 ; i >= 0 ; i--) {
      cout << pathStrings[i];
   }
}

/**
 * @brief Construct a new Priority Queue with no nodes
 */
PriorityQueue::PriorityQueue() {
   this->pHead = nullptr;
}


/**
 * @brief Inserts node into queue while maintaining lowest-cost sort
 * 
 * @param pNew node to insert
 */
void PriorityQueue::insert(PriorityQueueNode* pNew) {
   if(this->pHead == nullptr) { // empty queue
      this->pHead = pNew;
      pNew->pNext = nullptr;
      return;
   }

   if(this->pHead->netCost > pNew->netCost) { // pNode is lowest cost
      pNew->pNext = this->pHead;
      this->pHead = pNew;
      return;
   }

   PriorityQueueNode* pWorking = this->pHead;
   while(pWorking->pNext != nullptr) { // iterate through queue
      if(pWorking->pNext->netCost > pNew->netCost) {
         pNew->pNext = pWorking->pNext;
         pWorking->pNext = pNew;
         return;
      }
      pWorking = pWorking->pNext;
   }

   // put pNode at end of queue
   pWorking->pNext = pNew;
}

/**
 * @brief removes from queue element with highest priority
 * 
 * @return PriorityQueueNode* to the element removed from queue
 */
PriorityQueueNode* PriorityQueue::pop() {
   PriorityQueueNode* pOld = this->pHead;
   if (pOld != nullptr) {
      this->pHead = this->pHead->pNext;
   }
   return pOld;
}

/**
 * @brief returns whether or not there is anything in the queue
 * 
 * @return true when empty
 * @return false when not empty
 */
bool PriorityQueue::isEmpty() {
   return (this->pHead == nullptr);
}
