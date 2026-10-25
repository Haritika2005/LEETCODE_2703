class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curnode = q.front();
            q.pop();

            if (curnode == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(curnode->val) + ",");
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!getline(s, str, ',')) break;

            if (str == "#") {
                node->left = NULL;
            } else {
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

            // Right child
            if (!getline(s, str, ',')) break;

            if (str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }

        return root;
    }
};
// TreeNode* ans = deser.deserialize(ser.serialize(root));