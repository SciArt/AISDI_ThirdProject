#ifndef AISDI_THIRDPROJECT_NODE_H
#define AISDI_THIRDPROJECT_NODE_H

#include <list>

class Node
{
public:
    Node() : visited(false), visited2(false), visible(true) {}

    std::list<Node*> adjacent_nodes;

    bool visited;
    bool visited2;
    bool visible;

    int value;
private:
};

#endif //AISDI_THIRDPROJECT_NODE_H
