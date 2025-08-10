class Solution {
public:
    string reorganizeString(string s) {
        vector<int> m(26,0); //store count of chars
        string ans; // output string

        for (char c : s) m[c - 'a']++; // get count of each char

        int idx = findMost(m), idx2 = findMost(m, idx); // get most and second most common chatrs
        char c;

        while (idx2 != -1){
            ans += char(idx + 'a'), ans += char(idx2 + 'a'); // push chars
            m[idx]--; m[idx2]--; // reduce count
            idx = findMost(m);
            idx2 = findMost(m, idx); // get most and second most common chars
        }
        if (idx != -1) ans += char(idx + 'a'); // if still a char left push
        
        if (ans.length() == s.length()) return ans; // if all chars used return ans
        else return ""; // if not return nothing
    }

    int findMost(vector<int> &m, int index = -1){ //gets most common char and ignores a optional idx/
        int ans = -1, max = 0, idx = 0;

        for (int count : m){
            if (count > max && idx != index){
                ans = idx;
                max = count;
            }
            idx++;
        }
        return ans;
    }
};
