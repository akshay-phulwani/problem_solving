class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode *a = head;
        ListNode *b = head->next;
        ListNode *c = head->next->next;

        int pos = 2;
        int first = -1, last = -1;
        int mn = INT_MAX;

        while (c) {
            if ((b->val > a->val && b->val > c->val) ||
                (b->val < a->val && b->val < c->val)) {

                if (first == -1)
                    first = pos;
                else
                    mn = min(mn, pos - last);

                last = pos;
            }

            a = b;
            b = c;
            c = c->next;
            pos++;
        }

        if (first == last)
            return {-1, -1};

        return {mn, last - first};
    }
};