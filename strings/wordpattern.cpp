/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<string> split (string s, char delim)
    {
        vector<string> result;
        int size = s.size(); int curr = 0, prev=0;

        while (curr < size) {
            if (s[curr] == delim && prev < curr) {
                result.push_back(s.substr(prev, curr-prev));
                prev = curr+1;
            }
            ++curr;
        }
        if (prev < curr)
            result.push_back(s.substr(prev, curr-prev));

        return result;
    }

public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> pmap;
        unordered_map<string, char> smap;
        vector<string> tokens = split(str, ' ');
        int tsize = tokens.size();
        int psize = pattern.size();
        char c; string s;
        int index = 0;

        cout << "Tokens are : ";
        while (index < tsize)
            cout << tokens[index++] << " ";
        cout << endl;

        if (tsize != psize)
            return false;

        index = 0;

        while (index < tsize) {
            c = pattern[index]; s = tokens[index];
            if (pmap.find(c) == pmap.end()) {
                if (smap.find(s) == smap.end()) {
                    //new entry
                    smap[s] = c;
                    pmap[c] = s;
                }
                else
                    return false;
            } else if (pmap[c] != s)
                return false;
            ++index;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << "wordPattern match is - " << sol.wordPattern("aab", "very very nice") << endl;
}
