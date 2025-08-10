class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans; // output vector

        //parsing variables
        pair<string,int> p;
        int idx;
        string temp;

        stack<pair<string,int>> st; st.push({s, 0}); // stack and push string in with 0 index
        while(!st.empty()){ 
            p = st.top(); st.pop(); //get top and pop it

            for (string str : wordDict){ // for every string in wordDict
                temp = p.first; // str
                idx = p.second; // index
                if(str == temp.substr(idx, str.length())){ // if the start of string is a word
                   // if end of string push to answer
                    if (idx + str.length() == temp.length()) ans.push_back(temp); 
                    else { // otherwise push new pair to stack
                        temp.insert(idx + str.length(), " "); // insert space in
                        idx += 1 + str.length(); // update index
                        st.push({temp, idx});
                    }
                }
            }
        }
        return ans; // return answer
    }
};
