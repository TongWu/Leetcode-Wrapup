/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {  
      // Virtual head
      ListNode* dummyNode = new ListNode;
      dummyNode->next = head;
      // Dual pointer, fast one move n+1 steps (nth element)
      ListNode* fast = dummyNode;
      // Slow pointer move n steps (n-1th element)
      ListNode* slow = dummyNode;

      // fast pointer first move n+1 steps
      while(n-- && fast!=NULL) {
        fast = fast->next;
      }
      fast = fast->next;

      // Then fast and slow pointer move steps until fast pointer touches end
      while(fast != NULL) {
        fast = fast->next;
        slow = slow->next;
      }
      // remove the target element
      slow->next = slow->next->next;

      return dummyNode->next;
    }
};
// @lc code=end

