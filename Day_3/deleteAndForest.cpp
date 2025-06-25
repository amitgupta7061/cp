#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void f(TreeNode* root, unordered_set<int> &del, vector<TreeNode*> &result){
        if(root == NULL) return;

        f(root->left, del, result);
        f(root->right, del, result);

        if(root->left and del.count(root->left->val)){
            if(root->left->left) result.push_back(root->left->left);
            if(root->left->right) result.push_back(root->left->right);
            root->left = NULL;
        } 
        if(root->right and del.count(root->right->val)){
            if(root->right->left) result.push_back(root->right->left);
            if(root->right->right) result.push_back(root->right->right);
            root->right = NULL;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del (to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        f(root, del, result); 
        if(del.count(root->val)){
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
        } else{
            result.push_back(root);
        }
        return result;
    }
};


int main() {

    return 0;
}