class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0,start=-1;
        int n=nums.size();
        unordered_map<int,int>map;
        for(int end=0;end<n;end++)
        {
            map[nums[end]]++;
            while(map[nums[end]]>k)
            {
                start++;
                map[nums[start]]--;
            }
            ans=max(ans,end-start);
        }
        return ans;
    }
};