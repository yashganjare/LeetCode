class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        k%=total;
        vector<vector<int>>res(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int Idx=i*n+j;
                int newIdx=(Idx+k)%total;
                int row=newIdx/n;
                int col=newIdx%n;
                res[row][col]=grid[i][j];
            }
        }
        return res;
    }
};