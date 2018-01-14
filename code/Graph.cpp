#include "Graph.h"
#include <iostream>

bool Graph::checkConnectivity()
{
    return (size == depthFirstSearch());
}

void Graph::visit( Node* node )
{
    node->visited = true;
    for (auto &it : node->adjacent_nodes)
    {
        if (it->visible)
        {
            if (!it->visited)
                visit(it);
        }
    }
}

// Nodes flags 'visited' are set to false before and after calling function
int Graph::depthFirstSearch()
{
    int counter = 0;

    for( auto &it : nodes )
    {
        if( it.visible )
        {
            visit( &it );
            break;
        }
    }

    for( auto &it : nodes )
    {
        if( it.visited )
        {
            ++counter;
            it.visited = false;
        }
    }

    return counter;
}

void Graph::makeEdge( Node* n1, Node* n2 )
{
    n1->adjacent_nodes.push_back(n2);
    n2->adjacent_nodes.push_back(n1);
}
void Graph::makeEdge( int n1, int n2 )
{
    nodes[n1].adjacent_nodes.push_back(&(nodes[n2]));
    nodes[n2].adjacent_nodes.push_back(&(nodes[n1]));
}

std::vector<Edge> Graph::searchForExtensiveBridges()
{
    std::vector<Edge> bridges;
    Edge edge;

    size -= 2;
    for( auto &it : nodes )
    {
        it.visible = false;
        it.visited2 = true;
        edge.n1 = &it;
        for( auto &it2 : it.adjacent_nodes )
        {
            if( !it2->visited2 )
            {
                it2->visible = false;
                if( !checkConnectivity() )
                {
                    edge.n2 = it2;
                    bridges.push_back(edge);
                }
                it2->visible = true;
            }
        }
        it.visible = true;
    }
    size += 2;

    return bridges;
}

void Graph::createNodesWithoutEdges( unsigned int amount )
{
    nodes.clear();
    nodes.resize( amount );
    size = amount;

    int i = 0;
    for( auto &it : nodes )
    {
        it.value = i;
        ++i;
    }
}

void Graph::clear()
{
    nodes.clear();
    size = 0;
}

