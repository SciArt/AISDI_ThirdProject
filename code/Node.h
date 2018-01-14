#ifndef AISDI_THIRDPROJECT_NODE_H
#define AISDI_THIRDPROJECT_NODE_H

#include <list>

class Node
{
public:
    Node() : visited(false), visible(true) {}

    std::list<Node*> adjacent_nodes;

    bool visited;
    bool visible;

private:
};

#endif //AISDI_THIRDPROJECT_NODE_H
