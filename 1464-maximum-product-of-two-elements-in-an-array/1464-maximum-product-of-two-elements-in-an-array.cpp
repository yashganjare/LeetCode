class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int FirstMax=INT_MIN,SecondMax=INT_MIN;
        for(int num:nums)
        {
            if(num>FirstMax)
            {
                SecondMax=FirstMax;
                FirstMax=num;
            }
            else if(num>SecondMax)
            {
                SecondMax=num;
            }
        }
        return (FirstMax-1)*(SecondMax-1);
    }
};