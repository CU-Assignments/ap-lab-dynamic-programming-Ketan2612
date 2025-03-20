class Solution {
    public:
        int length(vector<int> &nums,vector<int> &dp,int i)
        {
            if(dp[i] != -1)
            {
                return dp[i];
            } 
            int res=0,c=0;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                {
                    c=1;
                    res=max(res,length(nums,dp,j));
                }
            }
            dp[i]=res+1;
            return res+1;
        }
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size(),-1);
            int res=0;
            for(int j=0;j<nums.size();j++)
            {
                res=max(res,length(nums,dp,j));
            }
            return res;
        }
    };