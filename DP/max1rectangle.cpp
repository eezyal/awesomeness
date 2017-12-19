/*
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 6.
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
private:
    int maxRectWithHeights(vector<int> &heights)
    {
        int size = heights.size();
        stack<int> s;
        int maxarea = 0, curr = 0, currarea = 0, top = 0;

        while (curr < size) {
            if (s.empty() || (heights[s.top()] <= heights[curr]))
                s.push(curr++);
            else {
                top = s.top();
                s.pop();
                currarea = heights[top] * (s.empty()?curr: curr - s.top() - 1 );
                maxarea = max(currarea, maxarea);
            }
        }
        while (!s.empty())
        {
            top = s.top();
            s.pop();
            currarea = heights[top] * (s.empty()?curr: curr-s.top()-1);
            maxarea = max(currarea, maxarea);
        }
        return maxarea;
    }

    void printvector(vector<int> &v)
    {
        int i = 0, size = v.size();
        cout << "[ ";
        for (i = 0; i < size - 1; ++i)
            cout << v[i] << ", ";
        cout << v[i] << "]";
    }
public:
    int maximalRectangle(vector<vector<char>> &m)
    {
    /*
     * Find max area with current row as the last row in the matrix.
     */
        vector<vector<int>> hm (m.size(), vector<int>(m[0].size(), 0));
        int max_area = 0;

        for (int i = 0; i < m.size(); ++i) {
            // 1. Calculate the height vector for this row - i
            for(int j = 0; j < m[i].size(); ++j) {
                if (m[i][j] == '1')
                    hm[i][j] = (i==0)?1:(hm[i-1][j]+1);
            }
            // 2. find max_area with row - i as base & update
            cout << "hm[" << i << "] : ";
            printvector(hm[i]);
            max_area = max (max_area, maxRectWithHeights(hm[i]));
            cout << "Max area of row " << i+1 << " : " << max_area << endl;
        }

        return max_area;
    }

};

int main()
{
    vector<vector<char>> m = {
                              {'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}
                            };
    Solution s;
    int max_area = s.maximalRectangle(m);
    cout << "max area " << max_area << endl;
}
