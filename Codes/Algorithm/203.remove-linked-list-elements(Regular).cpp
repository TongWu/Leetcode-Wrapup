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
        // In this version, we will not create a visual head to process the list. So in this case, we will face two condition for deleting the element in the list

        /* Condition 1: If the head need to be deleted: */
        // Determine that head is not NULL and head's val is target
        while (head != NULL && head->val == val) {
            // Create a temp pointer pointing to the head
            ListNode* tmp = head;
            // Change head to the next element
            head = head->next;
            // Delete head (tmp)
            delete tmp;
        }

        /*Condition 2: The non-head element need to be deleted*/
        // Determine a pointer pointing to the header
        ListNode* ptr = head;
        while (ptr != NULL && ptr->next != NULL) {
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

        return head;
    }
};
// @lc code=end

