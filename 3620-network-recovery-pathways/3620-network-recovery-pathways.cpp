class Solution {
public:
    bool dijkstra(int minEdge,int n,long long k,vector<vector<pair<int,int>>>&AdjList)
    {
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dist[0]=0;
        pq.push({0,0}); //currDist,node
        while(!pq.empty())
        {
            auto [currDist,u]=pq.top();
            pq.pop();
            if(currDist>k) return false;
            if(u==n-1) return true;
            if(currDist>dist[u]) continue;
            for(auto &[v,weight]:AdjList[u])
            {
                if(weight<minEdge) continue;
                long long newDist=currDist+weight;
                if(newDist<dist[v])
                {
                    dist[v]=newDist;
                    pq.push({newDist,v});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>>AdjList(n);
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(!online[u] || !online[v]) continue;
            AdjList[u].push_back({v,w});
            low=min(low,w);
            high=max(high,w);
        }
        if(!dijkstra(low,n,k,AdjList)) return -1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(dijkstra(mid,n,k,AdjList))
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};