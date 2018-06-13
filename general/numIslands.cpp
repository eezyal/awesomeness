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
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    inline int key(int i, int j) {
        return ((i << 16) | j);
    }
    int numComponents(unordered_map<int, vector<int>> g){
        //depth first search
        unordered_map<int, int> compMap;
        vector<int> v;
        int numComps = 0;
        stack<int> s;
        for (auto it : g)
            v.push_back(it.first);
        sort(v.begin(), v.end());
        for (auto curr: v) {
            if (compMap.find(curr) == compMap.end())
                numComps++;
            else
                continue;
            while(!s.empty() || curr >= 0) {
                if (curr >= 0) {
                    if (compMap.find(curr) == compMap.end()) {
                    // haven't visited it and haven't assigned a component to it.
                    // Do it now.
                        compMap[curr] = numComps;
                        for(auto num: g[curr]) {
                            if (compMap.find(num) == compMap.end())
                                s.push(num);
                        }
                    } else
                        curr = -1;
                } else {
                    curr = s.top();
                    s.pop();
                }
            }
        }
        return numComps;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
    // The main idea is to understand that there are as many
    // islands as there are connected components of 1's in the
    // matrix. Build a graph - find number of connected oomponents
        unordered_map<int, vector<int>> graph;
        int rows = grid.size();
        int cols = (rows > 0)?grid[0].size():0;
        int result = 0;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols ; ++j) {
                if (grid[i][j] == '1') {
                    vector<int> adjList;
                    graph[key(i,j)] = adjList;
                    if (j < cols-1 && grid[i][j+1] == '1')
                       graph[key(i,j)].push_back(key(i,j+1));
                    if (i < rows-1 && grid[i+1][j] == '1')
                       graph[key(i,j)].push_back(key(i+1,j));
                    if (j > 0 && grid[i][j-1] == '1')
                        graph[key(i,j)].push_back(key(i,j-1));
                    if (i > 0 && grid[i-1][j] == '1')
                       graph[key(i,j)].push_back(key(i-1,j));
                }
            }
        }
        result = (graph.size() > 0)?numComponents(graph):0;
        return result;
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> g = {
                            {'1','1','0','0','0'},
                            {'1','1','0','0','0'},
                            {'0','0','1','0','0'},
                            {'0','0','0','1','1'}
                            };
    int result = sol.numIslands(g);
    cout << "Number of islands in g is : " << result << endl;
    return 0;
}
