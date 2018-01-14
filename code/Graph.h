#ifndef AISDI_THIRDPROJECT_GRAPH_H
#define AISDI_THIRDPROJECT_GRAPH_H

#include <list>
#include "Node.h"

class Graph
{
public:
    bool checkConnectivity();

private:
    std::list<Node> nodes;
    int depthFirstSearch();

    void visit( Node* node );
};

#endif //AISDI_THIRDPROJECT_GRAPH_H
