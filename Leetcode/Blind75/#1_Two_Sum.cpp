class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; 
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i]; 
            if (m.find(target - num) != m.end()) { // if the current numbers twin exists return
                return {i, m[target - num]}; 
            }
            else m[num] = i;
        }
        return {}; // no pair
    }
};[Cclass Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; 
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i]; 
            if (m.find(target - num) != m.end()) { // if the current numbers twin exists return
                return {i, m[target - num]}; 
            }
            else m[num] = i;
        }
        return {}; // no pair
    }
};
