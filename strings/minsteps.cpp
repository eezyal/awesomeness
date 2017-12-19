#include <string>
#include <iostream>

using namespace std;

int minSteps(int n, string B){
    // Complete this function
    string pattern1 = "01010";
    string pattern2 = "010";
    int steps = 0;
    size_t pos = 0, pos2 = 0;
    while (pos + 5 < n) {
        pos2 = B.find(pattern1, pos);
        if (pos2 == string::npos)
            break;
        cout << "pos2 : " << pos << endl;
        B[pos2+2] = '1'; steps++;
        cout << "After step" << steps << ", B looks like : " << B << endl;
        pos = pos2+4;
    }
    pos = 0;
    while (pos + 3 < n) {
        pos2 = B.find(pattern2, pos);
        if (pos2 == string::npos)
            break;
        cout << "pos2 : " << pos << endl;
        B[pos2+1] = '0'; steps++;
        cout << "After step" << steps << ", B looks like : " << B << endl;
        pos = pos2+2;
    }
    return steps;
}

int main() {
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}

