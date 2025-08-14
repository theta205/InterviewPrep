#include <string>
using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        // dp[0] = "0", dp[1] = "1", dp[2] = "01", dp[3] = "10", dp[4] = "010", dp[5] = "101"
        long long dp[6] = {0};

        for (char c : s) {
            if (c == '0') { //extend instances ending in zero
                dp[0] += 1;      // "0"
                dp[3] += dp[1];  // "10"
                dp[4] += dp[2];  // "010"
            } else { // '1' //extend instances ending in one
                dp[1] += 1;      // "1"
                dp[2] += dp[0];  // "01"
                dp[5] += dp[3];  // "101"
            }
        }

        return dp[4] + dp[5]; // "010" + "101" 
    }
};

