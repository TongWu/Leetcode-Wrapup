# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        # Calculate the length of two linked list
        lenA, lenB = 0, 0
        cur = headA
        while cur:
            cur = cur.next
            lenA += 1
        cur = headB
        while cur:
            cur = cur.next
            lenB += 1

        # Aligned the linked list to the shortest one
        curA, curB = headA, headB
        while lenA != lenB:
            if lenA > lenB:
                curA = curA.next
                lenA -= 1
            elif lenB > lenA:
                curB = curB.next
                lenB -= 1

        # Step in for both linked list, find the interesction
        while not curA or curB:
            if curA == curB:
                return curA
            curA = curA.next
            curB = curB.next

        # If no intersection, return None
        return None