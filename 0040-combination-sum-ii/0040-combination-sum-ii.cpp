class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& res){
        int n = candidates.size();
        if (target == 0){
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < n; i++){
            if (candidates[i] > target){
                continue;
            }

            // We skip a node that's already checked
            if (i > idx && candidates[i] == candidates[i - 1]){
                continue;
            }

            curr.push_back(candidates[i]);

            // A node can only be used once, so we check the next candidates
            dfs(candidates, target - candidates[i], curr, i + 1, res);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> curr;

        dfs(candidates, target, curr, 0, res);

        return res;
    }
};