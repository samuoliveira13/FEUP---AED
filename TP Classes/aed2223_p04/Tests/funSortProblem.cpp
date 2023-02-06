#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------
bool operator<(Product a, Product b){
    if (a.getPrice() == b.getPrice()) return a.getWeight() < b.getWeight();
    else return a.getPrice() < b.getPrice();
}

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(),products.end());
    while (products.size() > k) {
        products.pop_back();
        k++;                    //pq aumentar 1?
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    vector<unsigned> values1 = values;
    unsigned mindif = INT_MAX;
    int size = values1.size();
    if(nc > size) return -1;
    else{
        sort(values1.begin(), values1.end());
        for(int i = 0 ; i < size - nc + 1; i++){
            if((values1[i + (nc - 1)]  - values1[i]) < mindif)
                mindif = values1[i + (nc - 1)]  - values1[i];
        }
    }
    return mindif;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    vector<int> v1 = v;
    std::sort(v1.begin(), v1.end());
    if (v == v1) return 0;
    else {
        int count = 1;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                count++;
                i--;
            }
        }
        return count;
    }
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

