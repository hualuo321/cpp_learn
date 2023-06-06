#include <iostream>
#include <vector>
using namespace std;

/**
 * 题目: 在坐标系中，小明从 (0,0) 移动到 (m,n), 一次只能正向移动 1 米, 请问到达终点一共有多少种走法?
 * 输入: m = 3, n = 7
 * 输出: 28
 * 思路: 1. 定义数组元素的含义, dp[i][j] 为终点为 (i,j) 可以的走法.
 * 思路: 2. 找出数组元素之间的关系, dp[i][j] = dp[i-1][j] + dp[i][j-1].
 * 思路: 3. 找出初始值, dp[0~m][0] = 1, dp[0][0~n] = 1.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));          // 1. 定义数组元素的含义, dp[i][j] 为终点为 (i,j) 可以的走法.
        for (int i = 0; i < m; ++i) dp[i][0] = 1;           // 3. 找出初始值, dp[0~m][0] = 1, dp[0][0~n] = 1.
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];     // 2. 找出数组元素之间的关系, dp[i][j] = dp[i-1][j] + dp[i][j-1].
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    cout << "imput m and n: ";
    int m, n;
    cin >> m >> n;
    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
}