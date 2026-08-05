class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<bool>suspicious(n,false);
        for(auto &edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        function<void(int)>dfs=[&](int u)
        {
            suspicious[u]=true;
            for(int v:graph[u])
            {
                if(!suspicious[v])
                {
                    dfs(v);
                }
            }
        };
        dfs(k);
        vector<int>ans;
        for(auto &edge:edges)
        {
            if(!suspicious[edge[0]] && suspicious[edge[1]])
            {
                for(int i=0;i<n;i++)
                {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!suspicious[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};