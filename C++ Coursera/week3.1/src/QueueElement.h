#ifndef QUEUEELEMENT_H
#define QUEUEELEMENT_H

/*
    QueueElement class holds the data for a single node during the shortest path calculation.
    These include its priority, the previous node in the path, and if the current node has been processed.
*/

const int UNDEFINED = -1;
const int INFINITE = 100*100;

class QueueElement
{
    public:
        QueueElement(int node, int previous = UNDEFINED, double prio = INFINITE):nodeIndex(node),previousNode(previous),priority(prio){processed = false;};
        int getNode(){return nodeIndex;}
        int getPreviousNode(){return previousNode;}
        double getPriority(){return priority;}
        void setPriority(double prio){priority = prio;}
        void setPreviousNode(int node){previousNode = node;}
        void setProcessed(){processed = true;}
        bool isProcessed(){return processed;}

    private:
        int nodeIndex, previousNode;
        double priority;
        bool processed;
};

#endif // QUEUEELEMENT_H
