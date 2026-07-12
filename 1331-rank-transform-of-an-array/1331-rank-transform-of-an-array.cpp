class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        int n=temp.size();
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int rank = 1;

        for(int num : temp)
        {
            if(mp.find(num) == mp.end())
            {
                mp[num] = rank;
                rank++;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};