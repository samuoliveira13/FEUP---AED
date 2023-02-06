#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>
#include "stackExt.h"
#include "funStackQueueProblem.h"
#include <string>

using testing::Eq;

TEST(test_, FindMin){
    StackExt<int> s1;
    // Testing empty()
    EXPECT_EQ(true, s1.empty());
    // Testing push() e top()
    s1.push(6);
    s1.push(4);
    s1.push(7);
    s1.push(2);
    s1.push(5);
    EXPECT_EQ(5, s1.top());
    // Testing pop() e top()
    s1.pop();
    s1.pop();
    EXPECT_EQ(7, s1.top());

    // Testing findMin()
    EXPECT_EQ(4, s1.findMin());
    s1.push(3);
    EXPECT_EQ(3, s1.findMin());
    s1.push(3);
    s1.pop();
    EXPECT_EQ(3, s1.findMin());

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    EXPECT_EQ(true, s1.empty());
}

TEST(test_, BinaryNumbers) {
    vector<string> res = FunStackQueueProblem::binaryNumbers(2);
    vector<string> resok= {"1","10"};
    EXPECT_EQ(true, resok==res);

    res.clear(); res = FunStackQueueProblem::binaryNumbers(5);
    resok= {"1","10","11","100","101"};
    EXPECT_EQ(true, resok==res);

    res.clear(); res = FunStackQueueProblem::binaryNumbers(0);
    EXPECT_EQ(true, res.empty());
}


TEST(test_, StockSpan) {
    vector<int> res = FunStackQueueProblem::calculateSpan({100,80,60,70,60,75,85});
    vector<int> resok = {1,1,1,2,1,4,6};
    EXPECT_EQ(true, resok==res);
    res = FunStackQueueProblem::calculateSpan({10,4,5,90,120,80});
    resok = {1,1,2,4,5,1};
    EXPECT_EQ(true, resok==res);
    res = FunStackQueueProblem::calculateSpan({40,35,37,36,41});
    resok = {1,1,2,1,5};
    EXPECT_EQ(true, resok==res);
    res = FunStackQueueProblem::calculateSpan({10,4,5,90,120,80});
    resok = {1,1,2,4,5,1};
    EXPECT_EQ(true, resok==res);
    res = FunStackQueueProblem::calculateSpan({});
    EXPECT_EQ(true,res.empty());
}

TEST(test_, KnightJumps) {
    int res = FunStackQueueProblem::knightJumps(4, 5, 1, 1, 6);
    EXPECT_EQ(3, res);
    res = FunStackQueueProblem::knightJumps(1, 1, 15, 15, 16);
    EXPECT_EQ(10, res);
    res = FunStackQueueProblem::knightJumps(2, 8, 8, 4, 8);
    EXPECT_EQ(4, res);
    res = FunStackQueueProblem::knightJumps(4, 5, 4, 5, 6);
    EXPECT_EQ(0, res);
}

//----------------------------------------- BENCHMARK

static void BM_FindMin(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        StackExt<long> s1;
        for (long i=0;i< state.range(0); i++)
            s1.push (i%10+3);
        state.ResumeTiming();
        // This code gets timed
        s1.findMin();
    }
    state.SetComplexityN(state.range(0));
}

static void BM_BinaryNumbers(benchmark::State& state) {
    for (auto _ : state) {
        FunStackQueueProblem::binaryNumbers(state.range(0));
    }
    state.SetComplexityN(state.range(0));
}


static void BM_StockSpan(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        vector<int> s;
        for (int i=0;i< state.range(0); i++) {
            s.push_back(i%10+3);
        }
        state.ResumeTiming();
        // This code gets timed
        FunStackQueueProblem::calculateSpan(s);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_KnightJumps(benchmark::State& state) {
    for (auto _ : state) {
        FunStackQueueProblem::knightJumps(4,5,1,1,state.range(0));
    }
    state.SetComplexityN(state.range(0));
}

// ------------------------------------------------ retirar comentarios para verificar complexidade
// Register the functions as a benchmark

/*
BENCHMARK(BM_FindMin)
        ->Unit(benchmark::kNanosecond)
        ->Range(1<<2, 1<<6)
        ->Complexity();
*/

/*
BENCHMARK(BM_BinaryNumbers)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_StockSpan)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_KnightJumps)
        ->Unit(benchmark::kNanosecond)
        ->Range(1<<2, 1<<10)
        ->Complexity();
*/

