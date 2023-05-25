#pragma once
#include "igraph.h"
#include <unordered_set>

class ListGraph : public IGraph
{
public:
    ListGraph(std::vector<std::unordered_set<int>>& _list);
    ListGraph(const ListGraph* oth);
    ~ListGraph();
    void AddEdge(int& from, int& to) override final;
    int VerticesCount() const override final;
    void GetNextVertices(int& vertex, std::vector<int> &vertices) const override final;
    void GetPrevVertices(int& vertex, std::vector<int> &vertices) const override final;
private:
    std::vector<std::unordered_set<int>> list;
};
