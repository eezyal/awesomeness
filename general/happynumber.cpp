/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> seen;
public:
    bool isHappy(int n) {
        int sum = 0, temp = n;
        if (n == 1)
            return true;

        if (seen.find(n) != seen.end())
            return false;

        seen[n] = true;
        while(temp > 0) {
            int curr = temp%10;
            sum += (curr * curr);
            temp /= 10;
        }
        return isHappy(sum);
    }
};

int main()
{
    Solution sol;
    int num  =  83;
    cout << "isHappy(" << num << ") is " << sol.isHappy(num) << endl;
}

