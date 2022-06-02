// 路径总和

// 给定一个二叉树，它的每个结点都存放着一个整数值。

// 找出路径和等于给定数值的路径总数。

// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

// 二叉树不超过 1000 个节点，且节点数值范围是[-1000000,1000000]的整数。




#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int count(TreeNode* root, int targetSum){
        if(!root)return 0;
        return (root->val == targetSum)+count(root->left, targetSum-root->val)+count(root->right, targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        return count(root, targetSum)+pathSum(root->left, targetSum)+pathSum(root->right, targetSum);
    }
};
