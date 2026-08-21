class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int a = mat.size();
        int b = mat[0].size();

        vector<vector<int>> ans(a, vector<int>(b));
        vector<vector<int>> prefix(a + 1, vector<int>(b + 1, 0));

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                int top = max(0, i - k);
                int bottom = min(a - 1, i + k);
                int left = max(0, j - k);
                int right = min(b - 1, j + k);

                ans[i][j] = prefix[bottom + 1][right + 1]
                          - prefix[top][right + 1]
                          - prefix[bottom + 1][left]
                          + prefix[top][left];
            }
        }

        return ans;
    }
};