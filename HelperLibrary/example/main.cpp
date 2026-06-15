#include <tuple>
#include <iostream>
#include <utility>

#include "../Helpers.h"

// Function with multiple parameters and multiple outputs (pair)
std::pair<int,int> SumAndDiff(int a, int b)
{
    return {a + b, a - b};
}

// Function with three inputs and three outputs (tuple)
std::tuple<int,int,int> ComputeThree(int a, int b, int c)
{
    return {a + b + c, a * b * c, a ^ c};
}

// Function that uses out-parameters (we'll adapt it to return a pair)
void split(int x, int &a, int &b)
{
    a = x / 2;
    b = x - a;
}

std::pair<int,int> split_out(int x)
{
    int a = 0, b = 0;
    split(x, a, b);
    return {a, b};
}

int main()
{
    // Example 1: call SumAndDiff with a tuple of inputs
    bool ok1 = Helpers::RunTestCase(SumAndDiff, std::make_tuple(5, 3), std::pair<int,int>{8, 2});
    std::cout << "Example 1 (SumAndDiff): " << (ok1 ? "PASS" : "FAIL") << "\n";

    // Example 2: call ComputeThree with a tuple of inputs
    bool ok2 = Helpers::RunTestCase(ComputeThree, std::make_tuple(2, 3, 4), std::tuple<int,int,int>{9, 24, 6});
    std::cout << "Example 2 (ComputeThree): " << (ok2 ? "PASS" : "FAIL") << "\n";

    // Example 3: function with out-parameters adapted to return a pair, called with a single-element tuple
    bool ok3 = Helpers::RunTestCase(split_out, std::make_tuple(7), std::pair<int,int>{3, 4});
    std::cout << "Example 3 (split_out): " << (ok3 ? "PASS" : "FAIL") << "\n";

    return (ok1 && ok2 && ok3) ? 0 : 1;
}
