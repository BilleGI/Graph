#include <iostream>
#include <vector>
#include <unordered_set>
#include "listgraph.h"
#include "matrixgraph.h"

bool add()
{
    char answer;

    while(true)
    {
        std::cin >> answer;
        if(answer == 'y')
            return true;
        else if(answer == 'n')
            return false;
    }
}

bool check(int& index, int& num, std::vector<std::unordered_set<int>>& build)
{

    if(index < build.size() && build[index].contains(num))
            return false;

    return true;
}

int numVertices()
{
    int num;
    while(true)
    {
        std::cout << "Enter the number of vertices of the graph: ";
        std::cin >> num;
        if(num > 1)
            return num;
    }
}

void checkInt(int& mean)
{
    if(mean <0)
    {
        std::cout << "Enter the correct mean: ";
        std::cin >> mean;
    }
}

void addTop(IGraph*& graph)
{
    char answer;
    while(true)
    {
        std::cout << "Add an edge ?(y/n)" << std::endl;
        std::cin >> answer;
        if(answer =='n') return;
        else if(answer =='y')
        {
            int from, to;
            std::cout << "Enter the first edge: ";
            std::cin >> from;
            checkInt(from);
            std::cout << "Enter the second edge: ";
            std::cin >> to;
            checkInt(to);
            graph->AddEdge(from,to);
        }
    }
}

void indent(char&& c)
{
    for(int i = 0; i < 40; ++i)
        std::cout <<c;
    std::cout <<std::endl;
}

void print(std::vector<int> vertices)
{
    for(int i = 0; i < vertices.size(); ++i)
    {
        if(i == vertices.size()-1) std::cout << vertices[i] << "." << std::endl;
        else std::cout << vertices[i] << ", ";
    }
}

int main()
{
    bool flag;
    std::vector<IGraph*> graph;
    std::cout << "The program implements graghs." << std::endl;
    for(int i = 0; ; ++i)
    {
        bool mean = false;
        std::vector<std::unordered_set<int>> build;
        if(i > 0)
        {
            mean = add();
            if(flag && mean) graph.push_back(new ListGraph(static_cast<const ListGraph*>(graph[graph.size()-1])));
            else if(!flag && mean) graph.push_back(new MatrixGraph(static_cast<const MatrixGraph*> (graph[graph.size()-1])));
        }

        if(mean == false)
        {
            int num;
            std::cout << "Create graph." << std::endl;
            num = numVertices();
            for(int a = 0; a < num; ++a)
            {
                std::unordered_set<int> edges;
                std::cout << "Add edges from a vertex." << std::endl;
                for(int k = 0, j; ; ++k)
                {
                    std::cout << "Top " << a << " connect to the vertex: ";
                    std::cin >> j;
                    if(j == -1)
                        break;
                    else if(j >= 0 && j < num && check(j, a, build))
                        edges.insert(j);
                }

                build.push_back(edges);
            }
            char choice;
            std::cout << "\nCreate a graph in the form: " << std::endl;
            std::cout << "1 - adjacency list;" << std::endl;
            std::cout << "2 - adjacency matrix." << std::endl;
            while(true)
            {
                std::cin >> choice;
                if(choice == '1' || choice == '2') break;
            }
            if(choice == '1')
            {
                flag = true;
                graph.push_back(new ListGraph(build));
            }
            else if(choice == '2')
            {
                flag = false;
                graph.push_back(new MatrixGraph(build));
            }

            addTop(graph[graph.size()-1]);
        }

        std::cout << "Create a new graph?(y/n) ";
        if(!add()) break;

        std::cout << "Copy the graph value?(y/n) ";
    }

    for(int i = 0; i < graph.size(); ++i)
    {
        indent('-');
        for(int j = 0; j < graph[i]->VerticesCount(); ++j)
        {
            std::vector<int> vertices;
            graph[i]->GetNextVertices(j, vertices);
            if(!vertices.empty())
            {
                std::cout << "From this vertex " << j <<  " you can walk to: ";
                print(vertices);
            }
        }
        indent('=');
        for(int j = 0; j < graph[i]->VerticesCount(); ++j)
        {
            std::vector<int> vertices;
            graph[i]->GetPrevVertices(j, vertices);
            if(!vertices.empty())
            {
                std::cout << "You can walk to the top " << j << " from: ";
                print(vertices);
            }
        }
    }
    return 0;
}
