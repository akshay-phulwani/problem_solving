class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;
        int ct1 = 0;
        int ct2 = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') {
                    ct1++;
                } else {
                    leftSum += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    ct2++;
                } else {
                    rightSum += num[i] - '0';
                }
            }
        }

        if ((ct1 + ct2) % 2 != 0) {
            return true;
        }

        return leftSum - rightSum != (ct2 - ct1) * 9 / 2;
    }
};