class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string lower=to_string(low);
        string higher=to_string(high);
        string to_compare="123456789";
        for(int i=lower.size();i<=higher.size();i++)
        {
            for(int j=0;j<=9-i;j++)
            {
                int num=stoi(to_compare.substr(j,i));
                if(num>high) break;
                if(num>=low && num<=high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};