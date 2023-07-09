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

// https://www.codewars.com/kata/5279f6fe5ab7f447890006a7/train/cpp

struct PeakData
{
    std::vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int>& v)
{
    PeakData result;

    int peakIdx = -1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[i - 1])
        {
            peakIdx = i;
        }
        else if (peakIdx != -1 && v[i - 1] > v[i])
        {
            result.pos.push_back(peakIdx);
            result.peaks.push_back(v[peakIdx]);
            peakIdx = -1;
        }
    }

    return result;
}

int main()
{
    PeakData actual = pick_peaks(std::vector<int> { 1, 2, 2, 2, 1 });

    return 0;
}
