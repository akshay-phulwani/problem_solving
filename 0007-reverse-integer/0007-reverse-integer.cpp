class Solution {
public:
    int reverse(int x) {
        long long a = 0;

        while (x != 0) {
            int b = x % 10;
            x /= 10;

            a = a * 10 + b;

            if (a > INT_MAX || a < INT_MIN)
                return 0;
        }

        return (int)a;
    }
};