#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "input.hpp"
#include "graph.hpp"
using namespace MinEdgeCover;


int main()
{
    std::ifstream input("input.txt");
    std::vector<std::vector<int>> adjacency;
    if (!input.is_open()) {
        std::cerr << "File isn't open !!! " << std::endl;
        exit(0);
    }

    getAdjacency(input, adjacency);

    if (isValidInput(adjacency)) {
        Graph G{adjacency};
        if(G.isolated()) {
            std::cout << "Graph G has an isolated vertex !!!" << std::endl;
            exit(0);
        }
        std::cout << "Graph G has " << G.vertexCount() << " vertex" << std::endl;
        std::cout << "Graph G has " << G.edgesCount() << " edges" << std::endl;
        int minEdge = G.minEdgeCover();
        std::cout << "\nThe number of edge covers in graph G is " << minEdge << std::endl;

    } else {
        std::cerr << "Input isn't correct !!!" << std::endl;
        exit(0);
    }
    return 0;
}
