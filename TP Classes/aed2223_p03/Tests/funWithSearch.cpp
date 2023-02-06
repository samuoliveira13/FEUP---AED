// AED 2022/2023 - Aula Pratica 03
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 02/10/2022]

#include "funWithSearch.h"
#include <climits>
#include <algorithm>

// ----------------------------------------------------------
// Exercicio 1: Pesquisa Elementar
// ----------------------------------------------------------
// TODO
int FunWithSearch::search(const vector<int> &v, int key) {
    int low = 0, high = (int) v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle; // found key
    }
    return -1; // not found
}

// ----------------------------------------------------------
// Exercicio 2: Limite Inferior
// ----------------------------------------------------------
// TODO
int FunWithSearch::lowerBound(const vector<int> &v, int key) {
    int low = 0, high = (int) v.size() - 1;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (v[middle] >= key) high = middle;
        else low = middle + 1;
    }
    if (v[low] < key) return -1;
    return low;
}

// ----------------------------------------------------------
// Exercicio 3: Intervalos
// ----------------------------------------------------------
// TODO
int FunWithSearch::countRange(const vector<int> &v, int a, int b) {
    int low = lowerBound(v,a);
    int high = lowerBound(v, b + 1);
    if (high == -1) high = v.size();
    if (low == -1) return 0;
    return high - low;
}

// ----------------------------------------------------------
// Exercicio 4a: Viagem de mochila às costas (isPossible)
// ----------------------------------------------------------
// TODO
bool FunWithSearch::isPossible(const vector<int> &v, int x, int k) {
    int count = 0;
    int n = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > x) return false;
        if (count + v[i] <= x) {
            count += v[i];
        }
        else {
            n++;
            count = 0;
            i--;
        }
    }
    return n <= k;
}

// ----------------------------------------------------------
// Exercicio 4b: Viagem de mochila às costas (partitions)
// ----------------------------------------------------------
// TODO
int FunWithSearch::partitions(const vector<int> &v, int k) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    int low = 0;
    int high = sum;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (isPossible(v,middle,k)) high = middle;
        else low = middle + 1;
    }
    return low;
}

// ----------------------------------------------------------
// Exercicio 5: Somas mais próximas
// ----------------------------------------------------------
// TODO
vector<int> FunWithSearch::closestSums(const vector<int> &v, const vector<int> &p) {
    vector<int> ans;
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Jogo de strings
// ----------------------------------------------------------
// TODO
int FunWithSearch::stringGame(const string &a, const string &b, const vector<int> &p) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 7: Regras Quadriculadas
// ----------------------------------------------------------
// TODO
long long FunWithSearch::rules(int k, long long a, long long b) {
    return 0;
}