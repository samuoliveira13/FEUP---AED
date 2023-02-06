// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funWithGraphs.h"
#include "graph.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 1.a: Devolvendo o grau
// ----------------------------------------------------------
TEST(test_1, outDegree) {
    cout << "Testando 'outDegree'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(2, g1.outDegree(1));
    EXPECT_EQ(2, g1.outDegree(2));
    EXPECT_EQ(2, g1.outDegree(3));
    EXPECT_EQ(3, g1.outDegree(4));
    EXPECT_EQ(3, g1.outDegree(5));
    EXPECT_EQ(2, g1.outDegree(6));
    EXPECT_EQ(2, g1.outDegree(7));
    EXPECT_EQ(1, g1.outDegree(8));
    EXPECT_EQ(1, g1.outDegree(9));
    EXPECT_EQ(-1, g1.outDegree(-42));
    EXPECT_EQ(-1, g1.outDegree(0));
    EXPECT_EQ(-1, g1.outDegree(10));
    EXPECT_EQ(-1, g1.outDegree(42));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(2, g3.outDegree(1));
    EXPECT_EQ(3, g3.outDegree(2));
    EXPECT_EQ(3, g3.outDegree(3));
    EXPECT_EQ(1, g3.outDegree(4));
    EXPECT_EQ(3, g3.outDegree(5));
    EXPECT_EQ(3, g3.outDegree(6));
    EXPECT_EQ(1, g3.outDegree(7));
    EXPECT_EQ(5, g3.outDegree(8));
    EXPECT_EQ(1, g3.outDegree(9));
    EXPECT_EQ(1, g3.outDegree(10));
    EXPECT_EQ(4, g3.outDegree(11));
    EXPECT_EQ(3, g3.outDegree(12));

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(2, g4.outDegree(1));
    EXPECT_EQ(1, g4.outDegree(2));
    EXPECT_EQ(1, g4.outDegree(3));
    EXPECT_EQ(1, g4.outDegree(4));
    EXPECT_EQ(1, g4.outDegree(5));
    EXPECT_EQ(0, g4.outDegree(6));
    EXPECT_EQ(1, g4.outDegree(7));
    EXPECT_EQ(1, g4.outDegree(8));

    cout << "  . graph10" << endl;
    Graph g10 = FunWithGraphs::graph10();
    EXPECT_EQ(1, g10.outDegree(1));
    EXPECT_EQ(1, g10.outDegree(2));
    EXPECT_EQ(0, g10.outDegree(3));
    EXPECT_EQ(1, g10.outDegree(4));
    EXPECT_EQ(2, g10.outDegree(5));
    EXPECT_EQ(2, g10.outDegree(6));
    EXPECT_EQ(0, g10.outDegree(7));
    EXPECT_EQ(1, g10.outDegree(8));
}

// ----------------------------------------------------------
// Exercicio 1.b: Devolvendo o grau... pesado
// ----------------------------------------------------------
TEST(test_1, weightedOutDegree) {
    cout << "Testando 'WeightedOutDegree'" << endl;

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    EXPECT_EQ(9, g8.weightedOutDegree(1));
    EXPECT_EQ(13, g8.weightedOutDegree(2));
    EXPECT_EQ(11, g8.weightedOutDegree(3));
    EXPECT_EQ(18, g8.weightedOutDegree(4));
    EXPECT_EQ(17, g8.weightedOutDegree(5));
    EXPECT_EQ(6, g8.weightedOutDegree(6));
    EXPECT_EQ(11, g8.weightedOutDegree(7));
    EXPECT_EQ(44, g8.weightedOutDegree(8));
    EXPECT_EQ(43, g8.weightedOutDegree(9));
    EXPECT_EQ(-1, g8.weightedOutDegree(0));
    EXPECT_EQ(-1, g8.weightedOutDegree(10));

    cout << "  . graph9" << endl;
    Graph g9 = FunWithGraphs::graph9();
    EXPECT_EQ(7, g9.weightedOutDegree(1));
    EXPECT_EQ(6, g9.weightedOutDegree(2));
    EXPECT_EQ(8, g9.weightedOutDegree(3));
    EXPECT_EQ(7, g9.weightedOutDegree(4));

    cout << "  . graph10" << endl;
    Graph g10 = FunWithGraphs::graph10();
    EXPECT_EQ(3, g10.weightedOutDegree(1));
    EXPECT_EQ(2, g10.weightedOutDegree(2));
    EXPECT_EQ(0, g10.weightedOutDegree(3));
    EXPECT_EQ(1, g10.weightedOutDegree(4));
    EXPECT_EQ(3, g10.weightedOutDegree(5));
    EXPECT_EQ(3, g10.weightedOutDegree(6));
    EXPECT_EQ(0, g10.weightedOutDegree(7));
    EXPECT_EQ(3, g10.weightedOutDegree(8));

    cout << "  . graph11" << endl;
    Graph g11 = FunWithGraphs::graph11();
    EXPECT_EQ(8, g11.weightedOutDegree(1));
    EXPECT_EQ(2, g11.weightedOutDegree(2));
    EXPECT_EQ(1, g11.weightedOutDegree(3));
}

