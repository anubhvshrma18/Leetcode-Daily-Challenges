/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>& B, int n) {
        vector<pair<int, int>>v(n);
        for(int i = 0; i < n; i++)
        v[i] = {B[i], i};	// v = {{4, 0}, {3, 1}, {8, 2}}
        sort(v.begin(), v.end()); // v = {{3, 1}, {4, 0}, {8, 2}}

        int count = 0;
        for(int i = 0; i < n ; i++){
          if(v[i].second == i) continue;
          else{
            count ++;
            swap(v[i], v[v[i].second]);
            i--;
          }
        }
        
        return count;
    }
    int minimumOperations(TreeNode* root) {
        int size, swaps = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> level;
        int i, notM;
        
        while(!q.empty()) {
            size = q.size();
            while(size--) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            
            swaps += minSwaps(level, level.size());
            
            level.clear();
        }
        
        return swaps;
    }
};