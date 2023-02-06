// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funWithGraphs.h"
#include "graph.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 1: DFS e grafos bipartidos
// ----------------------------------------------------------
TEST(test_1, bipartite) {
    cout << "Testando 'bipartite'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_TRUE(g1.bipartite());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_FALSE(g2.bipartite());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_FALSE(g3.bipartite());

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_TRUE(g4.bipartite());
}

// ----------------------------------------------------------
// Exercicio 2.a: Contando componentes fortemente conexos
// ----------------------------------------------------------
TEST(test_2a, countSCCs) {
    cout << "Testando 'countSCCs'" << endl;

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    EXPECT_EQ(2, g5.countSCCs());

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    EXPECT_EQ(4, g6.countSCCs());

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    EXPECT_EQ(3, g7.countSCCs());

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    EXPECT_EQ(7, g8.countSCCs());
}

// ----------------------------------------------------------
// Exercicio 2.b: Listando componentes fortemente conexos
// ----------------------------------------------------------
TEST(test_2b, listSCCs) {
    cout << "Testando 'listSCCs'" << endl;

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    list<list<int>> sccs5 = g5.listSCCs();
    for (auto & comp : sccs5) comp.sort();
    sccs5.sort();
    list<list<int>> answer5 = {{1,2,5,6},{3,4,7,8}};
    EXPECT_EQ(sccs5, answer5);

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    list<list<int>> sccs6 = g6.listSCCs();
    for (auto & comp : sccs6) comp.sort();
    sccs6.sort();
    list<list<int>> answer6 = {{1,2,3,6},{4,8},{5},{7}};
    EXPECT_EQ(sccs6, answer6);

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    list<list<int>> sccs7 = g7.listSCCs();
    for (auto & comp : sccs7) comp.sort();
    sccs7.sort();
    list<list<int>> answer7 = {{1,2,5},{3,4,8},{6,7}};
    EXPECT_EQ(sccs7, answer7);

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    list<list<int>> sccs8 = g8.listSCCs();
    for (auto & comp : sccs8) comp.sort();
    sccs8.sort();
    list<list<int>> answer8 = {{1},{2},{3},{4},{5},{6},{7}};
    EXPECT_EQ(sccs8, answer8);
}

// ----------------------------------------------------------
// Exercicio 3: Pontos de articulação
// ----------------------------------------------------------
TEST(test_3, articulationPoints) {
    cout << "Testando 'articulationPoints'" << endl;

    cout << "  . graph9" << endl;
    Graph g9 = FunWithGraphs::graph9();
    list<int> art9 = g9.articulationPoints();
    art9.sort();
    list<int> answer9 = {3, 5, 8};
    EXPECT_EQ(art9, answer9);

    cout << "  . graph10" << endl;
    Graph g10 = FunWithGraphs::graph10();
    list<int> art10 = g10.articulationPoints();
    list<int> answer10 = {};
    EXPECT_EQ(art10, answer10);

    cout << "  . graph11" << endl;
    Graph g11 = FunWithGraphs::graph11();
    list<int> art11 = g11.articulationPoints();
    list<int> answer11 = {1};
    EXPECT_EQ(art11, answer11);

    cout << "  . graph12" << endl;
    Graph g12 = FunWithGraphs::graph12();
    list<int> art12 = g12.articulationPoints();
    art12.sort();
    list<int> answer12 = {2, 3, 5, 8};
    EXPECT_EQ(art12, answer12);
}

// ----------------------------------------------------------
// Exercicio 4: Quartel da Polícia
// ----------------------------------------------------------
TEST(test_4, police) {
    cout << "Testando 'police'" << endl;

    cout << "  . casos exemplos do enunciado" << endl;
    pair<int, int> ans1 = FunWithGraphs::police({10,20,30}, {{1,2},{2,3},{3,2}});
    pair<int, int> sol1 = {30, 1};
    EXPECT_EQ(ans1, sol1);

    pair<int, int> ans2 = FunWithGraphs::police({10,20,30,5,10,5,10},
                                                {{1,2},{2,3},{3,1},{2,4},
                                                       {4,5},{4,6},{5,6},{6,7},{7,4}});
    pair<int, int> sol2 = {15, 2};
    EXPECT_EQ(ans2, sol2);

    cout << "  . outros casos de input" << endl;
    pair<int, int> ans3 = FunWithGraphs::police({1,3,2,2,1,3,1,4,10,10},
                                                {{1,2},{2,3},{3,1},{3,4},{4,5},{5,6},
                                                 {5,7},{6,4},{7,3},{8,9},{9,10},{10,9}});
    pair<int, int> sol3 = {15, 6};
    EXPECT_EQ(ans3, sol3);

    pair<int, int> ans4 = FunWithGraphs::police({7,91},{{1,2},{2,1}});
    pair<int, int> sol4 = {7, 1};
    EXPECT_EQ(ans4, sol4);

    pair<int, int> ans5 = FunWithGraphs::police({1,1,1,1,1,1,1,2,2,2},
                                                {{2,3},{2,4},{4,1},{4,7},{4,10},{4,5},{4,8},{2,6},
                                                {3,2},{1,2},{7,2},{10,2},{5,2},{8,2},{6,2}});

    pair<int, int> sol5 = {3, 7};
    EXPECT_EQ(ans5, sol5);

    pair<int, int> ans6 = FunWithGraphs::police({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                                {{1,2},{2,1},{3,4},{4,3},{5,6},{6,5},{7,8},{8,7},
                                                 {9,10},{10,9},{11,12},{12,11},{13,14},{14,13},
                                                 {15,16},{16,15},{17,18},{18,17},{19,20},{20,19},
                                                 {21,22},{22,21},{23,24},{24,23},{25,26},{26,25},
                                                 {27,28},{28,27}});

    pair<int, int> sol6 = {14, 16384};
    EXPECT_EQ(ans6, sol6);
}