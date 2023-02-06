#ifndef SRC_FUNSTACKQUEUEP_H_
#define SRC_FUNSTACKQUEUEP_H_

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class FunStackQueueProblem{
public:
    FunStackQueueProblem();
    static vector<string> binaryNumbers(int n);
    static vector<int> calculateSpan(vector<int> prices);
    static int knightJumps (int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n);
};

#endif