class Solution {
public:
    int getSum(int a, int b) {
        // get signs of each
        char a_sign = '+';
        char b_sign = '+';

        if (a < 0) {
            a = 0 - a;
            a_sign = '-';
        }
        if (b < 0) {
            b = 0 - b;
            b_sign = '-';
        }

        // convert to binary strings
        string A = decToBinary(a);
        string B = decToBinary(b);

        // make A larger than B or equal
        if (A.length() < B.length()) {
            A.swap(B);
            char temp = a_sign;
            a_sign = b_sign;
            b_sign = temp;
        }
        
        // make same length
        string zeros(A.length() - B.length(), '0');
        B = zeros + B;

        int digit = 1;
        a = 0; b = 0;
        // get unsigned decimal of each
        for (int i = A.length() - 1; i >= 0; i--){
            if (B[i] == '1')
                b += digit;
            if (A[i] == '1') {
                a += digit;
            }
            digit = digit * 2;
        } 

        // add sign back
        if (a_sign == '-') a = 0 - a;
        if (b_sign == '-') b = 0 - b;

        return a + b;
    }
    string decToBinary(int n) {
    
        string bin = "";
        while (n > 0) {
            int bit = n%2;
            bin.push_back('0' + bit);
            n /= 2;
        }
        
        reverse(bin.begin(), bin.end());
        return bin;
    }
};
