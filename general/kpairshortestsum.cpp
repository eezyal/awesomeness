/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    void printvectorofpairs(vector<pair<int, int>> &vp) {
        cout << "BoundQ = ";
        for (auto p : vp)
            cout << "(" << p.first << ", " << p.second << ") " ;
        cout << endl;
        return;
    }
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, size1 = nums1.size(), t_i = -1;
        int j = 0, size2 = nums2.size(), t_j = -1;
        vector<pair<int, int>> result;
        pair<int, int> p;
        vector<pair<int, int>> boundQ;

        while (k > 0 && i < size1 && j < size2 ) {
            p = make_pair(nums1[i],nums2[j]);
            cout << "Inserted " << "[" << nums1[i] << ", " << nums2[j] << "]" << endl;
            printvectorofpairs(boundQ);
            result.push_back(p);
            k--;
            if (boundQ.size() > 0) {
                t_i = boundQ.back().first;
                t_j = boundQ.back().second;
            } else {
                t_i = -1; t_j = -1;
            }

            if ((i == size1-1) && (j == size2 -1))
                break;
            else if ((i == size1-1 || j == size2-1) && boundQ.size() > 0) {
                i = t_i;  j = t_j;
                cout << "2 : i = " << i << ", j = " << j << endl;
                boundQ.pop_back();
                continue;
            } else if (boundQ.size() == 0 && i == size1-1) {
                j++;
                cout << "3 : i = " << i << ", j = " << j << endl;
                continue;
            } else if (boundQ.size() == 0 && j == size2-1) {
                i++;
                cout << "4 : i = " << i << ", j = " << j << endl;
                continue;
            }

            if ( nums1[i+1] + nums2[j] <= nums1[i] + nums2[j+1]) {
                if (t_i >= 0) {
                    if (t_i == i+1 && t_j == j) {
                        p = make_pair(i, j+1); boundQ.insert(boundQ.begin(), p);
                        i++;
                        cout << "5 : i = " << i << ", j = " << j << endl;
                        boundQ.pop_back();
                    } else if((nums1[i+1] + nums2[j]) >= (nums1[t_i] + nums2[t_j])) {
                        p = make_pair(i, j+1); boundQ.insert(boundQ.begin(), p);
                        p = make_pair(i+1, j); boundQ.insert(boundQ.begin(), p);
                        i = t_i; j = t_j;
                        cout << "6 : i = " << i << ", j = " << j << endl;
                        boundQ.pop_back();
                    } else {
                        p = make_pair(i, j+1); boundQ.insert(boundQ.begin(), p);
                        i++;
                        cout << "7: i = " << i << ", j = " << j << endl;
                    }
                } else {
                    p = make_pair(i, j+1); boundQ.insert(boundQ.begin(), p);
                    i++;
                    cout << "8 : i = " << i << ", j = " << j << endl;
                }
            } else {
                if (t_i >= 0) {
                    if (t_i == i && t_j == j+1) {
                        p = make_pair(i+1, j); boundQ.push_back(p);
                        j++;
                        cout << "10 : i = " << i << ", j = " << j << endl;
                        boundQ.pop_back();
                    } else if ((nums1[i] + nums2[j+1]) >= (nums1[t_i] + nums2[t_j])) {
                        p = make_pair(i, j+1); boundQ.insert(boundQ.begin(), p);
                        p = make_pair(i+1, j); boundQ.insert(boundQ.begin(), p);
                        i = t_i; j = t_j;
                        cout << "11 : i = " << i << ", j = " << j << endl;
                        boundQ.pop_back();
                    } else {
                        p = make_pair(i+1, j); boundQ.insert(boundQ.begin(), p);
                        j++;
                        cout << "12 : i = " << i << ", j = " << j << endl;
                    }
                } else {
                    p = make_pair(i+1, j); boundQ.insert(boundQ.begin(), p);
                    j++;
                    cout << "13 : i = " << i << ", j = " << j << endl;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {-1, 1, 2};

    vector<pair<int, int>> result = sol.kSmallestPairs(nums1, nums2, 100);

    cout << "Result: " << endl;
    for (auto p : result){
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << endl;
}
