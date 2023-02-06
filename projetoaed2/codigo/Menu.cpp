#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include "include/Menu.h"


Menu::Menu() {
    mainMenu();
}


void Menu::mainMenu() {
    int input;
    cout << "==============================================================" << endl << endl;
    cout << "Bem Vindo" << endl << endl;
    cout << "1 -> Ver qual o melhor trajeto para o percurso que vou realizar" << endl;
    cout << "2 -> Ver informacoes sobre um aeroporto"<< endl;
    cout << "3 -> Ver estatisticas" << endl;
    cout << "outro num -> Sair" << endl;
    cin >> input;
    cout << endl;
    switch (input) {
        case 1:
            get_best_route();
            break;
        case 2:
            get_airport_informations();
        case 3:
            get_statistics();
            break;
    }
}


void Menu::get_best_route() {
    int input;
    int input_origem;
    int input_chegada;
    int function_to_calculate;
    string aeroporto_partida;
    string aeroporto_chegada;
    string cidade_partida;
    string cidade_chegada;
    double lat_partida;
    double lat_chegada;
    double long_partida;
    double long_chegada;
    double kms=25;
    vector<string> possiveis_aeroportos_partida;
    vector<string> possiveis_aeroportos_chegada;
    vector<vector<pair<vector<string>,string>>> result;
    vector<vector<pair<vector<string>,string>>> to_compare;
    unordered_set<string> companhias_permitidas;
    set<string> checking_same_city;
    string companhia;
    cout << "==============================================================" << endl << endl;
    cout << "Deseja por alguma restricao nas linhas aereas possiveis de usar?"<<endl;
    cout << "1-> Sim. Pretendo usar apenas uma/algumas companhias aereas"<<endl;
    cout << "2-> Nao. Posso usar qualquer companhia aerea"<<endl;
    cin >> input;
    cout << endl;
    switch (input) {
        case 1:
            while (true){
                companhia.clear();
                cout<<"Digite o codigo da companhia aerea (pressione 1 caso ja tenha escrito todas as companhias aereas que quer usar)" << endl;
                cin>> companhia;
                if(companhia=="1") break;
                for(auto &x:companhia){
                    x=toupper(x);
                }
                if(airlines.find(companhia)!=airlines.end()) {
                    companhias_permitidas.insert(companhia);
                }
                else cout << "Essa companhia aerea nao existe"<<endl;
            }
            break;
    }
    cout << "==============================================================" << endl << endl;
    cout << "Qual o seu ponto de partida?"<<endl;
    cout << "1-> De um aeroporto"<<endl;
    cout << "2-> De uma cidade"<<endl;
    cout << "3-> Das coordenadas onde me encontro" << endl;
    cin >> input_origem;
    cout << endl;
    cout << "==============================================================" << endl << endl;
    cout << "Qual o seu ponto de chegada?"<<endl;
    cout << "1-> Um aeroporto"<<endl;
    cout << "2-> Uma cidade"<<endl;
    cout << "3-> Um local, com umas certas coordenadas" << endl;
    cin >> input_chegada;
    cout << endl;
    function_to_calculate=input_origem*3+input_chegada-3; //function_to_calculate between 1 and 9
    switch(function_to_calculate){
        case 1:
            cout << "Qual o seu aeroporto de origem? (Digite a sigla)" << endl;
            cin >> aeroporto_partida;
            while(!aeroporto_exists(aeroporto_partida)){
                cout << "Aeroporto invalido, digite novamente a sigla do aeroporto"<< endl;
                cin >> aeroporto_partida;
            }
            cout << "Qual o seu aeroporto de chegada? (Digite a sigla)" << endl;
            cin >> aeroporto_chegada;
            while(!aeroporto_exists(aeroporto_chegada)){
                cout << "Aeroporto invalido, digite novamente a sigla do aeroporto"<< endl;
                cin >> aeroporto_chegada;
            }
            cout<<"Carregando..."<<endl;
            result = airport_to_airport(aeroporto_partida, aeroporto_chegada, companhias_permitidas);
            break;
        case 2:
            cout << "Qual o seu aeroporto de origem? (Digite a sigla)\n";
            cin >> aeroporto_partida;
            while(!aeroporto_exists(aeroporto_partida)){
                cout << "Aeroporto invalido, digite novamente a sigla do aeroporto"<< endl;
                cin >> aeroporto_partida;
            }
            check_cidade_chegada_exists(cidade_chegada);
            possiveis_aeroportos_chegada=airports_by_city[cidade_chegada];
            for(auto x:possiveis_aeroportos_chegada){
                checking_same_city.insert(airports[airports_codes[x]][3]); // insert do país do aeroporto
            }
            if(checking_same_city.size()>1) check_airports(possiveis_aeroportos_chegada,checking_same_city);
            for(auto chegada:possiveis_aeroportos_chegada){
                to_compare= airport_to_airport(aeroporto_partida,chegada,companhias_permitidas);
                if(result.empty()){
                    result = to_compare;
                }
                else if(to_compare.size()!=0){
                    if(result[0].size()==to_compare[0].size()){
                        for(auto x:to_compare){
                            result.push_back(x);
                        }
                    }
                    else if(result[0].size()>to_compare[0].size()){
                        result=to_compare;
                    }
                }
            }
            break;
        case 3:
            cout << "Qual o seu aeroporto de origem? (Digite a sigla)\n";
            cin >> aeroporto_partida;
            while(!aeroporto_exists(aeroporto_partida)){
                cout << "Aeroporto invalido, digite novamente a sigla do aeroporto"<< endl;
                cin >> aeroporto_partida;
            }
            cout << "Digite a longitude do seu destino"<< endl;
            cin >> long_chegada;
            while(long_chegada<-180 || long_chegada>180){
                cout << "Longitude nao valida, escreva-a novamente"<<endl;
                cin >> long_chegada;
            }
            cout << "Digite a latitude do seu destino"<<endl;
            cin >> lat_chegada;
            while (lat_chegada<-180 || lat_chegada>180){
                cout << "Latitude nao valida, escreva-a novamente"<<endl;
                cin >> lat_chegada;
            }
            cout << "Carregando..."<< endl;
            while(possiveis_aeroportos_chegada.empty()){
                for(auto x:airports) {
                    if (is_in_distance(lat_chegada, long_chegada, stod(x.second[4]), stod(x.second[5]),kms))possiveis_aeroportos_chegada.push_back(x.second[0]);
                }
                kms+=10;
            }
            kms-=10;
            for(auto chegada:possiveis_aeroportos_chegada){
                to_compare= airport_to_airport(aeroporto_partida,chegada,companhias_permitidas);
                if(result.empty()){
                    result = to_compare;
                }
                else if(to_compare.size()!=0){
                    if(result[0].size()==to_compare[0].size()){
                        for(auto x:to_compare){
                            result.push_back(x);
                        }
                    }
                    else if(result[0].size()>to_compare[0].size()){
                        result=to_compare;
                    }
                }
            }
            break;
        case 4:
            check_cidade_partida_exists(cidade_partida);
            possiveis_aeroportos_partida=airports_by_city[cidade_partida];
            for(auto x:possiveis_aeroportos_partida){
                checking_same_city.insert(airports[airports_codes[x]][3]); // insert do país do aeroporto
            }
            if(checking_same_city.size()>1) check_airports(possiveis_aeroportos_partida,checking_same_city);
            cout << "Qual o seu aeroporto de chegada? (Digite a sigla)" << endl;
            cin >> aeroporto_chegada;
            while(!aeroporto_exists(aeroporto_chegada)){
                cout << "Aeroporto invalido, digite novamente a sigla do aeroporto"<< endl;
                cin >> aeroporto_chegada;
            }
            cout<<"Carregando..."<<endl;
            for(auto partida:possiveis_aeroportos_partida){
                to_compare= airport_to_airport(partida,aeroporto_chegada,companhias_permitidas);
                if(result.empty()){
                    result = to_compare;
                }
                else if(to_compare.size()!=0){
                    if(result[0].size()==to_compare[0].size()){
                        for(auto x:to_compare){
                            result.push_back(x);
                        }
                    }
                    else if(result[0].size()>to_compare[0].size()){
                        result=to_compare;
                    }
                }
            }
            break;
        case 5:
            check_cidade_partida_exists(cidade_partida);
            possiveis_aeroportos_partida=airports_by_city[cidade_partida];
            for(auto x:possiveis_aeroportos_partida){
                checking_same_city.insert(airports[airports_codes[x]][3]); // insert do país do aeroporto
            }
            if(checking_same_city.size()>1) check_airports(possiveis_aeroportos_partida,checking_same_city);
            check_cidade_chegada_exists(cidade_chegada);
            possiveis_aeroportos_chegada=airports_by_city[cidade_chegada];
            for(auto x:possiveis_aeroportos_chegada){
                checking_same_city.insert(airports[airports_codes[x]][3]); // insert do país do aeroporto
            }
            if(checking_same_city.size()>1) check_airports(possiveis_aeroportos_chegada,checking_same_city);
            cout<<"Carregando..."<<endl;
            for(auto partida:possiveis_aeroportos_partida){
                for(auto chegada:possiveis_aeroportos_chegada) {
                    to_compare = airport_to_airport(partida, chegada, companhias_permitidas);
                    if (result.empty()) {
                        result = to_compare;
                    } else if (to_compare.size() != 0) {
                        if (result[0].size() == to_compare[0].size()) {
                            for (auto x: to_compare) {
                                result.push_back(x);
                            }
                        } else if (result[0].size() > to_compare[0].size()) {
                            result = to_compare;
                        }
                    }
                }
            }
            break;
        case 6:
            check_cidade_partida_exists(cidade_partida);
            possiveis_aeroportos_partida=airports_by_city[cidade_partida];
            for(auto x:possiveis_aeroportos_partida){
                checking_same_city.insert(airports[airports_codes[x]][3]); // insert do país do aeroporto
            }
            if(checking_same_city.size()>1) check_airports(possiveis_aeroportos_partida,checking_same_city);
            cout << "Digite a longitude do seu destino"<< endl;
            cin >> long_chegada;
            while(long_chegada<-180 || long_chegada>180){
                cout << "Longitude nao valida, escreva-a novamente"<<endl;
                cin >> long_chegada;
            }
            cout << "Digite a latitude do seu destino"<<endl;
            cin >> lat_chegada;
            while (lat_chegada<-180 || lat_chegada>180){
                cout << "Latitude nao valida, escreva-a novamente"<<endl;
                cin >> lat_chegada;
            }
            cout << "Carregando..."<< endl;
            while(possiveis_aeroportos_chegada.empty()){
                for(auto x:airports) {
                    if (is_in_distance(lat_chegada, long_chegada, stod(x.second[4]), stod(x.second[5]),kms))possiveis_aeroportos_chegada.push_back(x.second[0]);
                }
                kms+=10;
            }
            kms-=10;
            for(auto partida:possiveis_aeroportos_partida){
                for(auto chegada:possiveis_aeroportos_chegada) {
                    to_compare = airport_to_airport(partida, chegada, companhias_permitidas);
                    if (result.empty()) {
                        result = to_compare;
                    } else if (to_compare.size() != 0) {
                        if (result[0].size() == to_compare[0].size()) {
                            for (auto x: to_compare) {
                                result.push_back(x);
                            }
                        } else if (result[0].size() > to_compare[0].size()) {
                            result = to_compare;
                        }
                    }
                }
            }
            break;
        case 7:
            cout << "Digite a longitude do seu ponto de partida"<< endl;
            cin >> long_partida;
            while(long_partida<-180 || long_partida>180){
                cout << "Longitude nao valida, escreva-a novamente"<<endl;
                cin >> long_partida;
            }
            cout << "Digite a latitude do seu ponto de partida"<<endl;
            cin >> lat_partida;
            while (lat_partida<-180 || lat_partida>180){
                cout << "Latitude nao valida, escreva-a novamente"<<endl;
                cin >> lat_partida;
            }
            while(possiveis_aeroportos_partida.empty()){
                for(auto x:airports) {
                    if (is_in_distance(lat_partida, long_partida, stod(x.second[4]), stod(x.second[5]),kms)) possiveis_aeroportos_partida.push_back(x.second[0]);
                }
                kms+=10;
            }
            cout << "Qual o seu aeroporto de chegada? (Digite a sigla)" << endl;
            cin >> aeroporto_chegada;
            while(!aeroporto_exists(aeroporto_chegada)){
                cout << "Aeroporto invalido, digite novamente a sigla do aeroporto"<< endl;
                cin >> aeroporto_chegada;
            }
            cout<<"Carregando..."<<endl;
            for(auto partida:possiveis_aeroportos_partida){
                to_compare= airport_to_airport(partida,aeroporto_chegada,companhias_permitidas);
                if(result.empty()){
                    result = to_compare;
                }
                else if(to_compare.size()!=0){
                    if(result[0].size()==to_compare[0].size()){
                        for(auto x:to_compare){
                            result.push_back(x);
                        }
                    }
                    else if(result[0].size()>to_compare[0].size()){
                        result=to_compare;
                    }
                }
            }
            break;
        case 8:
            cout << "Digite a longitude do seu ponto de partida"<< endl;
            cin >> long_partida;
            while(long_partida<-180 || long_partida>180){
                cout << "Longitude nao valida, escreva-a novamente"<<endl;
                cin >> long_partida;
            }
            cout << "Digite a latitude do seu ponto de partida"<<endl;
            cin >> lat_partida;
            while (lat_partida<-180 || lat_partida>180){
                cout << "Latitude nao valida, escreva-a novamente"<<endl;
                cin >> lat_partida;
            }
            while(possiveis_aeroportos_partida.empty()){
                for(auto x:airports) {
                    if (is_in_distance(lat_partida, long_partida, stod(x.second[4]), stod(x.second[5]),kms)) possiveis_aeroportos_partida.push_back(x.second[0]);
                }
                kms+=10;
            }
            check_cidade_chegada_exists(cidade_chegada);
            possiveis_aeroportos_chegada=airports_by_city[cidade_chegada];
            for(auto x:possiveis_aeroportos_chegada){
                checking_same_city.insert(airports[airports_codes[x]][3]); // insert do país do aeroporto
            }
            if(checking_same_city.size()>1) check_airports(possiveis_aeroportos_chegada,checking_same_city);
            cout<<"Carregando..."<<endl;
            for(auto partida:possiveis_aeroportos_partida){
                for(auto chegada:possiveis_aeroportos_chegada) {
                    to_compare = airport_to_airport(partida, chegada, companhias_permitidas);
                    if (result.empty()) {
                        result = to_compare;
                    } else if (to_compare.size() != 0) {
                        if (result[0].size() == to_compare[0].size()) {
                            for (auto x: to_compare) {
                                result.push_back(x);
                            }
                        } else if (result[0].size() > to_compare[0].size()) {
                            result = to_compare;
                        }
                    }
                }
            }
            break;
        case 9:
            cout << "Digite a longitude do seu ponto de partida"<< endl;
            cin >> long_partida;
            while(long_partida<-180 || long_partida>180){
                cout << "Longitude nao valida, escreva-a novamente"<<endl;
                cin >> long_partida;
            }
            cout << "Digite a latitude do seu ponto de partida"<<endl;
            cin >> lat_partida;
            while (lat_partida<-180 || lat_partida>180){
                cout << "Latitude nao valida, escreva-a novamente"<<endl;
                cin >> lat_partida;
            }
            while(possiveis_aeroportos_partida.empty()){
                for(auto x:airports) {
                    if (is_in_distance(lat_partida, long_partida, stod(x.second[4]), stod(x.second[5]),kms)) possiveis_aeroportos_partida.push_back(x.second[0]);
                }
                kms+=10;
            }
            kms=25;
            cout << "Digite a longitude do seu destino"<< endl;
            cin >> long_chegada;
            while(long_chegada<-180 || long_chegada>180){
                cout << "Longitude nao valida, escreva-a novamente"<<endl;
                cin >> long_chegada;
            }
            cout << "Digite a latitude do seu destino"<<endl;
            cin >> lat_chegada;
            while (lat_chegada<-180 || lat_chegada>180){
                cout << "Latitude nao valida, escreva-a novamente"<<endl;
                cin >> lat_chegada;
            }
            cout << "Carregando..."<< endl;
            while(possiveis_aeroportos_chegada.empty()){
                for(auto x:airports) {
                    if (is_in_distance(lat_chegada, long_chegada, stod(x.second[4]), stod(x.second[5]),kms))possiveis_aeroportos_chegada.push_back(x.second[0]);
                }
                kms+=10;
            }
            kms-=10;
            for(auto partida:possiveis_aeroportos_partida){
                for(auto chegada:possiveis_aeroportos_chegada) {
                    to_compare = airport_to_airport(partida, chegada, companhias_permitidas);
                    if (result.empty()) {
                        result = to_compare;
                    } else if (to_compare.size() != 0) {
                        if (result[0].size() == to_compare[0].size()) {
                            for (auto x: to_compare) {
                                result.push_back(x);
                            }
                        } else if (result[0].size() > to_compare[0].size()) {
                            result = to_compare;
                        }
                    }
                }
            }
            break;
    }
    if(result.size()==0){
        cout << "Nao foi possivel encontrar uma rota entre esses 2 pontos, com as restricoes que colocou"<<endl;
    }
    else {
        cout << "Aqui esta(o) retratadada(s) a(s) melhor(es) forma(s) de chegar desde o seu local de partida ate ao seu destino:"<< endl;
        for (int i = 0; i < result.size();i++){
            cout << i+1 << " forma:" << endl;
            for (auto aeroporto: result[i]){
                cout << aeroporto.first[1] << ", " << aeroporto.first[2] << ", " << aeroporto.first[3] ;
                if(result[i][result[i].size()-1]!=aeroporto) cout << ", usando a companhia aerea "<< aeroporto.second << "-> ";
                else cout << ";" << endl<<endl;
            }
        }
        if(function_to_calculate==3 || function_to_calculate==6 || function_to_calculate==9)
            cout<< endl << "Se usar um destes voos, todos estes aeroportos de chegada ficarao a menos de " << kms << "kms das coordenadas pretendidas;"<< endl;
    }
    done();
}


