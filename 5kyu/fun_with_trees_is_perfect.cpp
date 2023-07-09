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

// https://www.codewars.com/kata/57dd79bff6df9b103b00010f/train/cpp

class TreeNode
{
public:
    static bool isPerfect(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }

        if (!root->right && !root->left)
        {
            return true;
        }

        if (!root->right || !root->left)
        {
            return false;
        }

        if (getHeight(root->left) != getHeight(root->right))
        {
            return false;
        }

        return isPerfect(root->right) && isPerfect(root->left);
    }

    static TreeNode* getHeight(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    static TreeNode* leaf() { return new TreeNode(); }

    static TreeNode* join(TreeNode* left, TreeNode* right)
    {
        return (new TreeNode())->withChildren(left, right);
    }

    TreeNode* withLeft(TreeNode* left)
    {
        this->left = left;
        return this;
    }

    TreeNode* withRight(TreeNode* right)
    {
        this->right = right;
        return this;
    }

    TreeNode* withChildren(TreeNode* left, TreeNode* right)
    {
        this->left = left;
        this->right = right;
        return this;
    }

    TreeNode* withLeftLeaf() { return withLeft(leaf()); }

    TreeNode* withRightLeaf() { return withRight(leaf()); }

    TreeNode* withLeaves() { return withChildren(leaf(), leaf()); }

private:
    TreeNode* left;
    TreeNode* right;

    TreeNode()
        : left(NULL)
        , right(NULL)
    {
    }
};

int main() { return 0; }
