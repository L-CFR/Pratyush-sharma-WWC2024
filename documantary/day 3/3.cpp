/*Q2 . Elimination Game
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
 Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }

        return dp[0][n-1] >= 0;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 2};
    cout << (solution.PredictTheWinner(nums) ? "Player 1 can win" : "Player 1 cannot win") << endl;

    return 0;
}
