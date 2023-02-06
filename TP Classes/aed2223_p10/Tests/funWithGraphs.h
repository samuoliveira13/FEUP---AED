// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#ifndef _FUNGRAPHS_H_
#define _FUNGRAPHS_H_

#include <string>
#include "graph.h"

using namespace std;

class FunWithGraphs {

public:
    // ----- Some example graphs -----
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();
    static Graph graph5();
    static Graph graph6();
    static Graph graph7();
    static Graph graph8();
    static Graph graph9();
    static Graph graph10();
    static Graph graph11();

    // ----- Functions to implement in this class -----
    static int largestMicrobe(int rows, int cols, string m[]);
    static pair<int, int>slashMaze(int rows, int cols, string m[]);
};

#endif
