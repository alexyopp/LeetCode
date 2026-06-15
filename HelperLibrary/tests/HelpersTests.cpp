#include "../Helpers.h"
#include <tuple>
#include <cassert>

std::pair<int,int> SumAndDiff(int a, int b)
{
    return {a + b, a - b};
}

std::tuple<int,int,int> ComputeThree(int a, int b, int c)
{
    return {a + b + c, a * b * c, a ^ c};
}

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
    // SumAndDiff
    assert(Helpers::RunTestCase(SumAndDiff, std::make_tuple(5, 3), std::pair<int,int>{8, 2}) == true);

    // ComputeThree
    assert(Helpers::RunTestCase(ComputeThree, std::make_tuple(2, 3, 4), std::tuple<int,int,int>{9, 24, 6}) == true);

    // split_out
    assert(Helpers::RunTestCase(split_out, std::make_tuple(7), std::pair<int,int>{3,4}) == true);

    return 0;
}
