/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input:
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation:
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:
Input:
asteroids = [8, -8]
Output: []
Explanation:
The 8 and -8 collide exploding each other.

Example 3:
Input:
asteroids = [10, 2, -5]
Output: [10]
Explanation:
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.

Example 4:
Input:
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation:
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
Note:

The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size(), i = 0;
        bool collisions = false;

        if (size == 0 || size == 1)
            return asteroids;

        // check the array for collisions - if none return asteroids
        while (i < size - 1) {
            if (asteroids[i] > 0 && asteroids[i+1] < 0) {
                collisions = true;
                if ((asteroids[i+1] * -1 ) < asteroids[i]) {
                    asteroids.erase(asteroids.begin() + i+1);
                } else if ( (asteroids[i+1] * -1) > asteroids[i]) {
                    asteroids.erase(asteroids.begin() + i);
                } else {
                    asteroids.erase(asteroids.begin()+i);
                    asteroids.erase(asteroids.begin()+i);
                }
                size = asteroids.size();
            } else
                i++;
        }
        if (collisions)
            return asteroidCollision(asteroids);
        else
            return asteroids;
    }
    void printvector(vector<int> &a)
    {
        cout << "[";
        for (auto const i : a)
            cout << i << " ";
        cout << "]" << endl;
    }

};

int main()
{
    Solution sol;
    vector<int> asteroids = {8, -8, 10, 20, -24, 2, -4, 5, -4};

    sol.printvector(asteroids);
    asteroids = sol.asteroidCollision(asteroids);
    sol.printvector(asteroids);

}
