#pragma once
#include "igraph.h"
#include <unordered_set>

class MatrixGraph : public IGraph
{
public:
    MatrixGraph(std::vector<std::unordered_set<int>>& initializetion);
    MatrixGraph(const MatrixGraph* oth);
    ~MatrixGraph();
    void AddEdge(int& from, int& to) override final;
    int VerticesCount() const override final;
    void GetNextVertices(int& vertex, std::vector<int>& vertices) const override final;
    void GetPrevVertices(int& vertex, std::vector<int>& vertices) const override final;
private:
    std::vector<std::vector<int>> matrix;
};
