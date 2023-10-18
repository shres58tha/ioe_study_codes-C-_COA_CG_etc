#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include "QueueElement.h"

using namespace std;

/*
    PriorityQueue class includes a vector which holds the necessary data of each node during the shortest path calculation.
*/

class PriorityQueue
{
    public:
        PriorityQueue(){queueSize = 0;}
        void addElement(QueueElement& element);
        vector<QueueElement> getQueueElements(){return queueElements;}
        QueueElement top();
        QueueElement* getElement(int x);
        bool isEmpty();
        void decrSize();
        int getSize(){return queueSize;}

    private:
        vector<QueueElement> queueElements;
        int queueSize;
};

#endif // PRIORITYQUEUE_H
