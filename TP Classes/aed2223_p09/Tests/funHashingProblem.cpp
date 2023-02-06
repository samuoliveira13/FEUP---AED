#include "funHashingProblem.h"
#include <unordered_set>
#include <unordered_map>

FunHashingProblem::FunHashingProblem() {}

// -------------------------------------

// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_map<int,int> map;
    for (int i = 0; i < values.size(); i++) {
        map[values[i]]++;
        if (i > k) map[values[i - k - 1]]--;
        if (map[values[i]] > 1) res.push_back(values[i]);
    }
    for (auto pair : map) {
        cout << pair.first << ',' << pair.second << ';';
        cout << endl;
    }
    return res;
}