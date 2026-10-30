class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int index, vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index >= candidates.size() || target < 0) {
            return;
        }

        temp.push_back(candidates[index]);

        solve(index, candidates, target - candidates[index]);

        temp.pop_back();

        solve(index + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};