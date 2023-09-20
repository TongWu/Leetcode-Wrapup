/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* ptr1 = head;
        ListNode* ptr2 = nullptr;
        while(ptr1) {
            temp = ptr1->next;
            ptr1->next = ptr2;
            ptr2 = ptr1;
            ptr1 = temp;
        }
        return ptr2;
    }
};
// @lc code=end

