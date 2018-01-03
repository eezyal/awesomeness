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
#include <pair>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, size1 = nums1.size(), t_i = 0;
        int j = 0, size2 = nums2.size(), t_j = 0;
        vector<pair<int, int>> result;
        int limit = 0;
        pair<int, int> p(nums1[i], nums2[j]);

        while (i < size1 && j < size2 && k > 0) {
            swap(t_i, i); swap(t_j,j);
            p = {nums1[i], nums2[j]};
            result.push_back(p);

            if (i+1 < size1 && j+1 < size2) {
                if ((nums1[i+1] + nums2[j]) < (nums1[i] + nums2[j+1]) {
                    t_i = i;
                    t_j = j+1;
                    limit = nums1[i] + nums2[j+1];
                    while (++i < size1 && nums1[i] + nums2[j] < limit && k > 0) {
                        p = {nums1[i], nums2[j]};
                        result.push_back(p);
                        k--;
                    }
                } else {
                    t_i = i+1;
                    t_j = j;
                    limit = nums1[i+1] + nums2[j];
                    while (++j < size2 && nums1[i] + nums2[j] < limit && k > 0) {
                        p = {nums1[i], nums2[j]};
                        result.push_back(p);
                        k--;
                    }
                }
            } else
                break;  // deal with last few outside this loop
        }
        if (i == size1-1) {
            while (k > 0 && j < size2) {
                p = {nums1[i], nums2[j];
                result.push_back(p);
                k--;
            }
        } else if (j == size2-1) {
            while (k > 0 && j < size2) {
                p = {nums1[i], nums2[j];
                result.push_back(p);
                k--;
            }
        }

        return result;

    }
};
