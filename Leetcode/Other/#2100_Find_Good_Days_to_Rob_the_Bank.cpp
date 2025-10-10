class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int size = security.size();

        if (time == 0){
            vector<int> ans(size, 0);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }

        vector<int> dp(size, 0);
        vector<int> dpr(size, 0);
        vector<int> ans;

        int last = -1, guards;

        for(int i = 0; i < size; i++){
            guards = security[i];
            if(last >= guards){
                dp[i] = dp[i - 1] + 1;
            }
            last = guards;
        }
        
        last = -1;
        for(int i = size - 1; i >= 0; i--){
            guards = security[i];
            if(last >= guards){
                dpr[i] = dpr[i + 1] + 1;
                if (dpr[i] >= time && dp[i] >= time) ans.push_back(i);
            }
            last = guards;
        }

        return ans;
    }
};
