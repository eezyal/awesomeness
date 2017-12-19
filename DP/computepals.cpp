#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void computePal(vector<vector<int>> &pal, string s, int i, int j)
    {
        if(pal[i][j] != -1)
            return;
        if (i == j) {
            pal[i][j] = 1;
            return;
        }
        if (i == j-1)
            pal[i][j] = ((s[i] == s[j])?1:0);

        computePal(pal, s, i+1, j);
        computePal(pal, s, i, j-1);

        if (i != j-1)
            pal[i][j] = ((pal[i+1][j-1] == 1) && s[i] == s[j])? 1: 0;

    }
public:
    int countSubstrings(string s) {
        int size = s.size();
        int cnt = 0;

        // if we are doing each substring it's exponential time.
        // we need to be more clever than that.
        // define pal[i][j] that says if s(i,j) is a palindrome
        // or not.
        // pal[i][j] = 1 if pal[i+1][j-1] is 1 && s[i] == s[j]
        // pal[i][i] = 1 for any i.
        // This is n^2 solution
        // Manacher's algorithm is O(N) - that's part of 'strings'
        // module in the code base.
        vector<vector<int>> pal(size, vector<int>(size, -1));

        computePal(pal,s,0,size-1);

        // count all 1s in the upper half
        for (int i = 0; i < size; ++i)
            for(int j = i; j < size; ++j)
                cnt += pal[i][j];

        return cnt;
    }
};


int main()
{
    Solution s;
    cout << "substring palindromes count in 'aaa' is : " <<  s.countSubstrings("aaa") << endl;
}
