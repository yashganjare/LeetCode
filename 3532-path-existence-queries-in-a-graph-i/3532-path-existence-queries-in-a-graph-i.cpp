class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>path(n,0);
        path[0]=0;
        for(int i=1;i<n;i++)
        {
            path[i]=path[i-1]+(nums[i]-nums[i-1]>maxDiff);
        }
        vector<bool>ans;
        for(auto &query:queries)
        {
            ans.push_back(path[query[0]]==path[query[1]]);
        }
        return ans;
    }
};