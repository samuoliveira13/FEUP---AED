// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

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

    // ----- Functions to implement in this class -----
    static int maze(int rows, int cols, string m[]);
    static pair<int,int> volcano(int rows, int cols, string m[]);
    static pair<int, string> game(const vector<int> & target);

};

#endif
