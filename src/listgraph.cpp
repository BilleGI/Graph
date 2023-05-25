#include "listgraph.h"

ListGraph::ListGraph(std::vector<std::unordered_set<int>>& _list) : list(_list){}

ListGraph::ListGraph(const ListGraph* oth) : IGraph(oth), list(oth->list){}

ListGraph::~ListGraph(){}

void ListGraph::AddEdge(int& from, int& to)
{
    if(list[to].contains(from) || from >(list.size() - 1)) std::cout << "Adding an edge is not possible" << std::endl;
    else list[from].insert(to);
}

int ListGraph::VerticesCount() const
{
    return list.size();
}

void ListGraph::GetNextVertices(int& vertex, std::vector<int>& vertices) const
{
    for(const auto& it : list[vertex])
        vertices.push_back(it);
}

void ListGraph::GetPrevVertices(int& vertex, std::vector<int>& vertices) const
{
    for(int i = 0; i < list.size(); ++i)
    {
        if(list[i].contains(vertex))
            vertices.push_back(i);
    }
}
