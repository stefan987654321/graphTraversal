#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{
    string nodes[5] = {"Bob", "Alice", "Mark", "Rob", "Maria"};
    graph g;
    for (unsigned i = 0; i < 5; ++i)
        g.set_node(i, nodes[i]);
    
    g.connect("Bob", "Alice");
    g.connect("Bob", "Rob");
    g.connect("Alice", "Mark");
    g.connect("Rob", "Mark");
    g.connect("Alice", "Maria");
    g.connect("Rob", "Maria");
    g.print();

    int visitOrderDfs[GRAPH_SIZE] = {};
    g.dfs(visitOrderDfs);
    cout << "DFS done, visit order: " << endl;
    for (unsigned i = 0; i < GRAPH_SIZE; ++i)
        cout << g.get_name(i) << " - " << visitOrderDfs[i] << endl;

    int visitOrderBfs[GRAPH_SIZE] = {};
    g.bfs(visitOrderBfs);
    cout << "BFS done, visit order: " << endl;
    for (unsigned i = 0; i < GRAPH_SIZE; ++i)
        cout << g.get_name(i) << " - " << visitOrderBfs[i] << endl;
}