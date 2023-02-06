// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#ifndef _FUNGRAPHS_H_
#define _FUNGRAPHS_H_

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
    static Graph graph12();

    // ----- Functions to implement in this class -----
    static pair<int, int> police(vector<int> cost, vector<pair<int, int>> roads);
};

#endif
