class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2->val : 0;

            int sum = a + b + carry;

            int digit = sum % 10;
            carry = sum / 10;

            ans->next = new ListNode(digit);
            ans = ans->next;

            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        }

        return dummy->next;
    }
};