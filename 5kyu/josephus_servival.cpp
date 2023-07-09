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

// https://www.codewars.com/kata/555624b601231dc7a400017a/train/cpp

int josephusSurvivor(int n, int k)
{
    std::queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        q.pop();
    }

    return q.front();
}

int main()
{
    std::cout << josephusSurvivor(7, 3) << std::endl;

    return 0;
}
