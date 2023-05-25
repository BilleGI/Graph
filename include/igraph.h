#pragma once
#include <vector>
#include <iostream>

class IGraph
{
public:
    IGraph(){};
    IGraph(const IGraph* oth){};
    std::string getName() const;
    virtual ~IGraph() = default;
    virtual void AddEdge(int& from, int& to) = 0;
    virtual int VerticesCount() const = 0;
    virtual void GetNextVertices(int& vertex, std::vector<int>& vertices) const = 0;
    virtual void GetPrevVertices(int& vertex, std::vector<int>& vertices) const = 0;
};
