#ifndef PROJETOAED2_FLIGHTS_H
#define PROJETOAED2_FLIGHTS_H

#include <iostream>
#include "Airports.h"
#include <list>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

class Flights {
    struct Edge {
        int dest;
        string airline;
    };
    struct Node {
        list <Edge> adj;
        unordered_map<int, vector<string>> airlines_going_to_airport; // o 1º valor é o codigo do aeroporto de destino, e o vetor são todas
                                                    // as airlines que servem este voo entre o aeroporto de partida e o do destino
        bool visited;
        int distance;
    };
    vector<Node> nodes;

public:
    /// @brief calls readvoos()
    /// @note time complexity O(n)
    Flights();

    /// @brief adds flight to the node
    /// @param src 
    /// @param dest 
    /// @param airline 
    /// @note time complexity O(1)
    void addvoo(int src, int dest, string airline);

    /// @brief reads flights.csv
    /// @note time complexity O(n)
    void readvoos();

    /// @brief depth-first search
    /// @param x 
    /// @param dest 
    /// @param result 
    /// @param trying_to_add 
    /// @param companhias 
    /// @param distance_max 
    /// @note time complexity O(V + E)
    void dfs(int x, int dest, set<vector<pair<int, string>>> &result, vector<pair<int, string>> &trying_to_add, unordered_set<string> companhias, int distance_max);

    /// @brief branch-first search
    /// @param v 
    /// @param companhias 
    /// @note time complexity O(V + E)
    void bfs(int v, unordered_set<string> companhias);

    /// @brief 
    /// @param src 
    /// @param dest 
    /// @param companhias 
    /// @return 
    /// @note time complexity O(E)
    set<vector<pair<int, string>>> airport_to_airport(int src, int dest, unordered_set<string> companhias);

    /// @brief number of flights
    /// @return count
    /// @note time complexity O(n)
    int count_voos();

    /// @brief number of flights in an airport
    /// @param n 
    /// @return count
    /// @note time complexity O(1) 
    int countVoosPorAeroporto(int n);

    /// @brief number of flights in a country
    /// @param country 
    /// @return count
    /// @note time complexity O(n) 
    int countVoosPorPais(string country);

    /// @brief number of flights in an airline
    /// @param n 
    /// @param airline 
    /// @return count
    /// @note time complexity O(m)
    int countVoosPorAirportAirline(int n, string airline);

    /// @brief set of destinations from an airport
    /// @param n 
    /// @return set of destinations
    /// @note time complexity O(m) 
    set<string> destCountries(int n);

    /// @brief unique destinations from a specific airport
    /// @param n 
    /// @returnset of destinations
    /// @note time complexity O(m) 
    set<int> uniqueVoos(int n);

    /// @brief branch-first search
    /// @param v 
    /// @param y 
    /// @return
    /// @note time complexity O(n + m) 
    set<int> bfs_reachable_nodes(int v, int y);

    /// @brief reachable airports
    /// @param n 
    /// @param y 
    /// @return set of reachable airports
    /// @note time complexity O(n + m) 
    set<int> get_reachable_airports(int n, int y);
};



#endif //PROJETOAED2_FLIGHTS_H
