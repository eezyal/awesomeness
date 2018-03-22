/*
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
*/
#include <unordered_map>
#include <vector>

class Solution {
private:
    bool isSubSeq(string s, unordered_map<char, vector<int>>& indexMap) {
        int size = s.size();
        int curr = -1;

        for (int j = 0; j < size; j++) {
                if (indexMap.find(s[j]) == indexMap.end())
                        return false;
                vector<int> &v = indexMap[s[j]];
                auto it = upper_bound(v.begin(), v.end(), curr);
                if (it == v.end())
                        return false;
                curr = *it;
        }
        return true;
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        unordered_map<char, vector<int>> indexMap;
        // Build index map
        for (int i = 0; i < S.size(); i++)
                indexMap[S[i]].push_back(i);

        // get the counts
        for (auto _s: words)
                count+=(isSubSeq(_s, indexMap)?1:0);

        return count;
    }
};
