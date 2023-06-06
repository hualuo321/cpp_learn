#include <iostream>
#include <vector>
using namespace std;

/**
 * 题目: 斐波那契函数
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        vector<int> dp(2, 0);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main() {
    Solution sol;
    cout << sol.fib(4) << endl;
}