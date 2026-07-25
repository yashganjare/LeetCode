class Solution {
public:
    int maxProduct(int n) {
        int FirstMax=0,SecondMax=0;
        while(n>0)
        {
            int num=n%10;
            if(num>FirstMax)
            {
                SecondMax=FirstMax;
                FirstMax=num;
            }
            else if(num>SecondMax)
            {
                SecondMax=num;
            }
            n/=10;
        }
        return FirstMax*SecondMax;
    }
};