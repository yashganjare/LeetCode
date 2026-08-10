class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n==0) return false;
        vector<bool>dp(n+1,false);
        dp[0]=false;
        for(int stones=1;stones<=n;stones++)
        {
            for(int i=1;i*i<=stones;i++)
            {
                int sq=i*i;
                if(dp[stones-sq]==false)
                {
                    dp[stones]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};