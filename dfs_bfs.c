#include <stdio.h>
#include <string.h>

#define GRAPH_SIZE 5

void connect(unsigned a, unsigned b, int graph[GRAPH_SIZE][GRAPH_SIZE])
{
    graph[a][b] = 1;
    graph[b][a] = 1;
}

void dfs_visit(int graph[GRAPH_SIZE][GRAPH_SIZE], int visited[GRAPH_SIZE], unsigned node)
{
    static unsigned visitCount = 0;
    if (!visited[node])
    {
        unsigned j;
        ++visitCount;
        visited[node] = visitCount;
        for (j = 0; j < GRAPH_SIZE; ++j)
        {
            if (graph[node][j])
            {
                dfs_visit(graph, visited, j);
            }
        }
    }
}

void dfs(int graph[GRAPH_SIZE][GRAPH_SIZE], int visitOrder[GRAPH_SIZE])
{
    int i;
    for (i = 0; i < GRAPH_SIZE; ++i)
    {
        dfs_visit(graph, visitOrder, i);
    }
}

void bfs(int graph[GRAPH_SIZE][GRAPH_SIZE], int visitOrder[GRAPH_SIZE])
{
    unsigned fifo[GRAPH_SIZE];
    int fifoLast = -1;
    static int visitCount = 0;

    memset((void *) fifo, 0, sizeof(fifo));

    // Start with node 0
    fifo[0] = 0;
    fifoLast = 0;

    while(fifoLast != -1) 
    {
        unsigned node = fifo[fifoLast];
        unsigned k;

        --fifoLast;

        if (!visitOrder[node]) 
        {
            ++visitCount;        
            visitOrder[node] = visitCount;
        }
        
        for (k = 0; k < GRAPH_SIZE; ++k)
        {
            if ((graph[node][k]) && !visitOrder[k])
            {
                visitOrder[k] = visitCount;
                
                ++fifoLast;
                fifo[fifoLast] = k;
            }
        }
    }
}

int main()
{
    int graph[GRAPH_SIZE][GRAPH_SIZE];
    int visitOrderDfs[GRAPH_SIZE];
    int visitOrderBfs[GRAPH_SIZE];
    int i;

    memset(graph, 0, sizeof(graph));
    memset(visitOrderBfs, 0, sizeof(visitOrderBfs));
    memset(visitOrderDfs, 0, sizeof(visitOrderDfs));

    connect(0, 1, graph);
    connect(0, 3, graph);
    connect(1, 2, graph);
    connect(0, 2, graph);
    connect(1, 4, graph);
    connect(3, 4, graph);

    dfs(graph, visitOrderDfs);
    printf("DFS order:\n");
    for (i = 0; i < GRAPH_SIZE; ++i)
    {
        printf("\tNode %d - visited as nr %d\n", i, visitOrderDfs[i]);
    }

    bfs(graph, visitOrderBfs);
    printf("BFS order:\n");
    for (i = 0; i < GRAPH_SIZE; ++i)
    {
        printf("\tNode %d - visited as nr %d\n", i, visitOrderDfs[i]);
    }
}