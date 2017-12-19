/*
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number. Now, we define a pair (c, d) can follow
 * another pair (a, b) if and only if b < c. Chain of pairs can be formed in
 * this fashion.
 *
 * Given a set of pairs, find the length longest chain which can be formed.
 * You needn't use up all the given pairs. You can select pairs in any order.
 *
 * Example 1:
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 *
 * */

// Compile this code with
// $> g++ -std=c++11 maxpairchain.cpp
// $> ./a.out

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    int maximum(int a, int b)
    {
        return (a > b)?a:b;
    }
    int compare(vector<int> p1, vector<int> p2)
    {
        if (p1[1] < p2[0])
            return 1;
        if (p2[1] < p1[0])
            return -1;
        return 0;
    }

    int computeLC(int index, vector<int>& LC, vector<vector<int>>& compTable)
    {
        LC[index] = 1;  // Mark with a 1 indicating compute-done for this index
        for (int i = 0; i < LC.size(); ++i) {
            if (compTable[index][i]) {
                if (LC[i] == -1) // Haven't computed LC for this i - yet.
                    LC[i] = computeLC(i, LC, compTable);
                LC[index] = maximum(LC[index], 1 + LC[i]);
            }
        }
        return LC[index];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> compTable(pairs.size(), vector<int>(pairs.size(),0));

        // Build '<' compTable
        for(int i = 0; i < pairs.size(); ++i)
            for (int j = i+1; j < pairs.size(); ++j) {
                int comp = compare(pairs[i], pairs[j]);
                if (comp == 1)
                    compTable[i][j] = 1;
                if (comp == -1)
                    compTable[j][i] = 1;
            }

        // Now we have a compare table.
        // Build 'longest chain starting at index' vector
        // LC(i) = max(LC(j)) for all j such that pairs[i] < pairs[j] + 1;
		// IOW,  LC(i)  = max(LC(j)) (for all j such that compTable[i][j] = 1) + 1
        vector<int> LC(pairs.size(), -1);
        int result = INT_MIN;

        for(int i = 0; i < pairs.size(); ++i)
            computeLC(i, LC, compTable);

        for (int i  = 0 ; i < pairs.size(); ++i)
            result = maximum(LC[i], result);

        return result;

    }
};

int main()
{
    vector<int> a = {-275,-20};
    vector<int> b = {750,402};
    vector<int> c = {35,618};
    vector<int> d = {232,525};
    vector<int> e = {769,939};
    vector<int> f = {571,809};
    vector<int> g = {-488,302};
    vector<int> h = {429,557};
    vector<int> i = {210,725};
    vector<int> j = {55,862};
    vector<int> k = {963,997};
    vector<int> l = {217,491};
    vector<int> m = {-336,94};
    vector<int> n = {-849,54};
    vector<int> o = {787,955};
    vector<int> p = {-972,-801};
    vector<int> q = {-555,692};
    vector<int> r = {-954,-57};
    vector<int> s = {-92,602};
    vector<int> t = {640,782};
    vector<int> u = {591,889};
    vector<vector<int>> pairs = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u};
    Solution sol;
    cout << "Longest chain length is " << sol.findLongestChain(pairs) << endl;

    return 0;
}

