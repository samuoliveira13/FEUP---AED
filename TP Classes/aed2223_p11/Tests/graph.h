// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int color;
        int num;
        int low;
        bool in_stack;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);
    void dfs_isBipartido(int v, bool& is_bipartido, int color);
    void dfs_ComponentesConexos(int v, int& index, stack<int>& S, int& count_ComponentesConexos);
    void dfs_ComponentesConexosList(int v, int& index, stack<int>& S, int& count_ComponentesConexos, list<list<int>>& list);

    // ----- Functions to implement in this class -----
    bool bipartite();
    int countSCCs();
    list<list<int>> listSCCs();
    list<int> articulationPoints();
};

#endif
