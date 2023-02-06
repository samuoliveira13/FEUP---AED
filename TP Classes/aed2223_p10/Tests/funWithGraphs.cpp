// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "funWithGraphs.h"

// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(6,9);
    g.addEdge(6,7);
    g.addEdge(8,7);
    g.addEdge(8,9);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(12, false);
    g.addEdge(8,1);
    g.addEdge(8,2);
    g.addEdge(8,3);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(5,11);
    g.addEdge(5,12);
    g.addEdge(6,11);
    g.addEdge(6,12);
    g.addEdge(12,11);
    g.addEdge(11,10);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(9, true);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(9,6);
    g.addEdge(7,5);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph5() {
    Graph g(4, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,1);
    return g;
}

Graph FunWithGraphs::graph6() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph7() {
    Graph g(3, true);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    return g;
}

Graph FunWithGraphs::graph8() {
    Graph g(9, false);
    g.addEdge(1,2, 5);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 8);
    g.addEdge(3,4, 7);
    g.addEdge(4,5, 3);
    g.addEdge(5,6, 5);
    g.addEdge(5,7, 9);
    g.addEdge(6,9, 1);
    g.addEdge(7,8, 2);
    g.addEdge(8,9, 42);
    return g;
}

Graph FunWithGraphs::graph9() {
    Graph g(4, false);
    g.addEdge(1,2, 3);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 3);
    g.addEdge(3,4, 4);
    return g;
}

Graph FunWithGraphs::graph10() {
    Graph g(8, true);
    g.addEdge(1,3, 3);
    g.addEdge(2,1, 2);
    g.addEdge(4,2, 1);
    g.addEdge(5,4, 1);
    g.addEdge(5,6, 2);
    g.addEdge(6,8, 1);
    g.addEdge(6,7, 2);
    g.addEdge(8,7, 3);
    return g;
}

Graph FunWithGraphs::graph11() {
    Graph g(3, true);
    g.addEdge(2,1, 2);
    g.addEdge(1,3, 8);
    g.addEdge(3,2, 1);
    return g;
}


// ----------------------------------------------------------
// Exercicio 5: Contagem de Celulas
// ----------------------------------------------------------
// TODO
int FunWithGraphs::largestMicrobe(int rows, int cols, string m[]) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 6: Labirinto de Barras
// ----------------------------------------------------------
// TODO
pair<int, int>FunWithGraphs::slashMaze(int rows, int cols, string m[]) {
    pair<int, int> ans = {-1, -1};
    return ans;
}