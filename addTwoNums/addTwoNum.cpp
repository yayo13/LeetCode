class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int up_bit = 0, val = 0;
		ListNode* root = new ListNode(0);
		ListNode* flag = root;

		while(l1 || l2 || up_bit){
			int v1, v2;
			v1 = v2 = 0;
			if(l1){
				v1 = l1->val;
				l1 = l1->next;
			}
			if(l2){
				v2 = l2->val;
				l2 = l2->next;
			}
			val = v1 + v2 + up_bit;
			if(val / 10){
				up_bit = 1;
				val %= 10;
			}
			else
				up_bit = 0;

			flag->next = new ListNode(val);
			flag = flag->next;
		}
		return root->next;

	}
};
