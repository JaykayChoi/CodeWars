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

// https://www.codewars.com/kata/57e5a6a67fbcc9ba900021cd/train/cpp

class TreeNode
{
public:
    TreeNode(int value, TreeNode* left, TreeNode* right)
        : m_value(value)
        , m_left(left)
        , m_right(right)
    {
    }

    TreeNode(int value)
        : m_value(value)
        , m_left(NULL)
        , m_right(NULL)
    {
    }

    int m_value;
    TreeNode* m_left;
    TreeNode* m_right;
};

class Solution
{
public:
    static TreeNode* arrayToTree(std::vector<int> arr)
    {
        if (arr.size() == 0)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            TreeNode* newNode = new TreeNode(arr[i]);

            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode* curNode = q.front();
                q.pop();

                if (!curNode->m_left)
                {
                    curNode->m_left = newNode;
                    break;
                }
                else if (!curNode->m_right)
                {
                    curNode->m_right = newNode;
                    break;
                }
                else
                {
                    q.push(curNode->m_left);
                    q.push(curNode->m_right);
                }
            }
        }

        return root;
    }
};

int main() { return 0; }
