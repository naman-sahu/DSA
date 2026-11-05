
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;

        // Count frequency of nums1
        for (int num : nums1) {
            mp[num]++;
        }

        // Find common elements
        for (int num : nums2) {
            if (mp[num] > 0) {
                ans.push_back(num);
                mp[num]--;
            }
        }

        return ans;
    }
};
