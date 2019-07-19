#include <iostream>

using namespace std;

class Solution {
    public:
        long long largestPrimeFactor(long long n) {
            int result;
            for (int i = 2; i*i < n; ++i) {
                if (n%i == 0) {
                    if (isPrime(n/i))
                            return (long long)n/i;
                    else if (isPrime(i))
                        result = i;
                }
            }
            return result;
        }
    private:
        bool isPrime(long long n) {

            if (n <= 1) return false;
            if (n <= 3) return true;

            if (n%2 == 0 || n%3 == 0)
                return false;

            for (int i = 5; i*i <= n; i+=6)
                if (n%i == 0 || n%(i+2) == 0)
                    return false;

            return true;
        }
};

int main() {
    Solution sol;
    long long n;
    cout << "Enter your number: ";
    cin >> n;
    long long factor = sol.largestPrimeFactor(n);
    cout << "The largest prime factor of " << n << " is " << factor << "."<< endl;
}
