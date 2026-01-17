class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& res){
        int n = candidates.size();
        if (target < 0){
            return;
        }

        if (target == 0){
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < n; i++){
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, curr, res);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<vector<int>> res;
        vector<int> curr;
        dfs(candidates, target, 0, curr, res);

        return res;
    }
};