#include "matrixgraph.h"

MatrixGraph::MatrixGraph(std::vector<std::unordered_set<int>>& initialization)
{
    for(int i = 0; i < initialization.size(); ++i)
    {
        std::vector<int> line;
        for(int j = 0; j < initialization.size(); ++j)
        {
            if(initialization[i].contains(j)) line.push_back(1) ;
            else line.push_back(0);
        }
        matrix.push_back(line);
    }
}

MatrixGraph::MatrixGraph(const MatrixGraph* oth) : IGraph(oth), matrix(oth->matrix) {};

MatrixGraph::~MatrixGraph(){};

void MatrixGraph::AddEdge(int& from, int& to)
{
    if(matrix[from][to] == 1 || matrix[to][from] == 0) return;
    else if( from >= matrix.size() || to >= matrix.size()) std::cout << "Creating an edge is not possible." << std::endl;
    else matrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const
{
    return matrix.size();
}

void MatrixGraph::GetNextVertices(int& vertex, std::vector<int>& vertices) const
{
    if (vertex > (matrix.size()-1)) return;
    for(int i = 0; i < matrix.size(); ++i)
        if(matrix[vertex][i] == 1) vertices.push_back(i);
}

void MatrixGraph::GetPrevVertices(int& vertex, std::vector<int>& vertices) const
{
    if(vertex > (matrix.size()-1)) return;
    for(int i = 0; i < matrix.size(); ++i)
        if(matrix[vertex][i] == 1) vertices.push_back(i);
}
