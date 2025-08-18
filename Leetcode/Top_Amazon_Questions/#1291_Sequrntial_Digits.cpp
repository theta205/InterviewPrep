class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int l = log10(low) + 1; int h = log10(high) + 1; // get digits count of highest and lowest number
        
        int digit = 1; 
        string number; // used to add digits
        int num; // number as int
        vector<int> ans; //answer

        for (int i = l; i <= h; i++){ // loop within the digit count
            digit = 1; // start at 1
            while (digit + i <= 10){ // keep adding nums while a sequtional one fits.
                for (int x = digit; x < digit + i; x++){ // get the number
                    number += ('0' + x);
                }
                num = stoi(number); // convert to int
                if (num <= high && num >= low) // only add if within high low
                    ans.push_back(num); // add to answer

                digit++; // increase starting number
                number = ""; //clear number
            } 
        }
        return ans; 

    }
};
