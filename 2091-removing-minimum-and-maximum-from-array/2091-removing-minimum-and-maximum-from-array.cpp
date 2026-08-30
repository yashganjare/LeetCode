class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int min_Ind=0,max_Ind=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<nums[min_Ind])
            {
                min_Ind=i;
            }
            if(nums[i]>nums[max_Ind])
            {
                max_Ind=i;
            }
        }
        int left=min(min_Ind,max_Ind);
        int right=max(min_Ind,max_Ind);
        int opt1=right+1;
        int opt2=n-left;
        int opt3=(left+1)+(n-right);
        return min({opt1,opt2,opt3});
    }
};