#include <iostream>

using namespace std;

class Solution {
    public:
        long long sumOfEvenFib() {
            int f1 = 1, f2 = 2, temp = 0;
            long long sum = 2;

            while (temp < 4000000) {
                temp = f2 + f1;
                if (temp % 2 == 0)
                    sum += temp;
                f1 = f2;
                f2 = temp;
            }
            return sum;
        }
};

int main() {
    Solution sol;
    long long sum = sol.sumOfEvenFib();
    cout << "The sum of all even fib nums < 4000000 is " << sum << endl;
}
