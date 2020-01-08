#ifndef GRAPH_HPP_INCLUDED
#define GRAPH_HPP_INCLUDED

#include <string>
using namespace std;

#define GRAPH_SIZE 5

class graph
{
public:
    graph():
        connections(),
        data()
    {
    }

    bool connect(const string &nodeA, const string &nodeB);
    string get_name(unsigned i);
    void print();
    void set_node(unsigned node, const string &data);

    void dfs(int visitOrder[GRAPH_SIZE]);
    void bfs(int visitOrder[GRAPH_SIZE]);
private:
    int connections[GRAPH_SIZE][GRAPH_SIZE];
    string data[GRAPH_SIZE];
};

#endif