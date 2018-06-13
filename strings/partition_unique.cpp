/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:
S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/
#include <string>
#include <vector>
#include <pair>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> indMap;
        vector<int> sizes;
        vector<pair<int, int>> intervals;
        vector<pair<int, int>> work;

        for (int i = 0; i < s.size(); ++i) {
            if (indMap.find(s[i]) != indMap.end())
                indMap[s[i]].second = i;
            else
                indMap[s[i]] = make_pair(i, i);
        }

        for(auto kv: indMap)
            intervals.push_back(kv.second);

        sort(intervals.begin(), intervals.end(),
            [](const pair<int, int> a, const pair<int, int> b) -> bool
        {
            return (a.first < b.first);
        });

        work.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            pair<int, int> p_next = intervals[i];
            pair<int, int> p_curr = work.back();

            if (p_next.first  <  p_curr.second)
                work.back().second = max(p_next.second, p_curr.second);
            else
                work.push_back(p_next);
        }

        for (int i = 0 ; i < work.size(); ++i) {
            pair<int, int> p = work[i];
            sizes.push_back(p.second - p.first + 1);
        }

        return sizes;
    }
};

int main()
{
    Solution sol;
    vector<int> sizes =
}
