class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int count=0;
        if(n>=24)
        {
            count=48+(n%8)*4;
        }
        else if(n>=16)
        {
            count=24+(n%8)*3;
        }
        else if(n>=8)
        {
            count=8+(n%8)*2;
        }
        else 
        {
            count=n;
        }
        return count;
    }
};