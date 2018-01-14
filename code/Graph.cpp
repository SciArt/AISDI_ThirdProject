#include "Graph.h"

bool Graph::checkConnectivity()
{
    return (nodes.size() == depthFirstSearch());
}

void Graph::visit( Node* node )
{
    node->visited = true;
    for( auto &adjacent_node : node->adjacent_nodes )
    {
        if( !adjacent_node->visited )
            visit(adjacent_node);
    }
}

// Nodes flags 'visited' are set to false before and after calling function
int Graph::depthFirstSearch()
{
    int counter = 0;

    visit(&front);

    for( auto &node : nodes )
    {
        if( node.visited )
        {
            ++counter;
            node.visited = false;
        }
    }

    return counter;
}