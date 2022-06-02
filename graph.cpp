#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "graph.hpp"

namespace MinEdgeCover
{

int Graph::vertexCount() const
{
    return vertex.size();
}

int Graph::edgesCount() const
{
    return edges.size();
}

Graph::Graph(const std::vector<std::vector<int>>& adj)
    : adjacency{adj}
{
    for (int i = 0; i < adjacency.size(); ++i) {
        vertex.push_back(i);
        for (int j = i; j < adjacency.size(); ++j) {
            if (adjacency[i][j] == 1) {
                auto  edge = std::make_pair(i, j);
                edges.push_back(edge);
            }
        }
    }
}


bool Graph::isAdjacent(const std::pair<int, int>& f, const std::pair<int, int>& s) const
{
    if (f.first == s.first || f.first == s.second || f.second == s.first || f.second == s.second) {
        return true;
    }
    return false;
}


void Graph::printMinEdgesCover(const std::list<std::pair<int, int>>& myList) const
{
    std::vector<int> diff_vertex;
    int vertexCount = vertex.size();
    for(int i = 0; i < vertexCount; ++i) {
        auto it = myList.begin();
        for(; it != myList.end(); ++it) {
            if(it->first == i || it->second == i) break;
        }
        if(it == myList.end())
        diff_vertex.push_back(i);
    }


    // print edges in myList
    std::cout << "\n!!!  Minimum edges cover !!!\n" << std::endl;

    for(auto& elem : myList) {
        std::cout << elem.first << "-" << elem.second << std::endl;
    }

    // print edges in adjacency
    for(int i = 0; i < diff_vertex.size(); ++i) {
        int j = 0;
        for(; j < adjacency[diff_vertex[i]].size(); ++j) {
            if(adjacency[diff_vertex[i]][j] == 1) break;
        }
        std::cout << diff_vertex[i] << "-" << j << std::endl;
    }
}

std::list<std::pair<int, int>> Graph::independency() const
{
    std::list<std::pair<int, int>> myList;
    for (int i = 0; i < edges.size(); ++i) {
        myList.push_back(edges[i]);
    }

    for(auto it = myList.begin(); it != myList.end(); ++it) {
        for (auto iter = it; iter != myList.end();) {
            if(isAdjacent(*it,*iter)) {
                if(it == iter) {
                    ++iter;
                }
                else {
                    iter = myList.erase(iter);
                }
            } else {
                ++iter;
            }
        }
    }
    return myList;
}

int Graph::minEdgeCover() const
{
    int vertexCount = vertex.size();
    std::list<std::pair<int, int>> myList = independency();
    printMinEdgesCover(myList);
    return vertexCount - myList.size();
}

bool Graph::isolated() const
{
    bool isIsolated;
    for (int i = 0; i < adjacency.size(); ++i) {
        isIsolated = true;
        for (int j = 0; j < adjacency.size(); ++j) {
            if (adjacency[j][i] == 1) {
                isIsolated = false;
                break;
            }
        }
        if (isIsolated) {
            return true;
        }
    }
    return false;
}

} /// namespace MinEdgeCover
