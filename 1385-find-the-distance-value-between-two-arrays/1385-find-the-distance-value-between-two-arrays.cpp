class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count=0;
        for(int num1:arr1)
        {
            bool isFar=true;
            for(int num2:arr2)
            {
                if(abs(num1-num2)<=d) 
                {
                    isFar=false;
                    break;
                }
            }
            if(isFar) count++;
        }
        return count;
    }
};