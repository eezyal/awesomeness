/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size(), i = size - 1, total = 0, pow = 1;
        while (i >= 0) {
            total += ((s[i--] - 'A' + 1) * pow);
            pow *= 26;
        }
        return total;
    }
};

int main()
{
    Solution sol;
    cout << "ABC - " << sol.titleToNumber("ABC") << " and AB - " << sol.titleToNumber("AB") << endl;
}