vector<vector<pair<vector<string>,string>>> Menu::airport_to_airport(string partida, string chegada, unordered_set<string> companhias) {
    int x=airports_codes[partida];
    int y=airports_codes[chegada];
    set<vector<pair<int,string>>> fastest_way=flights.airport_to_airport(x,y,companhias);
    vector<vector<pair<vector<string>,string>>> result;
    vector<pair<vector<string>,string>> adding;
    for(auto vetor:fastest_way){
        for(auto element:vetor){
            adding.push_back({airports[element.first],element.second});
        }
        result.push_back(adding);
        adding.clear();
    }
    return result;
}


void Menu::get_airport_informations() {
    string airport;
    cout << "Por favor digite a sigla do aeroporto." << endl;
    cin >> airport;
    while (!aeroporto_exists(airport)) {
        cout << "Aeroporto invalido." << endl;
        getline(cin, airport);
    }
    int cod_aeroporto = airports_codes.at(airport);
    int input;
    cout << "==============================================================" << endl << endl;
    cout << "1 -> Ver quantos voos existem a partir de " << airport << "." << endl;
    cout << "2 -> Ver quantos voos, de cada companhia, existem a partir de " << airport << endl;
    cout << "3 -> Ver destinos possiveis a partir de " << airport << endl;
    cout << "4 -> Ver paises possiveis partindo de " << airport << endl;
    cout << "5 -> Ver quantos e quais aeroportos, cidades ou paises sao atingiveis usando um maximo de Y voos?" << endl;
    cout << "outro num -> Sair" << endl;
    cin >> input;
    cout << endl;
    switch (input) {
        case 1: {
            cout << "Existem " << flights.countVoosPorAeroporto(cod_aeroporto) << " voos a partir de " << airport
                 << endl;
            done();
            break;
        }
        case 2: {
            cout << "airline" << "   " << "numero de voos" << endl;
            for(auto airline: airlines){
                int voos_from_airline = flights.countVoosPorAirportAirline(cod_aeroporto, airline);
                if(voos_from_airline == 0) continue;
                else{
                    cout << airline << "   -->    " << voos_from_airline << endl;
                }
            }
            done();
            break;
        }
        case 3:{
            cout << "Existem " << flights.uniqueVoos(cod_aeroporto).size() << " destinos:" << endl;
            for(int i: flights.uniqueVoos(cod_aeroporto)){
                cout  << airports.at(i)[0]<< " | "<< airports.at(i)[1] << ", " << airports.at(i)[2] << ", " << airports.at(i)[3] << endl;
            }
            done();
            break;
        }
        case 4:{
            cout << "Existem " << flights.destCountries(cod_aeroporto).size() << " paises de destino:" << endl;
            for(string country: flights.destCountries(cod_aeroporto)){
                cout << country << endl;
            }
            done();
            break;
        }

        case 5:{
            int y;
            cout << "Introduza o valor de y: ";
            cin >> y;
            cout << "==============================================================" << endl << endl;
            cout << "1 -> Ver quantos aeroportos sao atingiveis usando um maximo de " << y << " voos?" << endl;
            cout << "2 -> Ver quantas cidades sao atingiveis usando um maximo de " << y << " voos?" << endl;
            cout << "3 -> Ver quantos paises sao atingiveis usando um maximo de " << y << " voos?" << endl;
            cout << "outro num -> Sair" << endl;
            cin >> input;
            set<int> reachableAirports = flights.get_reachable_airports(cod_aeroporto, y);
            switch (input) {
                case 1:{
                    cout << "Sao atingiveis " << reachableAirports.size() << " aeroportos a partir de " << airport << endl;
                    for(int i: reachableAirports){
                        cout  << airports.at(i)[0]<< " | "<< airports.at(i)[1] << ", " << airports.at(i)[2] << ", " << airports.at(i)[3] << endl;
                    }
                    done();
                    break;
                }
                case 2:{
                    set<string> reachableCities;
                    for(int i: reachableAirports){
                        reachableCities.insert(airports.at(i)[2]);
                    }
                    cout << "Sao atingiveis " << reachableCities.size() << " cidades a partir de " << airport << endl;
                    for(string city: reachableCities){
                            cout << city << endl;
                    }
                    done();
                    break;
                }
                case 3:{
                    set<string> reachableCountries;
                    for(int i: reachableAirports){
                        reachableCountries.insert(airports.at(i)[3]);
                    }
                    cout << "Sao atingiveis " << reachableCountries.size() << " paises a partir de " << airport << endl;
                    for(string country: reachableCountries){
                        cout << country << endl;
                    }
                    done();
                    break;
                }
            }
            done();
            break;
        }
    }
}


