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
        int i = 0, size1 = nums1.size(), t_i = -1;
        int j = 0, size2 = nums2.size(), t_j = -1;
        vector<pair<int, int>> result;
        pair<int, int> p;
        vector<pair<int, int>> boundQ;
            
        while (k > 0 && i < size1 && j < size2 ) {
            result.push_back(make_pair(nums1[i],nums2[j])); 
            k--;
            if ((i == size1-1) && (j == size2 -1))
                i++; // break by incrementing i to size1.
            else if (i == size1-1 || j == size2-1 && boundQ.size() > 0) {
                i = boundQ[boundQ.size() - 1].first;
                j = boundQ[boundQ.size() - 1].second;
                boundQ.pop_back();
            } else if (boundQ.size() == 0 && i+1 == size-1) {
                j++; continue;
            } else if (boundQ.size() == 0 && j+1 == size-1) {
                i++; continue;
            } 
            if (boundQ.size() > 0) {
                t_i = boundQ[boundQ.size() - 1].first;
                t_j = boundQ[boundQ.size() - 1].second;
            }
        
            if ( nums1[i+1] + nums2[j] <= nums1[i] + nums2[j+1]) {
                if (t_i >= 0 && (nums1[i+1] + nums2[j]) > (nums1[t_i] + nums2[t_j])) {
                    boundQ.push_front(make_pair(i+1,j);
                    i = t_i; j = t_j;
                    boundQ.pop_back();
                    t_i = -1; t_j = -1;
                } else
                    i++;
            } else {
                if (t_i >= 0 && (nums1[i] + nums2[j+1]) > (nums1[t_i] + nums2[t_j])) {
                    boundQ.push_front(make_pair(i,j+1);
                    i = t_i; j = t_j;
                    boundQ.pop_back();
                    t_i = -1; t_j = -1;
                } else
                    j++;
            }
                
        }

        return result;
    }
};
