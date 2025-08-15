class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0, minAmt;
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1]; // sort ascending by second value (amt of units)
        });

        for (auto boxType : boxTypes){
            if (truckSize == 0) return ans;

            minAmt = min(truckSize, boxType[0]); // get min of boxes left and boxes available of type
            ans += boxType[1] * minAmt; // add units to answer
            truckSize -= minAmt; // reduce boxes amount

        }
        return ans;
    }
};
