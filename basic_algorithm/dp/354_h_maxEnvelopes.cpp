#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 该方法超时.
/**
 * Q: 俄罗斯信封问题
 * A: 相当于把宽从小到大排序, 高从大到小排序, 再对高进行 LIS.
*/

class Solution {
public:
    int maxEnvelopes_1(vector<vector<int>> &envelopes) {
        int len = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    dp[i]= max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

int main() {
    Solution sol;
    vector<vector<int>> envelope = {{5,3},{6,2},{6,4},{2,8}};  // [2,8] [5,3] [6,4] [6,2]
    cout << sol.maxEnvelopes(envelope) << endl;
    return 0;
}