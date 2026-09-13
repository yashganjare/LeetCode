class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>A,B;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1) A.push_back({i,j});
                if(img2[i][j]==1) B.push_back({i,j});
            }
        }
        int best=0;
        map<pair<int,int>,int>mp;
        for(auto &a:A)
        {
            for(auto &b:B)
            {
                int dx=a.first-b.first;
                int dy=a.second-b.second;
                mp[{dx,dy}]++;
                best=max(best,mp[{dx,dy}]);
            }
        }
        return best;
    }
};