class Solution {
public:
    bool sumGame(string nums) {
        int n=nums.size();
        double ans=0.0;
        for(int i=0;i<n/2;i++) 
        {
            ans+=(nums[i]=='?' ? 4.5 : nums[i]-'0');
        }
        for(int i=n/2;i<n;i++)
        {
            ans-=(nums[i]=='?' ? 4.5 : nums[i]-'0');
        }
        return ans!=0.0;
    }
};