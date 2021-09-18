/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    map<TreeNode* , TreeNode*>parent;
    set<TreeNode*> visit;

    void findParent(TreeNode* node){
        if(!node) return;
        if(node->left){
            parent[node->left]=node;
            findParent(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return ans;
        findParent(root);
        dfs(target,k);
        return ans;      
    }

    void dfs(TreeNode* root, int k){
        if(visit.find(root) != visit.end())
            return;

        visit.insert(root);
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(root->left){
            dfs(root->left,k-1);
        }
        if(root->right){
            dfs(root->right,k-1);
        }
        TreeNode* p = parent[root];
        if(p){
            dfs(p,k-1);
        }
    }
};