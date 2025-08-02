class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right){ //move forward until the ends meet
            if(!isalnum(s[left])) {  //if not alnum move on
                left++;
                continue;
            }
            if(!isalnum(s[right])) {  //if not alnum move on
                right--;
                continue;
            }
            if ( tolower(s[left]) != tolower(s[right]) ){//if not equal not palindrome
                return false;
            }
            else{
                right--; // if good here move on
                left++;
            }
        }
        return true;
    }
};
