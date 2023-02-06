#include <fstream>
#include <sstream>
#include <set>
#include "include/Airports.h"


Airports::Airports(){
    read_airports();
}


unordered_map<int,vector<string>> Airports::get_airports(){
    return airports;
}


unordered_map<string,int> Airports::get_airports_codes() {
    return airports_codes;
}


unordered_map<string, vector<string>> Airports::get_airports_by_city() {
    return airports_by_city;
}


unordered_map<string, vector<string>> Airports::get_airports_by_country() {
    return airports_by_country;
}


void Airports::read_airports() {
    int airport_count=0;
    fstream fin;
    fin.open("../files_to_read/airports.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        if(line== "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (airport_count==0){
            airport_count++;
            continue;
        }
        airports[airport_count]=row;
        airports_codes[row[0]]=airport_count;
        airports_by_city[row[2]].push_back(row[0]);
        airports_by_country[row[3]].push_back(row[0]);
        airport_count++;
    }
}


set<string> Airports::getCountries(){
    set<string> countries;
    for(auto airport: airports){
        countries.insert(airport.second[3]);
    }
    return countries;
}
