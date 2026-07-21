class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes=0;
        for(char ch:s)
        {
            if(ch=='1') totalOnes++;
        }
        string t="1"+s+"1";
        vector<int>groups;
        vector<char>characters;
        int i=0;
        int n=t.size();
        while(i<n)
        {
            int j=i;
            while(j<n && t[j]==t[i])
            {
                j++;
            }
            characters.push_back(t[i]);
            groups.push_back(j-i);
            i=j;
        }
        int maxGain=0;
        for(int i=1;i<groups.size();i++)
        {
            if(characters[i]=='1' && characters[i-1]=='0' && characters[i+1]=='0')
            {
                maxGain=max(maxGain,groups[i-1]+groups[i+1]);
            }
        }
        return totalOnes+maxGain;
    }
};