void Menu::get_statistics() {
    int input;
    cout << "==============================================================" << endl << endl;
    cout << "1 -> Ver estatisticas globais" << endl;
    cout << "2 -> Ver estatisticas de um pais" << endl;
    cout << "outro num -> Sair" << endl;
    cin >> input;
    cout << endl;
    switch (input) {
        case 1: //ver estatisticas globais
            cout << "==============================================================" << endl << endl;
            cout << "1 -> numero de aeroportos" << endl;
            cout << "2 -> numero de voos" << endl;
            cout << "3 -> numero de companhias" << endl;
            cout << "4 -> top 10 aeroportos com mais voos" << endl;
            cout << "outro num -> Sair" << endl;
            cin >> input;
            switch (input) {
                case 1:
                    cout << "Existem " << airports.size() << " aeroportos a nivel mundial." << endl << endl;
                    done();
                    break;
                case 2:
                    cout << "Existem " << flights.count_voos() << " voos a nivel mundial" << endl << endl;
                    done();
                    break;
                case 3:
                    cout << "Existem " << airlines.size() << " companhias" << endl << endl;
                    done();
                    break;
                case 4:
                    vector<pair<int, int>> top10 = {};
                    int min;
                    for (auto airport: airports) {
                        int i = airport.first;
                        int n = flights.countVoosPorAeroporto(i);
                        if (top10.size() < 10) {
                            top10.push_back({n, i});
                        } else if (top10.size() >= 10) {
                            sort(top10.rbegin(), top10.rend());

                            min = top10[9].first;
                            if (n > min) {
                                top10.erase(top10.end() - 1);
                                top10.push_back({n, i});
                            }
                        }
                    }
                    sort(top10.rbegin(), top10.rend());
                    cout << "Os 10 aeroportos com mais voos sao:" << endl;
                    for (int j = 0; j <= 9; j++) {
                        pair<int, int> i = top10[j];
                        cout << j + 1 << ". " << airports.at(i.second)[1] << ", " << airports.at(i.second)[2] << ", "
                             << airports.at(i.second)[3] << endl << endl;
                    }
                    cout << endl;
                    done();
                    break;
            }
            break;

        case 2: {//ver estatisticas de um pais
            string country;
            cout << "Por favor digite o nome do pais." << endl;
            cin >> country;
            //getline(cin, country);
            set<string> countries = Airports().getCountries();
            while (countries.find(country) == countries.end()) {
                cout << "Pais invalido. Certifique-se que escreve o pais com a primeira letra de cada palavra em maiuscula." << endl;
                getline(cin, country);
            }
            cout << "==============================================================" << endl << endl;
            cout << "1 -> numero de aeroportos" << endl;
            cout << "2 -> numero de voos" << endl;
            cout << "3 -> numero de companhias" << endl;
            cout << "4 -> top 10 paises com mais voos" << endl;
            cout << "outro num -> Sair" << endl;
            cin >> input;
            switch (input) {
                case 1:
                    cout << "Existem " << airports_by_country[country].size() << " aeroportos." << endl;
                    done();
                    break;

                case 2: {
                    int count = 0;
                    for (auto airport: airports) {
                        if (airport.second[3] == country)
                            count += flights.countVoosPorAeroporto(airport.first);
                    }
                    cout << "Existem " << count << " voos." << endl << endl;
                    done();
                    break;
                }

                case 3:{
                    cout << "Existem " << airlines_by_country[country].size() << " companhias." << endl << endl;
                    done();
                    break;
                }

                case 4: {
                    vector<pair<int, string>> top10 = {};
                    int min;
                    for(auto country: Airports().getCountries()){
                        int n = flights.countVoosPorPais(country);
                        if (top10.size() < 10) {
                            top10.push_back({n, country});
                        } else if (top10.size() >= 10) {
                            sort(top10.rbegin(), top10.rend());
                            min = top10[9].first;
                            if (n > min) {
                                top10.erase(top10.end() - 1);
                                top10.push_back({n, country});
                            }
                        }
                    }
                    sort(top10.rbegin(), top10.rend());
                    cout << "Os 10 paises com mais voos sao:" << endl;
                    for (int j = 0; j <= 9; j++) {
                        pair<int, string> i = top10[j];
                        cout << j + 1 << ". " << i.second << endl;
                    }
                    cout << endl;
                    done();
                    break;
                }

            }
            break;
        }
    }
}


