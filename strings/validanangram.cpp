/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int counts[26] = { 0 };
        // count up
        for (auto const c : s)
            counts[c-'a']++;
        // count down
        for (auto const c : t)
            counts[c-'a']--;
        // check for non-zero.
        for (auto const i : counts)
            if (i != 0)
                return false;

        return true;
    }
};

int main()
{
    Solution sol;
    cout << "isAnagram(\"super\",\"purse\") is " << sol.isAnagram("super","purse") << endl;
}
