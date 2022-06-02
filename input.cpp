#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

namespace MinEdgeCover
{

bool isSpace(char ch)
{
    switch (ch) {
        case ' ':
        case '\n':
        case '\t':
            return true;
        default:
            break;
    }
    return false;
}

bool isValidInput(const std::vector<std::vector<int>>& adjacency)
{
    for (int i = 0; i < adjacency.size(); ++i) {
        if (adjacency[i][i] != 0) {
            return false;
        }
        for (int j = 0; j < adjacency.size(); ++j) {
            if (adjacency[i].size() != adjacency[j].size()) {
                return false;
            }
            if (adjacency[i][j] != 1 ) {
                if(adjacency[i][j] != 0) {
                    return false;
                }
            }
            if(adjacency[i][j] != adjacency[j][i]) {
                return false;
            }
        }
    }
    return true;
}


void getAdjacency(std::istream& in, std::vector<std::vector<int>>& adjacency)
{
    int n, m;
    in >> n; // vertex
    in >> m; // egde
    in.get();
    adjacency.resize(n);

    for(auto& elem : adjacency) {
        elem.resize(n);
    }

    while(true) {
        std::vector<int> elem;
        std::string temp;
        while(in.peek() != '\n' && in >> temp) {
            elem.push_back(std::stoi(temp));
        }

        if(!in.eof()) {
            adjacency[elem[0]][elem[1]] = adjacency[elem[1]][elem[0]] = 1;
            in.get();
        }
        else break;
    }

}


} ///namespace MinEdgeCover


