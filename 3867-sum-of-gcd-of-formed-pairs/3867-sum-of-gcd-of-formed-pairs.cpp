class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int Mx=nums[0];
        int n=nums.size();
        vector<int>prefixGCD(n);
        prefixGCD[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            Mx=max(Mx,nums[i]);
            prefixGCD[i]=gcd(Mx,nums[i]);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int left=0,right=n-1;
        long long ans=0;
        while(left<right)
        {
            ans+=gcd(prefixGCD[left++],prefixGCD[right--]);
        }
        return ans;
    }
};