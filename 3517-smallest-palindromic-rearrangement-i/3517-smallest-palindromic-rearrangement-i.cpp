class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26);
        string left="";
        char mid=0;
        for(char ch:s)
        {
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            while(freq[i]>=2)
            {
                left+=char('a'+i);
                freq[i]-=2;
            }
            if(freq[i]==1)
            {
                mid=char('a'+i);
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        if(mid)
            return left+mid+right;
        
        return left+right;
    }
};