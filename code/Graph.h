#ifndef AISDI_THIRDPROJECT_GRAPH_H
#define AISDI_THIRDPROJECT_GRAPH_H

#include <list>
#include <vector>
#include "Node.h"

struct Edge
{
    Edge() : n1(nullptr), n2(nullptr) {}
    Node* n1;
    Node* n2;
};

class Graph
{
public:
    Graph() : size(0) {}

    bool checkConnectivity();
    std::vector<Edge> searchForExtensiveBridges();
    void makeEdge( Node* n1, Node* n2 );
    void makeEdge( int n1, int n2 );
    void clear();
    void createNodesWithoutEdges( unsigned int amount );
private:
    unsigned int size;
    std::vector<Node> nodes;

    int depthFirstSearch();
    void visit( Node* node );
};

#endif //AISDI_THIRDPROJECT_GRAPH_H
