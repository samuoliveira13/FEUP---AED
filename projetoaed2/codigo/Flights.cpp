#include <fstream>
#include <sstream>
#include "include/Flights.h"
#include <set>
#include <queue>


Flights::Flights() : nodes(Airports().get_airports_codes().size()+1){
    readvoos();
}


void Flights::addvoo(int src, int dest, string airline) {
    nodes[src].adj.push_back({dest, airline});
    nodes[src].airlines_going_to_airport[dest].push_back(airline);
}


void Flights::readvoos() {
    Airports airports =Airports();
    unordered_map<string,int> count_percursos;
    unordered_map<string,int> airports_codes = airports.get_airports_codes();
    fstream fin;
    fin.open("../files_to_read/flights.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    while(!fin.eof()) {
        row.clear();
        getline(fin, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (row[0] == "Source") continue;
        addvoo(airports_codes[row[0]], airports_codes[row[1]], row[2]);
    }
}


void Flights::bfs(int v, unordered_set<string> companhias) {
    for (int i = 1; i < nodes.size(); i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        // show node order
        //cout << u << " ";
        if(companhias.empty()) {
            for (auto e: nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                }
            }
        }
        else{
            for(auto e:nodes[u].airlines_going_to_airport){
                for(auto airline:e.second) {
                    int w = e.first;
                    if (companhias.find(airline) != companhias.end() && !nodes[w].visited) {
                        q.push(w);
                        nodes[w].visited = true;
                        nodes[w].distance = nodes[u].distance + 1;
                        break;
                    }
                }
            }
        }
    }
}


void Flights::dfs(int x, int dest, set<vector<pair<int,string>>> &result, vector<pair<int,string>> &trying_to_add, unordered_set<string> companhias, int distance_max) {
    trying_to_add.push_back({x,""});
    for(auto edge:nodes[x].airlines_going_to_airport){
        for(auto airline:edge.second) {
            if ((companhias.find(airline) != companhias.end() || companhias.empty()) && nodes[edge.first].distance < distance_max && nodes[edge.first].distance - 1 == nodes[x].distance) {
                int w = edge.first;
                trying_to_add.back().second = airline;
                dfs(w, dest, result, trying_to_add, companhias, distance_max);
            }
            else if ((companhias.find(airline) != companhias.end() || companhias.empty()) && edge.first == dest) {
                trying_to_add.back().second = airline;
                trying_to_add.push_back({dest, ""});
                result.insert(trying_to_add);
                trying_to_add.erase(trying_to_add.end() - 1);
            }
        }
    }
    trying_to_add.erase(trying_to_add.end()-1);
}


set<vector<pair<int,string>>> Flights::airport_to_airport(int src, int dest, unordered_set<string> companhias) {        // ??
    bfs(src,companhias);
    set<vector<pair<int,string>>> result;
    vector<pair<int,string>> trying_to_add;
    dfs(src, dest, result, trying_to_add, companhias, nodes[dest].distance);
    return result;
}


int Flights::count_voos() { //retorna o numero total de voos
    int count = 0;
    for(Node n: nodes){
        count += n.adj.size();
    }
    return count;
}


int Flights::countVoosPorAeroporto(int n) { //retorna o numero de voos no aeroporto n
    return nodes[n].adj.size();
}


int Flights::countVoosPorPais(string country){ //retorna o numero de voos num pais country
    int count = 0;
    for(auto airport: Airports().get_airports()){
        if(airport.second[3] == country){ // ??
            count += countVoosPorAeroporto(airport.first);
        }
    }
    return count;
}


set<string> Flights::destCountries(int n){ //retorna um set com todos os paises que sao destino de voos do aeroporto n
    set<string> dest;
    for(auto voo: nodes[n].adj){
        dest.insert(Airports().get_airports().at(voo.dest)[3]);
    }
    return dest;
}


int Flights::countVoosPorAirportAirline(int n, string airline) {
    int count = 0;
    for(auto voo: nodes[n].adj){
        if(voo.airline == airline) count++;
    }
    return count;
}


set<int> Flights::uniqueVoos(int n){ //retorna todos os aeroportos que sao destino do aeroporto n (nao ha repeticoes)
    set<int> destinos;
    for(auto edge: nodes[n].adj){
        destinos.insert(edge.dest);
    }
    return destinos;
}


set<int> Flights::bfs_reachable_nodes(int v, int y) {
    for (int i = 1; i < nodes.size(); i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    set<int> reachableNodes = {};
    q.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front();
        q.pop();
        // show node order
        //cout << u << " ";
        for (auto e: nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                if(nodes[w].distance <= y) reachableNodes.insert(w);
            }
        }
    }
    return reachableNodes;
}


set<int> Flights::get_reachable_airports(int n, int y) {   //retorna aeroportos atingiveis a partir
    return bfs_reachable_nodes(n, y);                   // do aeroporto n com um maximo de y voos
}
