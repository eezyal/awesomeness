/*
 * Given two strings S and T, determine if they are both one edit distance apart.
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int s_i = 0, t_i = 0;
        int mismatch = 0;

        while (s_i < s.size() && t_i < t.size()) {
            if (s[s_i] == t[t_i]) {
                s_i++; t_i++;
            } else {
                if (s.size() == (t.size() + 1) )
                    s_i++;
                else if ((s.size() + 1) == t.size())
                    t_i++;
                else {
                    s_i++; t_i++;
                }
                mismatch++;
                if (mismatch == 2)
                    break;
            }
        }
        if (mismatch == 0)
            return ((s_i + t_i)  == (s.size() + t.size() - 1));
        return (mismatch == 1);

    }
};

int main()
{
    Solution sol;
    cout << ((sol.isOneEditDistance("a","ac"))?"True":"False") << endl;

}
