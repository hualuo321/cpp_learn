#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 题目: 给定两个单词 word1, word2 用最少的步骤实现转换, 可以插入, 删除, 替换字符.
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 思路: 1. 定义数组元素的含义, dp[i][j] 代表两单词长度为 i 和 j 时需要的最小步数.
 * 思路: 2. 找出数组元素之间的关系
 *          - word1[i]=word2[j], 则 dp[i][j] = dp[i-1][j-1]
 *          - word1[i]!=word2[j], 则 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
 *              - 替换 dp[i][j] = dp[i-1][j-1] + 1
 *              - 添加 dp[i][j] = dp[i-1][j] + 1
 *              - 删除 dp[i][j] = dp[i][j-1] + 1
 * 思路: 3. 找出初始值, dp[0][j]=dp[0][j-1] + 1, dp[i][0] = dp[i-1][0] + 1
 * */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));         // 1. 定义数组元素的含义, dp[i][j] 代表两单词长度为 i 和 j 时需要的最小步数.
        for (int i = 1; i <= len1; ++i) dp[i][0] = dp[i - 1][0] + 1;        // 3. 找出初始值, dp[0][j]=dp[0][j-1] + 1, dp[i][0] = dp[i-1][0] + 1
        for (int j = 1; j <= len2; ++j) dp[0][j] = dp[0][j - 1] + 1;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];      // 2. 找出数组元素之间的关系
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                cout << dp[i][j] << "  ";
            }
            cout <<endl;
        }
        return dp[len1][len2];
    }
};

int main() {
    Solution sol;
    cout << sol.minDistance("horse", "ros") << endl;
}