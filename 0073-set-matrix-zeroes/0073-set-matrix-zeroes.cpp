class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool zeroInFirstCol=false;
        for(int row=0;row<m;row++)
        {
            if(matrix[row][0]==0) zeroInFirstCol=true;
            for(int col=1;col<n;col++)
            {
                if(matrix[row][col]==0)
                {
                    matrix[row][0]=0;
                    matrix[0][col]=0;
                }
            }
        }
        for(int row=m-1;row>=0;row--)
        {
            for(int col=n-1;col>=1;col--)
            {
                if(matrix[row][0]==0 || matrix[0][col]==0)
                {
                    matrix[row][col]=0;
                }
            }
            if(zeroInFirstCol)
            {
                matrix[row][0]=0;
            }
        }
    }
};