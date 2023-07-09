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

// https://www.codewars.com/kata/5550d638a99ddb113e0000a2/train/cpp

std::vector<int> josephus(std::vector<int> items, int k)
{
    std::queue<int> q;
    std::vector<int> ret;
    for (int elem : items)
    {
        q.push(elem);
    }

    while (q.size() > 0)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        ret.push_back(q.front());
        q.pop();
    }

    return ret;
}

int main()
{
    josephus({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 2);

    return 0;
}
