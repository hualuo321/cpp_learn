#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 题目: 小明一次可以移动 1 或 2 米, 请问移动 n 米有多少种走法?
 * 输入: n = 2
 * 输出: 2
 * 思路: 1. 找出数组含义定义: dp[i] 代表移动 i 米的走法数.
 * 思路: 2. 找出数组间的关系: dp[i] = dp[i-1]+dp[i-2].
 * 思路: 3. 找出初始条件: dp[0]=0, dp[1]=1, dp[2]=1.
*/

class Solution {
public:
    int numWays(int n) {
        vector<int> dp(max(2, n + 1));      // 1. 找出数组含义定义: dp[i] 代表移动 i 米的走法数.
        dp[0] = 1, dp[1] = 1;               // 3. 找出初始条件: dp[0]=1, dp[1]=1.
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;   // 2. 找出数组间的关系: dp[i] = dp[i-1]+dp[i-2].
        }
        return dp[n] ;
    }
};

int main() {
    int n;
    cout << "input num: ";
    cin >> n;
    Solution sol;
    cout << sol.numWays(n) << endl;
    return 0;
}