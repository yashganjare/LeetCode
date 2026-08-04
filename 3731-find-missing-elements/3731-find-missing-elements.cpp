class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<nums.size();i++)
        {
            int num=nums[i-1]+1;
            while(nums[i]!=num)
            {
                ans.push_back(num);
                num=num+1;
            }
        }
        return ans;
    }
};