// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funWithGraphs.h"
#include "graph.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 1.a: Distáncia entre dois nós
// ----------------------------------------------------------
TEST(test_1a, distance) {
    cout << "Testando 'distance'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(0, g1.distance(1,1));
    EXPECT_EQ(1, g1.distance(1,2));
    EXPECT_EQ(1, g1.distance(1,3));
    EXPECT_EQ(2, g1.distance(1,4));
    EXPECT_EQ(3, g1.distance(1,5));
    EXPECT_EQ(4, g1.distance(1,6));
    EXPECT_EQ(4, g1.distance(1,7));
    EXPECT_EQ(5, g1.distance(1,8));
    EXPECT_EQ(5, g1.distance(1,9));
    EXPECT_EQ(2, g1.distance(4,1));
    EXPECT_EQ(1, g1.distance(4,2));
    EXPECT_EQ(1, g1.distance(4,3));
    EXPECT_EQ(0, g1.distance(4,4));
    EXPECT_EQ(1, g1.distance(4,5));
    EXPECT_EQ(2, g1.distance(4,6));
    EXPECT_EQ(2, g1.distance(4,7));
    EXPECT_EQ(3, g1.distance(4,8));
    EXPECT_EQ(3, g1.distance(4,9));
    EXPECT_EQ(2, g1.distance(2,3));
    EXPECT_EQ(4, g1.distance(9,8));
    EXPECT_EQ(2, g1.distance(8,5));
    EXPECT_EQ(4, g1.distance(2,8));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(1, g2.distance(1,2));
    EXPECT_EQ(2, g2.distance(1,3));
    EXPECT_EQ(3, g2.distance(1,4));
    EXPECT_EQ(-1, g2.distance(1,5));
    EXPECT_EQ(-1, g2.distance(12,1));
    EXPECT_EQ(2, g2.distance(1,7));
    EXPECT_EQ(1, g2.distance(1,8));
    EXPECT_EQ(2, g2.distance(1,9));
    EXPECT_EQ(3, g2.distance(4,7));
    EXPECT_EQ(2, g2.distance(9,3));
    EXPECT_EQ(2, g2.distance(10,6));
    EXPECT_EQ(1, g2.distance(5,12));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(4, g3.distance(5,1));
    EXPECT_EQ(3, g3.distance(5,2));
    EXPECT_EQ(2, g3.distance(5,3));
    EXPECT_EQ(1, g3.distance(5,4));
    EXPECT_EQ(4, g3.distance(5,6));
    EXPECT_EQ(4, g3.distance(5,7));
    EXPECT_EQ(3, g3.distance(5,8));
    EXPECT_EQ(2, g3.distance(5,9));
    EXPECT_EQ(1, g3.distance(5,10));
    EXPECT_EQ(3, g3.distance(2,10));
    EXPECT_EQ(2, g3.distance(1,7));
    EXPECT_EQ(4, g3.distance(3,8));
}

// ----------------------------------------------------------
// Exercicio 1.b: Diâmetro
// ----------------------------------------------------------
TEST(test_1b, diameter) {
    cout << "Testando 'diameter'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(5, g1.diameter());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(-1, g2.diameter());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(4, g3.diameter());
}

// ----------------------------------------------------------
// Exercicio 2: Um labirinto 2D
// ----------------------------------------------------------
TEST(test_2, maze) {
    cout << "Testando 'maze'" << endl;

    cout << "  . caso de exemplo do enunciado" << endl;
    string m1[] = {"##########",
                   "#..P.....#",
                   "#.##.###.#",
                   "#..#.....#",
                   "## #.#.###",
                   "#....#...#",
                   "#.######.#",
                   "#.....T..#",
                   "##########"};
    EXPECT_EQ(13, FunWithGraphs::maze(9, 10, m1));

    cout << "  . outros casos" << endl;
    string m2[] = {"#####",
                   "#..P#",
                   "#.#.#",
                   "#T..#",
                   "####"};
    EXPECT_EQ(4, FunWithGraphs::maze(5, 5, m2));

    string m3[] = {"#############",
                   "#.#.........#",
                   "#.#.....#.###",
                   "#.#.#####...#",
                   "#.......###.#",
                   "#.....P.#T..#",
                   "#############"};
    EXPECT_EQ(21, FunWithGraphs::maze(7, 13, m3));

    string m4[] = {"#############",
                   "#...........#",
                   "#.#########.#",
                   "#.#T........#",
                   "#.###########",
                   "#..........P#",
                   "#############"};
    EXPECT_EQ(34, FunWithGraphs::maze(7, 13, m4));

    string m5[] = {"###########",
                   "#.........#",
                   "#.#.#.#.#P#",
                   "#####.#####",
                   "#.......T.#",
                   "###########"};
    EXPECT_EQ(11, FunWithGraphs::maze(6, 11, m5));
}

