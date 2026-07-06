class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> left;
        vector<int> right;

        // First half
        for (int i = 0; i < n; i++) {
            left.push_back(nums[i]);
        }

        // Second half
        for (int i = n; i < nums.size(); i++) {
            right.push_back(nums[i]);
        }

        vector<int> ans;

        // Shuffle
        for (int i = 0; i < n; i++) {
            ans.push_back(left[i]);
            ans.push_back(right[i]);
        }

        return ans;
    }
};