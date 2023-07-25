#pragma warning(disable : 4996)
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

// https://www.codewars.com/kata/5263c6999e0f40dee200059d/train/cpp

// ┌───┬───┬───┐
// │ 1 │ 2 │ 3 │
// ├───┼───┼───┤
// │ 4 │ 5 │ 6 │
// ├───┼───┼───┤
// │ 7 │ 8 │ 9 │
// └───┼───┼───┘
//     │ 0 │
//     └───┘

const std::map<int, std::vector<int>> map { { 1, { 1, 2, 4 } }, { 2, { 1, 2, 3, 5 } },
    { 3, { 2, 3, 6 } }, { 4, { 1, 4, 5, 7 } }, { 5, { 2, 4, 5, 6, 8 } },
    { 6, { 3, 5, 6, 9 } }, { 7, { 4, 7, 8 } }, { 8, { 0, 5, 7, 8, 9 } },
    { 9, { 6, 8, 9 } }, { 0, { 0, 8 } } };

// My solutions.
void combinate(std::string curStr, int curIdx,
    const std::vector<std::vector<int>>& numbers, std::vector<std::string>& ret)
{
    if (curIdx == numbers.size())
    {
        ret.push_back(curStr);
        return;
    }

    for (int num : numbers[curIdx])
    {
        combinate(curStr + std::to_string(num), curIdx + 1, numbers, ret);
    }
}

std::vector<std::string> get_pins(std::string observed)
{
    std::vector<std::vector<int>> numbers;
    for (const char& c : observed)
    {
        int x = c - '0';
        std::vector<int> clone(map.at(x));
        numbers.push_back(clone);
    }

    std::vector<std::string> ret;
    combinate("", 0, numbers, ret);
    return ret;
}

int main()
{
    //
    return 0;
}

// Best solutions.
std::vector<std::string> get_pins2(
    const std::string& observed, const std::string& prefix = "")
{
    static const std::map<char, std::string> neighbors
        = { { '1', "124" }, { '2', "1235" }, { '3', "236" }, { '4', "1457" },
              { '5', "24568" }, { '6', "3569" }, { '7', "478" }, { '8', "05789" },
              { '9', "689" }, { '0', "08" } };
    if (!observed.size())
    {
        return { prefix };
    }
    std::vector<std::string> pins;
    for (auto c : neighbors.at(observed[0]))
    {
        for (auto pin : get_pins2(observed.substr(1), prefix + c))
        {
            pins.push_back(pin);
        }
    }
    return pins;
}