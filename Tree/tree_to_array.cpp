#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 这种递归方式会更简单一些
vector<int> rec;
void pre_tree_new(TreeNode* root){
    if(!root){return ;}
    pre_tree_new(root->left);
    rec.push_back(root->val);
    pre_tree_new(root->right);
}




// vector<int> pre_tree(TreeNode* root){
//     vector<int> l, r, ans;
//     if(!root){return l;}
//     ans.push_back(root->val);
//     l = pre_tree(root->left);
//     r = pre_tree(root->right);
//     for(auto i : l){
//         ans.push_back(i);
//     }
//     for(auto i : r){
//         ans.push_back(i);
//     }
//     return ans;
// }

// vector<int> mid_tree(TreeNode* root){
//     vector<int> l, r, ans;
//     if(!root){return l;}
//     l = mid_tree(root->left);
//     r = mid_tree(root->right);
//     for(auto i : l){
//         ans.push_back(i);
//     }
//     ans.push_back(root->val);
//     for(auto i : r){
//         ans.push_back(i);
//     }
//     return ans;
// }

// vector<int> post_tree(TreeNode* root){
//     vector<int> l, r, ans;
//     if(!root){return l;}
//     l = post_tree(root->left);
//     r = post_tree(root->right);
//     for(auto i : l){
//         ans.push_back(i);
//     }
//     for(auto i : r){
//         ans.push_back(i);
//     }
//     ans.push_back(root->val);
//     return ans;
// }



