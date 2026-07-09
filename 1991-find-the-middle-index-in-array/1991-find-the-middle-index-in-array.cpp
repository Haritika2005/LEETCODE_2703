class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++)
        {
            tsum+=nums[i];


        }
        for(int i=0;i<n;i++)
        {
            r=tsum-l-nums[i];
            if(l==r)
            return i;
            l=l+nums[i];
        }
        return -1;

    }
};