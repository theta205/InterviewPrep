class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) { 
            return ""; 
            // if either string is empty or not enought chars in s to find a valid window return ""
        }

        vector<int> m(128, 0); // to hold count of a char in t
        for (char c : t){ // populate count of chars in t
            m[c]++;
        }

        int right = 0, left = 0, minLen = INT_MAX, startAns = 0;
        int unseen = t.length();

        while(right < s.length()){
            if(m[s[right++]]-- > 0){ // increase right pointer and decrease the time the char was t
                unseen--;
            }
            while(unseen == 0) { //seen all of t;
                if (right - left < minLen){ //new minLen
                    startAns = left;
                    minLen = right - left;
                }
                if(m[s[left++]]++ == 0){ // increase left pointer and increase the time the char was t
                    unseen++; // add to unseen if we are moving passed a char that was in t
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startAns, minLen); 
        //if we found a valid min window substring return it (else "")
    }
};
