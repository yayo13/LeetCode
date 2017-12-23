# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers_v1(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        temp1 = l1
        temp2 = l2
        result = []
        
        up_bit = 0
        while True:
            value = temp1.val + temp2.val + up_bit
            if value / 10 != 0:
                up_bit = 1
                value %= 10
            else:
                up_bit = 0
                
            result.append(ListNode(value))
            temp1 = temp1.next
            temp2 = temp2.next
            
            if temp1 == None and temp2 == None:
                if up_bit == 1:
                    result.append(ListNode(1))
                break
            if temp1 == None:
                temp1 = ListNode(0)
            if temp2 == None:
                temp2 = ListNode(0)
        
        node_result = ListNode(result[0].val)
        if len(result) > 1:
            node_result.next = result[1]
            for index in range(len(result)-2):
                result[index+1].next = result[index+2]
        return node_result
                
    def addTwoNumbers_v2(self, l1, l2):
        carry = 0
        root = n = ListNode(0)
        while l1 or l2 or carry:
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(v1+v2+carry, 10)
            n.next = ListNode(val)
            n = n.next
        return root.next