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

// https://www.codewars.com/kata/55983863da40caa2c900004e/train/cpp

typedef long long long_t;

// My solution.
long_t nextBigger(long_t n)
{
    if (n < 10)
    {
        return -1;
    }
    std::vector<int> digits;
    long_t num = n;
    while (num > 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    int numDigits = digits.size();
    int pivot = -1;
    std::vector<int> rearrageCandidate { digits.front() };
    for (int i = 1; i < numDigits; i++)
    {
        rearrageCandidate.push_back(digits[i]);
        if (digits[i] < digits[i - 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        return -1;
    }

    std::sort(rearrageCandidate.begin(), rearrageCandidate.end());

    int newPivotVal = -1;

    int rearrageCandidateSize = rearrageCandidate.size();
    for (int i = 0; i < rearrageCandidateSize; i++)
    {
        if (rearrageCandidate[i] > digits[pivot])
        {
            newPivotVal = rearrageCandidate[i];
            rearrageCandidate.erase(rearrageCandidate.begin() + i);
            rearrageCandidateSize--;
            break;
        }
    }

    long_t ret = 0;
    for (int i = numDigits - 1; i > pivot; i--)
    {
        ret += digits[i] * pow(10, i);
    }

    ret += newPivotVal * pow(10, pivot);

    for (int i = 0; i < rearrageCandidateSize; i++)
    {
        ret += rearrageCandidate[i] * pow(10, rearrageCandidateSize - 1 - i);
    }

    return ret;
}

int main()
{

    // 609569982799741554
    long_t v = 609569982799741554; // 609569982799744155
    std::cout << nextBigger(v) << std::endl;

    return 0;
}

// Best solutions.
long nextBigger2(long n)
{
    std::string str = std::to_string(n);
    return std::next_permutation(str.begin(), str.end()) ? std::stol(str) : -1;
}