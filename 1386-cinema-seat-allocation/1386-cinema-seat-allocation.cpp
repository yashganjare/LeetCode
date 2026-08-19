class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto &seat:reservedSeats)
        {
            mp[seat[0]].insert(seat[1]);
        }
        int ans=(n-mp.size())*2;
        for(auto &[row,seat]:mp)
        {
            bool left=!mp[row].count(2) && 
                      !mp[row].count(3) &&
                      !mp[row].count(4) &&
                      !mp[row].count(5);

            bool right=!mp[row].count(6) && 
                      !mp[row].count(7) &&
                      !mp[row].count(8) &&
                      !mp[row].count(9);

            bool middle=!mp[row].count(4) && 
                      !mp[row].count(5) &&
                      !mp[row].count(6) &&
                      !mp[row].count(7);
            if(left && right)
            {
                ans+=2;
            }
            else if(left || middle || right)
            {
                ans+=1;
            }
        }
        return ans;
    }
};