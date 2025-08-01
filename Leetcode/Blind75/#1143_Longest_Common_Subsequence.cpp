class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0); // tracks LCS for each index of text1;
        int longest = 0; 

        for (char c : text2) {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curLength < dp[i]) { // if we alr found a longer LCS update
                    curLength = dp[i];
                } else if (c == text1[i]) { // add to LCS as we find more common chars
                    dp[i] = curLength + 1;
                    longest = max(longest, curLength + 1);
                }
            }
        }

        return longest;        
    }
};
