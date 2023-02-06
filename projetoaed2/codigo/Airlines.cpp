#include <fstream>
#include <sstream>
#include "include/Airlines.h"


Airlines::Airlines(){
    read_airlines();
}


unordered_set<string> Airlines::get_airlines() {
    return airlines;
}


unordered_map<string,vector<string>> Airlines::get_airlines_by_country(){
    return airlines_by_country;
}


void Airlines::read_airlines() {
    int airline_count=0;
    fstream fin;
    fin.open("../files_to_read/airlines.csv", ios::in);
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
        if (airline_count==0){
            airline_count++;
            continue;
        }
        airlines.insert(row[0]);
        airlines_by_country[row[3]].push_back(row[1]);
    }
}
