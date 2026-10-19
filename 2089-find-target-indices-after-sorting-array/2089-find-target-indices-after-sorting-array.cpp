class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_than = 0;
        int equal_to = 0;
        
        for (int num : nums) {
            if (num < target) {
                less_than++;
            } else if (num == target) {
                equal_to++;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < equal_to; i++) {
            result.push_back(less_than + i);
        }
        
        return result;
    }
};