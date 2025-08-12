class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string ans;
        int section = num % 1000; num /= 1000;
        int sectionCount = 1;

        while (section != 0 || num != 0){
            if (section != 0) {
                ans.insert(0, denomination(sectionCount));
                if(section > 99) ans.insert(0, threeDigit(section));
                else ans.insert(0, twoDigit(section));
                if (num != 0)  ans.insert(0, " ");
            }

            section = num % 1000; num /= 1000;
            sectionCount++;
        }
        return ans;
    }
    string oneDigit(int num){
        switch (num){
            case 0:
                return "Zero";
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
        }
        return "";
    }
    string twoDigit(int num){
        if (num < 10) return oneDigit(num);
        if (num < 20){
            switch (num){
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
            }
        }
        else{
            string output, ones = "";
            if (num % 10 != 0) ones = " " + oneDigit(num % 10);
            switch (num / 10){
                case 2: 
                    output = "Twenty" + ones;
                    return output;
                case 3: 
                    output = "Thirty" + ones;
                    return output;
                case 4: 
                    output = "Forty" + ones;
                    return output;
                case 5: 
                    output = "Fifty" + ones;
                    return output;
                case 6: 
                    output = "Sixty" + ones;
                    return output;
                case 7: 
                    output = "Seventy" + ones;
                    return output;
                case 8: 
                    output = "Eighty" + ones;
                    return output;
                case 9: 
                    output = "Ninety" + ones;
                    return output;
            }
        }
        return "";
    }
    string threeDigit(int num){
        string output = oneDigit(num / 100) + " Hundred";
        if (num % 100 != 0) return output + " " + twoDigit(num % 100);
        else return output;
    }
    string denomination(int sectionCount){
        switch (sectionCount){
            case 2:
                return " Thousand";
            case 3:
                return " Million";
            case 4:
                return " Billion";
        }
        return "";
    }
};
