#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> lkp; // last known position
        int i = 1, r, inCount;
        char zerochar = '0';
        // Ensure final solution till the index processed.
        // tasks[:0] is already a solution.
        if (n == 0)
            return tasks.size();
        lkp[tasks[0]] = 0;
        while (i < tasks.size()) {
            if (lkp.find(tasks[i]) != lkp.end()) {
                if (i - lkp[tasks[i]] - 1 < n ) {
                    r = i+1;
                    while (r < tasks.size()) {
                        if ((lkp.find(tasks[r]) != lkp.end()) &&
                            (i - lkp[tasks[r]] - 1 >= n)) {
                            cout << "tasks[" << i << "] : " << tasks[i] << "and tasks[" << r << "]: " << tasks[r] << endl;
                            swap(tasks[i], tasks[r]);
                            break;
                        } else if (lkp.find(tasks[r]) == lkp.end()) {
                            cout << "tasks[" << i << "] : " << tasks[i] << "and tasks[" << r << "]: " << tasks[r] << endl;
                            swap(tasks[i], tasks[r]);
                            break;
                        } else
                            r++;
                    }
                    if (r == tasks.size()) {
                        inCount = n - (i - lkp[tasks[i]] - 1);
                        cout << "Inserting " << inCount << "idles before tasks[" << i << "] : " << tasks[i] << endl;
                        tasks.insert(tasks.begin()+i, inCount, zerochar); // pad it up with idles
                        i+=inCount;
                    }       
                }
            }
            lkp[tasks[i]] = i;
            i++;
        }
        
        return tasks.size();
    }
};

int main()
{
    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks, 2);
}
