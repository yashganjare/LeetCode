class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>status(101,false);
        for(int bulb:bulbs)
        {
            status[bulb]=!status[bulb];
        }
        vector<int>ans;
        for(int i=0;i<101;i++)
        {
            if(status[i]==true)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};