// ----------------------------------------------------------
// Exercicio 3: Nuvem de Cinzas
// ----------------------------------------------------------
TEST(test_3, volcano) {
    cout << "Testando 'volcano'" << endl;

    cout << "  . caso de exemplo do enunciado" << endl;
    string m1[] = {"..#...##",
                   ".##.....",
                   "###.A..A",
                   ".#......",
                   ".#....A.",
                   "...A....",
                   "........"};
    pair<int, int> ans1 = {2,4};
    EXPECT_EQ(ans1, FunWithGraphs::volcano(7, 8, m1));

    cout << "  . outros casos" << endl;
    string m2[] = {"....................",
                   ".....A.............A",
                   ".....AA..........A..",
                   ".........A..........",
                   ".......#............",
                   "....................",
                   "....................",
                   "............A.......",
                   "...........A...A....",
                   "..A................."};
    pair<int, int> ans2 = {3,15};
    EXPECT_EQ(ans2, FunWithGraphs::volcano(10, 20, m2));

    string m3[] = {"....................",
                   "....................",
                   "....................",
                   "..#.........A.......",
                   "...#................",
                   "....................",
                   "................A...",
                   ".......#............",
                   "....................",
                   ".....A......A.......",
                   "....................",
                   ".........A..........",
                   "....................",
                   ".................#..",
                   "....................",
                   "....................",
                   "....................",
                   "....#...............",
                   "....................",
                   "...................."};
    pair<int, int> ans3 = {4,9};
    EXPECT_EQ(ans3, FunWithGraphs::volcano(20, 20, m3));

    string m4[] = {".....#....................#...",
                   "......A.......................",
                   "..............................",
                   "..............................",
                   "..............................",
                   "......................#.......",
                   "..............................",
                   ".........A.......A............",
                   "...........#A.................",
                   "..............................",
                   ".............#................",
                   "..............................",
                   ".A............................",
                   "..............................",
                   "......................A.....A.",
                   "..............................",
                   "..............................",
                   "........................#.....",
                   "..............................",
                   ".........A....................",
                   "......#..................A....",
                   "..............................",
                   "..............................",
                   "..............................",
                   "....................A.........",
                   "..............................",
                   "..............................",
                   ".......................#......",
                   "..............................",
                   "....................#......#.."};
    pair<int, int> ans4 = {1,13};
    EXPECT_EQ(ans4, FunWithGraphs::volcano(30, 30, m4));
}

// ----------------------------------------------------------
// Exercicio 4: Quadrados Mágicos
// ----------------------------------------------------------
TEST(test_4, game) {
    cout << "Testando 'game'" << endl;

    cout << "  . caso de exemplo do enunciado" << endl;
    pair<int, string> ans1 = {2,"BC"};
    EXPECT_EQ(ans1, FunWithGraphs::FunWithGraphs::game({4,8,1,3,6,2,7,5}));

    cout << "  . outros casos" << endl;
    pair<int, string> ans2 = {3,"ACC"};
    EXPECT_EQ(ans2, FunWithGraphs::FunWithGraphs::game({8,3,2,5,4,7,6,1}));
    pair<int, string> ans3 = {5,"BCABC"};
    EXPECT_EQ(ans3, FunWithGraphs::FunWithGraphs::game({6,4,5,2,1,7,8,3}));
    pair<int, string> ans4 = {7,"ACABCCB"};
    EXPECT_EQ(ans4, FunWithGraphs::FunWithGraphs::game({6,4,2,8,1,3,5,7}));
    pair<int, string> ans5 = {13,"BBBCBCABCCBBB"};
    EXPECT_EQ(ans5, FunWithGraphs::FunWithGraphs::game({7,1,6,4,3,2,8,5}));
}