#ifndef PROJETOAED2_AIRLINES_H
#define PROJETOAED2_AIRLINES_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Airlines{
public:
    /// @brief calls read_airlines()
    /// @note time complexity O(n)
    Airlines();

    /// @brief reads airlines.csv
    /// @note time complexity O(n)
    void read_airlines();

    /// @brief returns airlines
    /// @return airlines
    ///@note time complexity O(1)
    unordered_set<string> get_airlines();

    /// @brief returns airlines in a country
    /// @return airlines in a country
    ///@note time complexity O(1)
    unordered_map<string,vector<string>> get_airlines_by_country();

private:
    unordered_set<string> airlines;
    unordered_map<string,vector<string>> airlines_by_country;
};
#endif //PROJETOAED2_AIRLINES_H
