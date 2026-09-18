class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Create valid intervals
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                // Character appears before l -> invalid
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Greedily select intervals with earliest ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};