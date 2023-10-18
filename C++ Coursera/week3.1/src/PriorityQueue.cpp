#include "PriorityQueue.h"
#include <iostream>
using namespace std;

void PriorityQueue::addElement(QueueElement& element)
{
    queueElements.push_back(element);
    queueSize++;
}

void PriorityQueue::decrSize()
{
    queueSize--;
}

bool PriorityQueue::isEmpty()
{
    return queueSize?false:true;
}

QueueElement* PriorityQueue::getElement(int x)
{
    return &queueElements.at(x);
}

/*
    top() functions finds and returns the element (node) with the top priority
    (smallest value) in the queue.
*/
QueueElement PriorityQueue::top()
{

    double min = INFINITE, index = 0, ret = 0;
    vector<QueueElement>::iterator it;

    for (it = queueElements.begin(); it != queueElements.end(); ++it)
    {
        if(it->getPriority() < min && !it->isProcessed())
        {
            min = it->getPriority();
            ret = index;
        }
        index++;
    }

    return queueElements.at(ret);
}
