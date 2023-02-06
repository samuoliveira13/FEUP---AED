#ifndef PROJETOAED2_MENU_H
#define PROJETOAED2_MENU_H

#include "Flights.h"
#include "Airports.h"
#include "Airlines.h"

class Menu{
public:
    /// @brief calls main menu
    /// @note time complexty O(1)
    Menu();

    /// @brief main menu
    /// @note time complexty O(1)
    void mainMenu();

    /// @brief gets best route from one place to another
    void get_best_route();

    /// @brief 
    /// @param partida 
    /// @param chegada 
    /// @param companhias 
    /// @return 
    /// @note time complexity O(m*m) where n is the size of fastest_way and m is the size of vetor.
    vector<vector<pair<vector<string>,string>>> airport_to_airport(string partida, string chegada, unordered_set<string> companhias);

    /// @brief checks if the airport exists
    /// @param aeroporto 
    /// @return true or false
    /// @note time complexity O(1)
    bool aeroporto_exists(string &aeroporto);

    /// @brief checks if the destination city exists
    /// @param cidade 
    /// @note time complexity O(n)
    void check_cidade_chegada_exists(string &cidade);

    /// @brief checks if the departure city exists
    /// @param cidade 
    /// @note time complexity O(n)
    void check_cidade_partida_exists(string &cidade);

    /// @brief executes everytime at the end of an operation
    /// @note time complexity O(1)
    void done();

    /// @brief checks if two airports are within a certain distance of each other
    /// @param lat1 
    /// @param long1 
    /// @param lat2 
    /// @param long2 
    /// @param value 
    /// @return true or false
    /// @note time complexity O(1)
    bool is_in_distance(double lat1, double long1,double lat2, double long2, double value);

    /// @brief checks airports in a set of countries
    /// @param possiveis_aeroportos 
    /// @param paises
    /// @note time complexity O(n) 
    void check_airports(vector<string> &possiveis_aeroportos, set<string> paises);

    /// @brief global and countries' statistics (number of flights, airports, airlines, and top 10 airports with most flights)
    /// @note O(n * log(n))
    void get_statistics();

    /// @brief informations about an airport (flights, airlines, reachable destinations)
    /// @note time complexity O(n)
    void get_airport_informations();

private:
    Flights flights = Flights();
    unordered_map<string,int> airports_codes=Airports().get_airports_codes();
    unordered_map<int,vector<string>> airports=Airports().get_airports();
    unordered_map<string,vector<string>> airports_by_city=Airports().get_airports_by_city();
    unordered_map<string,vector<string>> airports_by_country=Airports().get_airports_by_country();
    unordered_set<string> airlines=Airlines().get_airlines();
    unordered_map<string,vector<string>> airlines_by_country=Airlines().get_airlines_by_country();

};
#endif //PROJETOAED2_MENU_H
