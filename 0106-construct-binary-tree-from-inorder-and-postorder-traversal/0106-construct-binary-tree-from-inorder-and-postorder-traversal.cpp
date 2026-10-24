
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build_Tree(inorder, 0, inorder.size() - 1,
                          postorder, 0, postorder.size() - 1, mp);
    }

    TreeNode* build_Tree(vector<int>& inorder, int is, int ie,
                         vector<int>& postorder, int ps, int pe,
                         unordered_map<int, int>& mp) {

        if (is > ie || ps > pe) {
            return NULL;
        }

        int nodeval = postorder[pe];
        TreeNode* root = new TreeNode(nodeval);

        int pos = mp[nodeval];
        int numsleft = pos - is;

        // Build right subtree first
        root->right = build_Tree(inorder, pos + 1, ie,
                                 postorder, ps + numsleft, pe - 1, mp);

        // Build left subtree
        root->left = build_Tree(inorder, is, pos - 1,
                                postorder, ps, ps + numsleft - 1, mp);

        return root;
    }
};
