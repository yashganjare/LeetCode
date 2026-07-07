class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0,sum=0,place=1;
        while(n>0)
        {
            int digit=n%10;
            if(digit!=0)
            {
                x=x+digit*place;
                sum+=digit;
                place*=10;
            }
            n/=10;
        }
        return sum*x;
    }
};