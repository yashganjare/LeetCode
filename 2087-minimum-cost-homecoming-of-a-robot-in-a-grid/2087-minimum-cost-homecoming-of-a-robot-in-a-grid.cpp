class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r1=startPos[0];
        int r2=homePos[0];
        int c1=startPos[1];
        int c2=homePos[1];
        int ans=0;
        if(r2>=r1)
        {
            ans+=accumulate(rowCosts.begin()+r1+1,rowCosts.begin()+r2+1,0);
        }
        else 
            ans+=accumulate(rowCosts.begin()+r2,rowCosts.begin()+r1,0);

        if(c2>=c1)
        {
            ans+=accumulate(colCosts.begin()+c1+1,colCosts.begin()+c2+1,0);
        }
        else 
            ans+=accumulate(colCosts.begin()+c2,colCosts.begin()+c1,0);

        return ans;
    }
};