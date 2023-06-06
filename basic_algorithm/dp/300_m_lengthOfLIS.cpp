#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Q: 给定一个数组, 求最大递增子序列.
 * A: 动态规划
 *      1. 给出 dp 的定义, dp[i] 代表长度为 i 时, 最大子序列为长度 dp[i].
 *      2. 找出其中的关系: 比如 [1, 3, 5, 4]  则 dp[3] = max(dp[1], dp[2]) + 1
 *          for 循环比较
 *      3. 初始值: 获取 dp 里面最大的那个数
*/

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        vector<int> dp(len, 1);
        dp[0] = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(nums) << endl;
}