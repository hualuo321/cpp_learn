#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/**
 * 1. dp[i][j]: 下落到 i j 处的最小路径和
 * 2. dp[i][j] = min(dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1]) + matrix[i][j]
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &metrics) {
        int row = metrics.size(), col = metrics[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        for (int i = 0; i < col; ++i) {
            dp[0][i] = metrics[0][i];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j == 0) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + metrics[i][j];
                } else if (j == col - 1) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + metrics[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1])) + metrics[i][j];
                }
            }
        }
        return *min_element(dp[row-1].begin(), dp[row-1].end());
    }

    int minFallingPathSum_2(vector<vector<int>> &metrics) {
        int row = metrics.size(), col = metrics[0].size();
        vector<int> dp(col + 2);
        dp[0] = INT_MAX, dp[col + 1] = INT_MAX;
        for (int i = 1; i <= col; ++i) dp[i] = metrics[0][i - 1];
        for (int i = 1; i < row; ++i) {     // 行
            int last = INT_MAX, cur, next;
            for (int j = 1; j < col + 1; ++j) {
                cur = dp[j];
                next = dp[j + 1]; cout << next << "  " << endl;
                dp[j] = min(cur, min(last, next)) + metrics[i][j - 1];
                last = cur;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> metrics = {{-19, 57},{-40, 5}};
    cout << sol.minFallingPathSum_2(metrics) << endl;
    return 0;
}