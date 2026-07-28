class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int firstMax=INT_MIN,secondMax=INT_MIN;
        int idx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>firstMax)
            {
                idx = i;
                secondMax=firstMax;
                firstMax=nums[i];
            }
            else if(nums[i]>secondMax)
            {
                secondMax=nums[i];
            }
        }
        if((secondMax*2)<=firstMax) return idx;
        return -1;
    }
};