bool Menu::aeroporto_exists(string &aeroporto) {
    for(auto &x : aeroporto) x = toupper(x);
    return (airports_codes.find(aeroporto)!=airports_codes.end());
}


void Menu::check_cidade_partida_exists(string &cidade) {
    cout << "Qual a sua cidade de partida?\n";
    cin.ignore();
    getline(cin,cidade);
    while(true) {
        for (int i = 0; i < cidade.size(); i++) {
            if (i > 0) {
                if (cidade[i - 1] != ' ') {
                    cidade[i] = tolower(cidade[i]);
                } else cidade[i] = toupper(cidade[i]);
            } else cidade[i] = toupper(cidade[i]);
        }
        if(airports_by_city.find(cidade)!=airports_by_city.end()) break;
        else{
            cout << "Cidade invalida, escreva novamente a cidade pretendida" << endl;
            getline(cin,cidade);
        }
    }
}


void Menu::check_cidade_chegada_exists(string &cidade) {
    cout << "Qual a sua cidade de chegada?\n";
    cin.ignore();
    getline(cin,cidade);
    while(true) {
        for (int i = 0; i < cidade.size(); i++) {
            if (i > 0) {
                if (cidade[i - 1] != ' ') {
                    cidade[i] = tolower(cidade[i]);
                } else cidade[i] = toupper(cidade[i]);
            } else cidade[i] = toupper(cidade[i]);
        }
        if(airports_by_city.find(cidade) != airports_by_city.end()) break;
        else{
            cout << "Cidade invalida, escreva novamente a cidade pretendida" << endl;
            getline(cin,cidade);
        }
    }
}


void Menu::check_airports(vector<string> &possiveis_aeroportos, set<string> paises) {
    string country;
    cout << "A nome da cidade que escolheu pertence a mais do que um pais."<<endl;
    cout << "Por favor digite o pais a que pertence a cidade escolhida."<<endl;
    getline(cin,country);
    while(paises.find(country)==paises.end()){
        cout << "Pais invalido. Certifique-se que escreve o pais com a primeira letra de cada palavra em maiuscula."<<endl;
        getline(cin,country);
    }
    auto x=possiveis_aeroportos.begin();
    while(x!=possiveis_aeroportos.end()) {
        if (airports[airports_codes[*x]][3] != country) possiveis_aeroportos.erase(x);
        else x++;
    }
}


void Menu::done() {
    int input;
    cout << "Deseja fazer mais alguma coisa?"<<endl<<endl;
    cout << "1 -> Sim: Voltar ao menu principal"<< endl;
    cout << "Outro Numero- > Nao e sair"<< endl;
    cin >> input;
    switch (input) {
        case 1:
            mainMenu();
            break;
        default:
            exit(-1);
    }
}


bool Menu::is_in_distance(double lat1, double long1, double lat2, double long2, double value) {
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (long2 - long1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return (rad * c)<=value;
}
