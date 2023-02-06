// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"
#include <iostream>

using namespace std;

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string &s) {
    string reverse;
    int i = s.size() - 1;
    while (i != -1) {
        reverse += s[i];
        i--;
    }
    return reverse == s;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string &s) {
    string str;
    for (int k = 0; k < s.length(); k++) {
        if (s[k] == ' ' || isalpha(s[k])) continue;
        else
            str += tolower(s[k]);
    }
    return palindrome(str);
}

// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO


int FunWithCycles::nextInterestingNumber(int n, int sum) {
    for (int i = n + 1; i < n + 100000; i++) {
        if (digitSum(i) == sum) return i;
        else continue;
    }
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum = 0;
    int num;
    while (n != 0) {
        num = n % 10;
        sum += num;
        n /= 10;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> &v) {
    int count = 0;
    int max = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i + 1] < v[i]) {
            count++;
            if (count > max)
                max = count;
        }
        else count = 0;
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> &v, int n) {
    return 0;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> &v) {
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> &v) {

}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> &v1, const vector<int> &v2) {
    vector<int> ans;
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    return false;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    return 0;
}
