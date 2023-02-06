#include "funStackQueueProblem.h"
#include "cell.h"

FunStackQueueProblem::FunStackQueueProblem() {}


//-----------------------------------------------------------------

// TODO
vector<string> FunStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> bin;

    if (n == 0) return res;

    bin.push("1");
    for (int i = 2; i <= n; i++) {
        bin.push(bin.front() + "0");
        bin.push(bin.front() + "1");
        res.push_back(bin.front());
        bin.pop();
    }
    res.push_back(bin.front());
    return res;
}


//TODO
vector<int> FunStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    int count = 1;
    stack<int> s;
    stack<int> copy;
    for (int i = 0; i < prices.size(); i++) {
        count = 1;
        copy = s;
        if(s.empty()){
            res.push_back(1);
            s.push(prices[i]);
            continue;
        }
        while(prices[i] > copy.top() && !copy.empty()){
            count++;
            copy.pop();
        }
        res.push_back(count);
        s.push(prices[i]);
    }

    return res;
}


//TODO
int FunStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}






