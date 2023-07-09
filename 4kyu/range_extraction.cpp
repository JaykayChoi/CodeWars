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

// https://www.codewars.com/kata/51ba717bb08c1cd60f00002f/train/cpp

void append_str_from_cache(std::string& str, const std::vector<int>& cache)
{
    if (!str.empty())
    {
        str.append(",");
    }
    str.append(std::to_string(cache.front()));
    int size = cache.size();
    if (size == 1)
    {
        return;
    }
    if (size == 2)
    {
        str.append(",");
    }
    else
    {
        str.append("-");
    }
    str.append(std::to_string(cache.back()));
}

std::string range_extraction(std::vector<int> args)
{
    std::string ret;
    std::vector<int> cache;
    for (int x : args)
    {
        if (cache.empty())
        {
            cache.push_back(x);
            continue;
        }
        if (cache.back() + 1 == x)
        {
            cache.push_back(x);
            continue;
        }
        append_str_from_cache(ret, cache);
        cache.clear();
        cache.push_back(x);
    }

    if (!cache.empty())
    {
        append_str_from_cache(ret, cache);
    }
    return ret;
}

int main()
{
    // -6,-3-1,3-5,7-11,14,15,17-20
    std::cout << range_extraction(
        { -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20 })
              << std::endl;

    return 0;
}
