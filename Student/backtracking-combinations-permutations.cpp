#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 组合问题：从 n 个数中选 k 个数
void combineHelper(int n, int k, int startIndex, vector<int>& path, vector<vector<int>>& result) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= n; i++) {
        path.push_back(i);
        combineHelper(n, k, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    combineHelper(n, k, 1, path, result);
    return result;
}

// 排列问题：全排列
void permuteHelper(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        permuteHelper(nums, used, path, result);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    permuteHelper(nums, used, path, result);
    return result;
}

void printResult(const vector<vector<int>>& res) {
    for (const auto& row : res) {
        cout << "[";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i] << (i == row.size() - 1 ? "" : ",");
        }
        cout << "] ";
    }
    cout << endl;
}

int main() {
    cout << "Combinations (n=4, k=2):" << endl;
    vector<vector<int>> res1 = combine(4, 2);
    printResult(res1);

    cout << "Permutations ([1,2,3]):" << endl;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res2 = permute(nums);
    printResult(res2);

    return 0;
}
