class Solution {
public:
    int MOD=1e9+7;
    int dp[201][201][201];
    int solve(int index,int g1,int g2,vector<int>&nums)
    {
        if(index==nums.size())
        {
            if(g1==g2 && g1!=0)
                return 1;
            return 0;
        }
        if(dp[index][g1][g2]!=-1) return dp[index][g1][g2];
        long long ans=0;
        //skip nums[i] 
        ans=(ans+solve(index+1,g1,g2,nums))%MOD;
        //include nums[i] in g1
        ans=(ans+solve(index+1,gcd(g1,nums[index]),g2,nums))%MOD;
        //include nums[i] in g2
        ans=(ans+solve(index+1,g1,gcd(g2,nums[index]),nums))%MOD;
        return dp[index][g1][g2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums);
    }
};