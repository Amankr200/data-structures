class Solution {
public:
    void findCombinations(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If we reach end of array or target becomes negative, return
        if (index == candidates.size() || target < 0)
            return;

        // Choice 1: Include current element
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, candidates, target - candidates[index], current, result);
            current.pop_back(); // backtrack
        }

        // Choice 2: Exclude current element and move to next
        findCombinations(index + 1, candidates, target, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, candidates, target, current, result);
        return result;
    }
};
