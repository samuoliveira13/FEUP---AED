#include "funListProblem.h"
#include <algorithm>

FunListProblem::FunListProblem() {}


//-----------------------------------------------------------------

// TODO
list<int> FunListProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    for(auto itr = values.begin();itr != values.end(); itr++) {
        if (*itr > x) {
            l1.push_back(*itr);
            itr = values.erase(itr);
            itr--;
        }
    }
    return l1;
}



//TODO
list<pair<int,int>> FunListProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    if (values.empty()) return res;
    values.sort();
    auto itr = values.begin();
    res.push_back(*itr);
    auto it = res.begin();
    itr++;
    while (itr != values.end()) {
        if (itr->first < it->second) {
            it->second = max(itr->second,it->second);
        }
        else {
            res.push_back(*itr);
            it++;
        }
        itr++;
    }
    return res;
}
