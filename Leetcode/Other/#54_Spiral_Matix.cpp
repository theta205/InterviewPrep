class Solution {
public:

    pair<int,int> rowRange; // stores range of unadded indexs
    pair<int,int> colRange;
    vector<int> ans;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // set ranges
        rowRange = {0, matrix.size() - 1};
        colRange = {0, matrix[0].size() - 1};

        int times = 0; // tracks number of "sides added"

        while(addToSpiral(times, matrix)) times++; // while more to add
        return ans;
    } 

    bool addToSpiral(int &times,vector<vector<int>>& matrix){
        // four if statements for each side 
        if(times % 4 == 0){ 
            for (int j = colRange.first; j <= colRange.second; j++){ // for the length of each side add elements
                ans.push_back(matrix[rowRange.first][j]);
            }
            rowRange.first++; // update range
        }
        else if (times % 4 == 1){
            for (int i = rowRange.first; i <= rowRange.second; i++){
                ans.push_back(matrix[i][colRange.second]);
            }
            colRange.second--;
        }
        else if (times % 4 == 2){
            for (int j = colRange.second; j >= colRange.first; j--){
                ans.push_back(matrix[rowRange.second][j]);
            }

            rowRange.second--;
        }
        else{
            for (int i = rowRange.second; i >= rowRange.first; i--){
                ans.push_back(matrix[i][colRange.first]);
            }
            colRange.first++;
        }
        if (rowRange.first > rowRange.second || colRange.first > colRange.second) return false; // if no col or rows left then done
        else return true;
    }       
};
