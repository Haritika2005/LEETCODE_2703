
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
    void findparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* current = que.front();
            que.pop();

            if (current->left) {
                parent_track[current->left] = current;
                que.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                que.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        findparent(root, parent_track);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            if (distance == k) {
                break;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && !visited.count(current->left)) {
                    q.push(current->left);
                    visited.insert(current->left);
                }

                if (current->right && !visited.count(current->right)) {
                    q.push(current->right);
                    visited.insert(current->right);
                }

                if (parent_track.count(current) &&
                    !visited.count(parent_track[current])) {
                    q.push(parent_track[current]);
                    visited.insert(parent_track[current]);
                }
            }

            distance++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
