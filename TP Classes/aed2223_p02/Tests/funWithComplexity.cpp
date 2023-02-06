// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO
int FunWithComplexity::maxSubArray(const vector<int> &v) {
    unsigned n = v.size();
    int sum = 0;
    int maxSoFar = v[0]; // porque é esta uma boa escolha para a melhor soma inicial?
    for (unsigned i = 0; i < n; i++) { // todas as posicoes iniciais possiveis
        for (unsigned j = i; j < n; j++) { // todas as posicoes finais possiveis
            sum += v[j];
            if (sum > maxSoFar) maxSoFar = sum;
        }
        sum = 0;
    }
    return maxSoFar;

}


// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> &v, int k, int t) {
    int count = 0, sum = 0;
    for (int a = 0; a < k; a++) {
        if (v[a] >= t) count++;
    }
    if (count >= k/2.0) sum++;
    for (int a = k; a < v.size(); a++) {
        if (v[a] >= t) count++;
        if (v[a - k] >= t) count--;
        if (count >= k/2.0) sum++;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}