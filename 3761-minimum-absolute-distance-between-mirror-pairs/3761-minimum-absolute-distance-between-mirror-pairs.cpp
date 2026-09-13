class Solution {
public:
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) { // <-- Renamed this function
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current number matches a previously reversed number
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }
            
            // Reverse the current number and store its index
            int rev = reverseNum(nums[i]);
            mp[rev] = i; 
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};