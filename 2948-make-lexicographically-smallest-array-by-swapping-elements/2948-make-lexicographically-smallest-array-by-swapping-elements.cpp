class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Step 1: Store value and original index
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort according to values
        sort(arr.begin(), arr.end());

        vector<int> result(n);

        int start = 0;

        // Step 3: Process every group
        while (start < n) {

            int end = start;

            // Find the complete connected group
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            vector<int> values;
            vector<int> indices;

            // Collect values and original indices
            for (int i = start; i <= end; i++) {
                values.push_back(arr[i].first);
                indices.push_back(arr[i].second);
            }

            // Step 4: Sort indices
            sort(indices.begin(), indices.end());

            // Step 5: Put smallest values at smallest indices
            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = values[i];
            }

            // Move to next group
            start = end + 1;
        }

        return result;
    }
};