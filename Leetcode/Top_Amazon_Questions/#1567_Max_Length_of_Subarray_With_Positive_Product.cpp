class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // Length of subarray with negative product ending at current index
        int negLen = 0;
        // Length of subarray with positive product ending at current index
        int posLen = 0;
        // Maximum length of subarray with positive product found so far
        int ans = 0;

        // Iterate through each number in the array
        for (int num : nums){
            if(num == 0) {
                // Zero breaks the subarray, reset both lengths
                negLen = 0;
                posLen = 0;
            }
            else{
                if (num < 0) 
                    // Multiplying by a negative flips signs:
                    // swap positive and negative lengths
                    swap(posLen, negLen);

                // Update positive length:
                // - if there was already a positive subarray, extend it
                // - or start a new one if current number is positive
                if (posLen > 0 || num > 0) ++posLen; 

                // Update negative length:
                // - if there was already a negative subarray, extend it
                // - or start a new one if current number is negative
                if (negLen > 0 || num < 0) ++negLen;

                // Update the answer with the max positive subarray length
                ans = max(ans, posLen);
            }
        }

        return ans;
    }
};

