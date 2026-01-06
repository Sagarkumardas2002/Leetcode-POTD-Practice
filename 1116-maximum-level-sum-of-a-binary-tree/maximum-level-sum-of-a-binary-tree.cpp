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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int level=1;
        priority_queue<pair<long long, int>>pq;

        while(!q.empty()){
            int n=q.size();
            long long sum=0;
            
            for(int i=0;i<n;i++){
               TreeNode *node=q.front();
               q.pop();

               sum+=node->val;

               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
            }
            pq.push({sum,-level});
            level++;
        }
        return -pq.top().second;
    }
};