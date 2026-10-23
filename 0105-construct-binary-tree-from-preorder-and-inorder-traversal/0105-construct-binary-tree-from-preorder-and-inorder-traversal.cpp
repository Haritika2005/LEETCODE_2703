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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int preIndex=0;
        return build(preorder,inorder,mp,preIndex,0,inorder.size()-1);
        
    }
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&mp,int &preIndex,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int rootvalue=preorder[preIndex++];
        TreeNode* root= new TreeNode(rootvalue);
        int position=mp[rootvalue];


        
          root->left=  build(preorder,inorder,mp,preIndex,start,position-1);
          root->right=build(preorder,inorder,mp,preIndex,position+1,end);
          return root;
        
    }
};