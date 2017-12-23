/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *n = NULL, *nn = NULL, *ansNode = NULL;

        ansNode = (head && head->next)?head->next:head;

        while (curr && curr->next) {
            nn = curr->next->next;
            n = curr->next;
            if(prev) prev->next = n;
            curr->next = nn;
            n->next = curr;
            prev = curr;
            curr = nn;
        }
        return ansNode;
    }
    void printList (ListNode *head)
    {
        ListNode *r = head;
        cout << "[";
        while (r != NULL) {
            cout << r->val << " " ;
            r = r->next;
        }
        cout << "]" << endl;
    }
};

int main()
{
    Solution sol;
    ListNode one(1);ListNode two(2);ListNode three(3);ListNode four(4);
    one.next = &two; two.next = &three; three.next = &four;

    sol.printList(&one);
    sol.printList(sol.swapPairs(&one));
}
