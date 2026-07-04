class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto &edge:roads)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<bool>visited(n+1,false);
        visited[1]=true;
        queue<int>q;
        q.push(1);
        int ans=INT_MAX;
        while(!q.empty())
        {
            auto u=q.front();
            visited[u]=true;
            q.pop();
            for(auto &[v,w]:graph[u])
            {
                ans=min(ans,w);
                if(!visited[v])
                {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};