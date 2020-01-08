#include "graph.hpp"

#include <iostream>
#include <cstring>
using namespace std;

void dfs_visit(const int graphArray[][GRAPH_SIZE], int visited[GRAPH_SIZE], unsigned node)
{
    static unsigned visitCount = 0;
    ++visitCount;
    visited[node] = visitCount;
    for (unsigned j = 0; j < GRAPH_SIZE; ++j)
    {
        if ((graphArray[node][j]) && !visited[j])
        {
            dfs_visit(graphArray, visited, j);
        }
    }
}
void graph::dfs(int visitOrder[GRAPH_SIZE])
{
    for (unsigned i = 0; i < GRAPH_SIZE; ++i)
    {
        if (!visitOrder[i])
            dfs_visit(connections, visitOrder, i);
    }
}

void graph::bfs(int visitOrder[GRAPH_SIZE])
{
    unsigned fifo[GRAPH_SIZE];
    int fifoLast = -1;
    memset((void *) fifo, 0, sizeof(fifo));

    static int visitCount = 0;

    // Start with node 0
    fifo[0] = 0;
    fifoLast = 0;

    while(fifoLast != -1) 
    {
        unsigned node = fifo[fifoLast];
        --fifoLast;

        if (!visitOrder[node]) 
        {
            ++visitCount;        
            visitOrder[node] = visitCount;
        }
        for (unsigned k = 0; k < GRAPH_SIZE; ++k)
        {
            if ((connections[node][k]) && !visitOrder[k])
            {
                visitOrder[k] = visitCount;
                
                ++fifoLast;
                fifo[fifoLast] = k;
            }
        }
    }
}

string graph::get_name(unsigned i)
{
    return data[i];
}

bool graph::connect(const string &nodeA, const string &nodeB)
{
    int aID = -1, bID = -1;
    for (unsigned i = 0; i < GRAPH_SIZE; ++i) 
    {
        if (nodeA == data[i]) 
        {
            aID = i;
        } 
        if (nodeB == data[i]) 
        {
            bID = i;
        }
    }

    if ((aID != -1) && (bID != -1)) 
    {
        connections[aID][bID] = 1;
        connections[bID][aID] = 1;
        return true;
    }
    return false;    
}

void graph::print()
{
    for (unsigned i = 0; i < GRAPH_SIZE; ++i) 
    {
        for (unsigned j = 0; j < GRAPH_SIZE; ++j)
        {
            cout << connections[i][j] << ' ';
        }
        cout << endl;
    }
}

void graph::set_node(unsigned node, const string &d)
{
    data[node] = d;
}