class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;

        for (char a : s) {
            if (!s1.empty() && s1.top() == a) {
                s1.pop();
            } else {
                s1.push(a);
            }
        }

        string b = "";
        while (!s1.empty()) {
            b += s1.top();
            s1.pop();
        }

        reverse(b.begin(), b.end());
        return b;
    }
};