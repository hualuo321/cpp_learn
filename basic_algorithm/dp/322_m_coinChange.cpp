#include <iostream>
#include <vector>
using namespace std;

/**
 * 题目: 给出一组数，看能不能凑成 target，求可以凑成的最少数量。
 * 思路: 1. 给出 dp 的定义，dp[i] 代表目标金额为 i 时，需要 dp[i] 块硬币凑出。
 * 思路: 2. 找出 dp[i] 与前者的关系, 在本题中, dp[i] = min(dp[i], (min(dp[i-1], dp[i-2], dp[i-5])+1))
 * 思路: 3. 找出初始值 dp[0] = 0
*/

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;                                          // 找出初始值 dp[0] = 0
        for (int i = 1; i < dp.size(); ++i) {               // 求取每一个 dp[i]
            for (int coin : coins) {                        // 依次获取 dp[i-1], dp[i-2], dp[i-5], 并求 min(...) + 1
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        if (dp[amount] == amount + 1) return -1;
        else return dp[amount];
    }
};

// dp[11] = min(dp[10], dp[9], dp[6]) + 1
// dp[6] = min(dp[5], dp[4], dp[1]) + 1
// dp[1] = min(dp[0]) + 1
// dp[11] = 3

int main() {
    Solution sol;
    vector<int> coins = {1};
    cout << sol.coinChange(coins, 0) << endl;
    return 0;
}