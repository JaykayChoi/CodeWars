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

// https://www.codewars.com/kata/57e5279b7cf1aea5cf000359/train/cpp

class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int value;
};

class Solution
{
public:
    static int maxSum(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        return root->value
            + std::max(Solution::maxSum(root->left), Solution::maxSum(root->right));
    }
};

int main() { return 0; }
