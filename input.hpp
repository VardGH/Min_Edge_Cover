#ifndef INPUT_HPP
#define INPUT_HPP

namespace MinEdgeCover
{

    bool isSpace(char);
    void getAdjacency(std::istream&, std::vector<std::vector<int>>&);
    bool isValidInput(const std::vector<std::vector<int>>&);

} ///namespace MinEdgeCover

#endif /// INPUT_HPP
