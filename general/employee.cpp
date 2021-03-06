/*
You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
Note:
One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Employee {
public:
    int id;
    int imp;
    vector<int> subs;
};

class Solution {
private:
    int getImpWithMap(unordered_map<int, Employee*> emap, int id)
    {
        int result = emap[id]->imp;
        for (const auto i : emap[id]->subs)
            result += getImpWithMap(emap, i);
        return result;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        unordered_map<int, Employee *> emap;

        for (const auto i : employees )
            emap[i->id] = i;

        result = getImpWithMap(emap, id);
        return result;
    }
};

int main()
{
    Solution sol;
    Employee emp1 = {1, 2, {2}};
    Employee emp2 = {2, 3, {}};
    vector<Employee *> emps = {&emp1, &emp2};

    cout << "Employee imp of 1 is : " << sol.getImportance(emps, 1) << endl;
}
