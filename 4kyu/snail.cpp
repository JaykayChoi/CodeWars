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

// https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/train/cpp

// 12345
// 12345
// 12345
// 12345
// 12345

// 123
// 894
// 765

// My solution.
std::vector<int> snail(const std::vector<std::vector<int>>& map)
{
    int size = map.size();
    if (size == 0 || map[0].size() == 0)
    {
        return {};
    }
    std::vector<int> ret;
    for (int i = 0; i < ceil(size / 2.); i++)
    {
        std::vector<int> top = map[i];
        for (int j = i; j < size - i; j++)
        {
            ret.push_back(top[j]);
        }

        for (int j = i + 1; j < size - i - 1; j++)
        {
            std::vector<int> middle = map[j];
            int v = middle[size - 1 - i];
            ret.push_back(v);
        }

        if (size - 1 - i < 0 || i == size - 1 - i)
        {
            continue;
        }
        std::vector<int> bottom = map[size - 1 - i];
        for (int j = size - 1 - i; j >= i; j--)
        {
            ret.push_back(bottom[j]);
        }

        for (int j = size - 2 - i; j >= i + 1; j--)
        {
            std::vector<int> middle = map[j];
            int v = middle[i];
            ret.push_back(v);
        }
    }

    return ret;
}

// Best solutions.
std::vector<int> snail2(const std::vector<std::vector<int>>& xs)
{
    std::vector<int> res;
    if (xs[0].empty())
        return res;
    const std::size_t ny = xs.size(), nx = xs[0].size();
    res.reserve(ny * nx);
    std::ptrdiff_t x0 = 0, y0 = 0, x1 = nx - 1, y1 = ny - 1, x = 0, y = 0;
    while (y0 <= y1)
    {
        while (x < x1)
            res.push_back(xs[y][x++]);
        y0++;
        while (y < y1)
            res.push_back(xs[y++][x]);
        x1--;
        while (x > x0)
            res.push_back(xs[y][x--]);
        y1--;
        while (y > y0)
            res.push_back(xs[y--][x]);
        x0++;
    }
    res.push_back(xs[y][x]);
    return res;
}

inline std::vector<int> snail3(std::vector<std::vector<int>> array)
{
    int leftlimit = 0, uplimit = 0, rightlimit = array[0].size() - 1,
        downlimit = rightlimit, cx = -1, cy = -1;
    std::vector<int> ans;
    while (leftlimit <= rightlimit)
    {
        for (cy++, uplimit++, cx++; cx <= rightlimit; cx++)
            ans.push_back(array[cy][cx]);
        for (cx--, rightlimit--, cy++; cy <= downlimit; cy++)
            ans.push_back(array[cy][cx]);
        for (cy--, downlimit--, cx--; cx >= leftlimit; cx--)
            ans.push_back(array[cy][cx]);
        for (cx++, leftlimit++, cy--; cy >= uplimit; cy--)
            ans.push_back(array[cy][cx]);
    }
    return ans;
}

int main()
{
    snail({ {} });
    // snail({ { 1, 2 }, { 4, 3 } });
    // snail({ { 1, 2, 3, 4 }, { 12, 13, 14, 5 }, { 11, 16, 15, 6 }, { 10, 9, 8, 7 } });
    return 0;
}
