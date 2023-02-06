#ifndef PROJETOAED2_AIRPORTS_H
#define PROJETOAED2_AIRPORTS_H

#include <unordered_map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Airports{

public:
    /// @brief calls read_airports
    /// @note time complexity O(n)
    Airports();

    /// @brief reads airports.csv
    /// @note time complexity O(n)
    void read_airports();

    /// @brief returns airports
    /// @return airports
    ///@note time complexity O(1)
    unordered_map<int, vector<string>> get_airports();

    /// @brief returns airport's codes
    /// @return airport's codes
    ///@note time complexity O(1)
    unordered_map<string,int> get_airports_codes();

    /// @brief returns airports in a city
    /// @return airports in a city
    ///@note time complexity O(1)
    unordered_map<string,vector<string>> get_airports_by_city();

    /// @brief returns airports in a country
    /// @return airports in a country
    ///@note time complexity O(1)
    unordered_map<string,vector<string>> get_airports_by_country();

    /// @brief returns countries
    /// @return set of countries
    ///@note time complexity O(n)
    set<string> getCountries();

private:
    unordered_map<int,vector<string>> airports;
    unordered_map<string,int> airports_codes;
    unordered_map<string,vector<string>> airports_by_city;
    unordered_map<string,vector<string>> airports_by_country;

};
#endif //PROJETOAED2_AIRPORTS_H
