#ifndef MinEdgeCover_GRAPH_HPP
#define MinEdgeCover_GRAPH_HPP

namespace MinEdgeCover
{
    class Graph
    {
    public:
        explicit Graph(const std::vector<std::vector<int>>&);
        bool isolated() const;
        int vertexCount() const;
        int edgesCount() const;
        int minEdgeCover() const;

    private:
        std::vector<int> vertex;
        std::vector<std::pair<int, int>> edges;
        std::vector<std::vector<int>> adjacency;//matrix

    private:
        std::list<std::pair<int, int>> independency() const;
        bool isAdjacent(const std::pair<int, int>& , const std::pair<int, int>&) const;

	    void printMinEdgesCover(const std::list<std::pair<int, int>>&) const;
    };


} /// namespace MinEdgeCover

#endif /// MinEdgeCover_GRAPH_HPP
