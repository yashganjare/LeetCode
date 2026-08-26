class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string curr="";
            int countOnes=0;
            for(int j=i;j<n;j++)
            {
                curr+=s[j];
                if(s[j]=='1') countOnes++;
                if(countOnes>k) break;
                if(countOnes==k)
                {
                    if(ans.size()==0 || ans.size()>curr.size() || (ans.size()==curr.size() && curr<ans))
                    {
                        ans=curr;
                    }
                }
            }
        }
        return ans;
    }
};