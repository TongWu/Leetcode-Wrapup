/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        // In this version, we will make a visual header, inorder to prevent the one more condition to consider

        // Create a dummyhead
        ListNode* DummyHead = new ListNode(0);
        // Set the dummy head's next to the head
        DummyHead->next = head;

        // Regular way
        ListNode* ptr = DummyHead;
        while (ptr->next != NULL) {
            if (ptr->next->val /*The next element's value*/ == val) {
                // Create a pointer containing the next element
                ListNode* tmp = ptr->next;
                ptr->next = ptr->next->next;
                delete tmp;
            } else{
                // If the ptr's value is not target, move to the next
                ptr = ptr->next;
            }
        }    

        // Delete the dummyhead at last
        head = DummyHead->next;
        delete DummyHead;
        return head;    
    }
};
// @lc code=end

