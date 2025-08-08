class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int MAX = -1, ans = 0;
        for (int num : nums){
            minHeap.push(num); // push all nums in minHeap
            MAX = max(num, MAX); // keep track of largest number
        }
        int last = 0, top;
        while (MAX > 0){ // while not all nums are 0;
            top = minHeap.top(); minHeap.pop(); // get top;
            if (top - last > 0) { // if number is greater than zero subract
                MAX -= max(0, top - last);
                ans++;
                last = top;
            }
        }
        return ans; // return ans
    }
};
class Solution {
public: // cheat, the number of minimumOperations is also the number of unique numbers in nums
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> uniquePositives;
        for (int num : nums) {
            if (num > 0) uniquePositives.insert(num);
        }
        return uniquePositives.size();
    }
};
