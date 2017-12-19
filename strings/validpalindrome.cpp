// "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    bool validPalindromeInternal(string s, bool strict) {
        int left = 0, right = s.size() - 1;
        while (left < right){
            if (s[left] != s[right]) {
                if (strict)
                    return false; // second mismatch
                else {
                    strict = true; // only one mistake is allowed.
                    // make two strings and try the function
                    // for both of them. if one of them succeeds.
                    // we have an answer.
                    string s1 = s.substr(left, right-left); // exclude right
                    string s2 = s.substr(left+1, right-left); // exclude left;
                    return (validPalindromeInternal(s1, strict) || 
                                validPalindromeInternal(s2, strict));
                }
            }
            left++; right--;
        }
        return (left >= right);
    }

public:
    bool validPalindrome(string s) {
        return validPalindromeInternal(s, false);
    }

};

int main()
{
    string s;
    bool result;
    Solution sol;
    cout << "String : " ;
    cin >> s;
    result = sol.validPalindrome(s);
    cout << "Validpalindrome : " << result << endl;
}
