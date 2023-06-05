#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 题目: 给定一个网格, 选出一条路径, 使得 (0,0)->(m,n) 之和最小.
 * 输入: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出: 7
 * 思路: 1. 定义数组元素的含义，比如 dp[i][j] 代表走到 (i,j) 的最小路径.
 * 思路: 2. 找出数组元素之间的关系，比如 dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
 * 思路: 3. 找出初始值, dp[0~m][0]=sum(...), dp[0][0~n]=sum(...)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));                   // 1. 定义数组元素的含义，比如 dp[i][j] 代表走到 (i,j) 的最小路径.
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) dp[i][0] = dp[i-1][0] + grid[i][0]; // 3. 找出初始值, dp[0~m][0]=sum(...), dp[0][0~n]=sum(...)
        for (int j = 1; j < n; ++j) dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];    // 2. 找出数组元素之间的关系，比如 dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << sol.minPathSum(nums) << endl;
}
