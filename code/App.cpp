#include "App.h"
#include <iostream>
#include <vector>
#include <list>

void App::run()
{
    int size;
    std::cin >> size;
    graph.createNodesWithoutEdges( size );

    /*std::cout << "\nWezly: \n";
    for( auto &it : graph.nodes )
    {
        std::cout << it.value << std::endl;
    }*/

    int n1, n2;
    while( std::cin >> n1 && std::cin >> n2  )
    {
        graph.makeEdge( n1, n2 );
    }

    /*std::cout << "\nKrawedzie:\n";

    for( auto &it : graph.nodes )
    {
        for( auto &it2 : it.adjacent_nodes )
            std::cout << it.value << " " << it2->value << std::endl;
    }*/

    std::vector<Edge> bridges;
    bridges = graph.searchForExtensiveBridges();

    //std::cout << "\n";
    //std::cout << "\nMosty rozlegle:\n";
    for( auto &it : bridges )
    {
        std::cout << it.n1->value << " " << it.n2->value << std::endl;
    }
}