// ----------------------------------------------------------
// Exercicio 2.a: Contando componentes conexos
// ----------------------------------------------------------
TEST(test_2, connectedComponents) {
    cout << "Testando 'connectedComponents'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(1, g1.connectedComponents());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(3, g2.connectedComponents());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(2, g3.connectedComponents());

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    EXPECT_EQ(1, g8.connectedComponents());

    cout << "  . graph9" << endl;
    Graph g9 = FunWithGraphs::graph9();
    EXPECT_EQ(1, g9.connectedComponents());
}

// ----------------------------------------------------------
// Exercicio 2.b: Componente gigante
// ----------------------------------------------------------
TEST(test_2, giantComponent) {
    cout << "Testando 'giantComponent'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(9, g1.giantComponent());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(4, g2.giantComponent());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(7, g3.giantComponent());

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    EXPECT_EQ(9, g8.giantComponent());

    cout << "  . graph9" << endl;
    Graph g9 = FunWithGraphs::graph9();
    EXPECT_EQ(4, g9.giantComponent());
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
TEST(test_3, topologicalSorting) {
    cout << "Testando 'topologicalSorting'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    list<int> order = g4.topologicalSorting();
    // Uncomment to print order
    // cout << "    Order:"; for (auto v : order ) cout << " " << v; cout << endl;
    // A naive exhaustive verification
    EXPECT_EQ(9, order.size()); // size of order
    for (int v=1; v<=9; v++) EXPECT_NE(order.end(), find(order.begin(), order.end(), v)); // v exists
    // "Ugly", but to keep the graph class as simple as possible and as it was given so as not to confuse students
    vector<pair<int, int>> edges4 = {{1,2},{1,3}, {2,4}, {3,4}, {4,5}, {5,6}, {9,6},{7,5}, {8,7}};
    for (auto e : edges4) {
        auto u = find(order.begin(), order.end(), e.first);
        auto v = find(order.begin(), order.end(), e.second);
        EXPECT_LT(distance(order.begin(), u), distance(order.begin(), v)); // pos(u) < pos(v)
    }

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    order = g6.topologicalSorting();
    // Uncomment to print order
    // cout << "    Order:"; for (auto v : order ) cout << " " << v; cout << endl;
    // A naive exhaustive verification
    EXPECT_EQ(8, order.size()); // size of order
    for (int v=1; v<=8; v++) EXPECT_NE(order.end(), find(order.begin(), order.end(), v)); // v exists
    // "Ugly", but to keep the graph class as simple as possible and as it was given so as not to confuse students
    vector<pair<int, int>> edges6 = {{1,2},{3,1}, {2,4}, {5,4}, {5,6}, {6,7}, {6,8}, {8,7}};
    for (auto e : edges6) {
        auto u = find(order.begin(), order.end(), e.first);
        auto v = find(order.begin(), order.end(), e.second);
        EXPECT_LT(distance(order.begin(), u), distance(order.begin(), v)); // pos(u) < pos(v)
    }

    cout << "  . graph10" << endl;
    Graph g10 = FunWithGraphs::graph10();
    order = g10.topologicalSorting();
    // Uncomment to print order
    // cout << "    Order:"; for (auto v : order ) cout << " " << v; cout << endl;
    // A naive exhaustive verification
    EXPECT_EQ(8, order.size()); // size of order
    for (int v=1; v<=8; v++) EXPECT_NE(order.end(), find(order.begin(), order.end(), v)); // v exists
    // "Ugly", but to keep the graph class as simple as possible and as it was given so as not to confuse students
    vector<pair<int, int>> edges10 = {{2,1},{1,3}, {4,2}, {5,4}, {5,6}, {6,7}, {6,8}, {8,7}};
    for (auto e : edges10) {
        auto u = find(order.begin(), order.end(), e.first);
        auto v = find(order.begin(), order.end(), e.second);
        EXPECT_LT(distance(order.begin(), u), distance(order.begin(), v)); // pos(u) < pos(v)
    }
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
TEST(test_4, hasCycle) {
    cout << "Testando 'hasCycle'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_FALSE(g4.hasCycle());

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    EXPECT_TRUE(g5.hasCycle());

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    EXPECT_FALSE(g6.hasCycle());

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    EXPECT_TRUE(g7.hasCycle());

    cout << "  . graph10" << endl;
    Graph g10 = FunWithGraphs::graph10();
    EXPECT_FALSE(g10.hasCycle());

    cout << "  . graph11" << endl;
    Graph g11 = FunWithGraphs::graph11();
    EXPECT_TRUE(g11.hasCycle());
}

// ----------------------------------------------------------
// Exercicio 5: Contagem de Celulas
// ----------------------------------------------------------
TEST(test_5, largestMicrobe) {
    cout << "Testando 'largestMicrobe'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    string m1[5] = {"##.#...",
                    ".###...",
                    ".....##",
                    ".#...##",
                    "#.#...."};
    EXPECT_EQ(6, FunWithGraphs::largestMicrobe(5, 7, m1));

    cout << "  . Outros casos" << endl;

    string m2[3] = {"...",
                    "...",
                    "..."};
    EXPECT_EQ(0, FunWithGraphs::largestMicrobe(3, 3, m2));

    string m3[6] = {"########",
                    "........",
                    "#.#.#.#.",
                    ".#.#.#.#",
                    ".#.#.#.#",
                    "#.#.#.#."};
    EXPECT_EQ(16, FunWithGraphs::largestMicrobe(6, 8, m3));

    string m4[6] = {"##.....#..",
                    "##.#.#...#",
                    "....#...##",
                    "###...#.##"};
    EXPECT_EQ(5, FunWithGraphs::largestMicrobe(4, 10, m4));
}

// ----------------------------------------------------------
// Exercicio 5: Contagem de Celulas
// ----------------------------------------------------------
TEST(test_6, slashMaze) {
    cout << "Testando 'slashMaze'" << endl;

    cout << "  . Exemplos do enunciado" << endl;

    // R"()" is a raw literal (avoiding having to escape the backslash)
    string m1[4] = {R"(\//\\/)",
                    R"(\///\/)",
                    R"(//\\/\)",
                    R"(\/\///)"};
    pair<int,int> ans1 = {2, 16};
    EXPECT_EQ(ans1, FunWithGraphs::slashMaze(4, 6, m1));

    cout << "  . Outros casos de teste" << endl;

    string m3[5] = {R"(/\/\/)",
                    R"(\/\/\)",
                    R"(/\/\/)",
                    R"(/\/\/)",
                    R"(\/\/\)"};
    pair<int,int> ans3 = {6, 4};
    EXPECT_EQ(ans3, FunWithGraphs::slashMaze(5, 5, m3));

    string m4[4] = {R"(//\\)",
                    R"(//\\)",
                    R"(\\//)",
                    R"(\\//)"};
    pair<int,int> ans4 = {2, 12};
    EXPECT_EQ(ans4, FunWithGraphs::slashMaze(4, 4, m4));

    string m5[6] = {R"(/\/\/\)",
                    R"(\//\\/)",
                    R"(///\\\)",
                    R"(\\\///)",
                    R"(/\\//\)",
                    R"(\/\/\/)"};
    pair<int,int> ans5 = {7, 20};
    EXPECT_EQ(ans5, FunWithGraphs::slashMaze(6, 6, m5));

    string m6[4] = {R"(/\/\/\)",
                    R"(\\/\//)",
                    R"(//\/\\)",
                    R"(\/\/\/)"};
    pair<int,int> ans6 = {2, 28};
    EXPECT_EQ(ans6, FunWithGraphs::slashMaze(4, 6, m6));
}