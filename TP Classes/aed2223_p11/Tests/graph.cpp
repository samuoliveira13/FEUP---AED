// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#include <stack>
#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

void Graph::dfs_isBipartido(int v, bool& is_bipartido, int color) {
    nodes[v].visited = true;
    nodes[v].color = color;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) dfs_isBipartido(w, is_bipartido, -color);
        else{
            if(nodes[w].color == color) is_bipartido = false;
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1: DFS e grafos bipartidos
// ----------------------------------------------------------
// TODO
bool Graph::bipartite() {
    int color = 1;
    bool is_bipartido = true;
    for(auto& node : nodes) node.visited = false;
    for(int i = 1; i < nodes.size(); i++){
        if(!nodes[i].visited) dfs_isBipartido(i, is_bipartido, color);
    }
    return is_bipartido;
}

// ----------------------------------------------------------
// Exercicio 2.a: Contando componentes fortemente conexos.
// ----------------------------------------------------------
// TODO

void Graph::dfs_ComponentesConexos(int v, int& index, stack<int>& S, int& count_ComponentesConexos) {
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    S.push(v);
    nodes[v].in_stack = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].num == -1){
            dfs_ComponentesConexos(w,index,S,count_ComponentesConexos);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if(nodes[w].in_stack) nodes[v].low = min(nodes[v].low, nodes[w].num);
    }
    if(nodes[v].num == nodes[v].low){
        count_ComponentesConexos++;
        int current;
        while(current != v){
            current = S.top();
            nodes[current].in_stack = false;
            S.pop();
        }
    }
}
int Graph::countSCCs() {
    int count_ComponentesConexos = 0;
    int index = 1;
    stack<int> S = {};
    for(auto& node : nodes){
        node.num = -1;
        node.visited = false;
        node.in_stack = false;
    }
    for(int i = 1; i < nodes.size(); i++){
        if(nodes[i].num == -1) dfs_ComponentesConexos(i, index,S, count_ComponentesConexos);
    }
    return count_ComponentesConexos;
}

// ----------------------------------------------------------
// Exercicio 2.b: Listando componentes fortemente conexos
// ----------------------------------------------------------
// TODO
void Graph::dfs_ComponentesConexosList(int v, int& index, stack<int>& S, int& count_ComponentesConexos, list<list<int>>& list) {
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    S.push(v);
    nodes[v].in_stack = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].num == -1){
            dfs_ComponentesConexosList(w,index,S,count_ComponentesConexos, list);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if(nodes[w].in_stack) nodes[v].low = min(nodes[v].low, nodes[w].num);
    }
    if(nodes[v].num == nodes[v].low){
        std::list<int> componentesConexos;
        count_ComponentesConexos++;
        int current;
        while(current != v){
            current = S.top();
            componentesConexos.push_back(current);
            nodes[current].in_stack = false;
            S.pop();
        }
        list.push_back(componentesConexos);
    }
}

list<list<int>> Graph::listSCCs() {
    list<list<int>> list;
    int count_ComponentesConexos = 0;
    int index = 1;
    stack<int> S = {};
    for(auto& node : nodes){
        node.num = -1;
        node.visited = false;
        node.in_stack = false;
    }
    for(int i = 1; i < nodes.size(); i++){
        if(nodes[i].num == -1) dfs_ComponentesConexosList(i, index,S, count_ComponentesConexos, list);
    }
    return list;
}

// ----------------------------------------------------------
// Exercicio 3: Pontos de articulação
// ----------------------------------------------------------
// TODO
list<int> Graph::articulationPoints() {
    list<int> answer;
    return answer;
}
