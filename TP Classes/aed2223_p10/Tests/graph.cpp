// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num + 1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src < 1 || src > n || dest < 1 || dest > n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e: nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

int Graph::dfsB(int v) {
    // show node order
    // cout << v << " ";
    int count = 1;
    nodes[v].visited = true;
    for (auto e: nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            count += dfsB(w);
    }
    return count;
}

void Graph::dfs2(int v, list<int>& order) {
    nodes[v].visited = true;
    for(auto e : nodes[v].adj){
        int w = e.dest;
        if(!nodes[w].visited) dfs2(w, order);
    }
    order.push_front(v);
}

bool Graph::cycleDFS(int v) {
    nodes[v].color = "Gray";
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].color == "Gray")
            return true;
        else if (nodes[w].color == "White")
            if (cycleDFS(w))
                return true;
    }

    nodes[v].color = "black";
    return false;
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if (v < 1 || v > n) return -1;
    return nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    int count = 0;
    if (v < 1 || v > n) return -1;
    for (auto edge: nodes[v].adj) {
        count += edge.weight;
    }
    return count;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    for (auto x : nodes)x.visited=false;
    int count = 0;
    for (int i=1;i <= n;i++){
        if (!nodes[i].visited){
            count++;
            dfs(i);
        }
    }
    return count;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (!nodes[i].visited) {
            ret = max(ret, dfsB(i));

        }
    }
    return ret;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> order;
    for(int i = 1; i <= n; i++) nodes[i].visited = false;
    for(int i = 1; i <= n; i++){
        if(!nodes[i].visited){
            dfs2(i, order);
        }
    }
    return order;

}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    for (int i = 1; i <= this->n; i++) {
        nodes[i].color = "White";
    }

    for (int i = 1; i <= this->n; i++) {
        if(cycleDFS(i)) {
            return true;
        }
    }
    return false;
}