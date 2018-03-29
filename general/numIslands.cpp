/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

#include <unordered_map>
#include <vector>
#include <pair>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> g) {
        unordered_map<int, vector<pair<int, int>>> compMap;
        unordered_map<pair<int, int>, int> revCompMap;
        int comps = 0;

        for (int i = 0; i < g.size(); ++i) {
            for(int j = 0; j < g[0].size() && g[i][j] == '1'; ++j) {
                pair p = make_pair(i,j);
                if ((i-1 > 0 && g[i-1][j] == '1') &&
                    (j-1 > 0 && g[i][j-1] == '1') &&
                    (revCompMap[make_pair(i-1,j)] != revComp[make_pair(i,j-1)])
                    ) {
                    int dup_comp_num = revCompMap[make_pair(i,j-1)]
                } else if (i-1 > 0 && g[i-1][j] == '1') {
                    int comp_num = revCompMap[make_pair(i-1,j)];
                    revCompMap[p] = comp_num;
                    compMap[comp_num].push_back(p);
                } else if (j-1 > 0 && g[i][j-1] == '1') {
                    int comp_num = revCompMap[make_pair(i,j-1)];
                    revCompMap[p] = comp_num;
                    compMap[comp_num].push_back(p);
                } else {
                    ++comps;
                    compMap[comps].push_back(p);
                    revCompMap[p] = comps;
                }
            }
        }

    }

};
