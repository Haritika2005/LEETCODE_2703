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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        TreeNode* target=NULL;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            if(node->val==start)
            {
                target=node;
            }
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
             if(node->right)
            {
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        // burn the bfs
        unordered_map<TreeNode*,bool>visited;
        int time=-1;
        q.push(target);
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            time++;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parent.count(node)&&!visited[parent[node]])
                {
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
        }
    
        return time;
        
    }
};