class Solution {
public:

    void getpath(TreeNode* root, string path, vector<string>& ans) 
    {

        if(root == NULL)
            return;

        path += to_string(root->val);

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";

        getpath(root->left, path, ans);
        getpath(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        if(root == NULL)
            return ans;

        getpath(root, "", ans);

        return ans;
    }
};