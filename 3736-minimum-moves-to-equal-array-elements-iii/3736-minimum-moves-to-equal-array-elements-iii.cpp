
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        for(int i : nums) {
            maxi = max(maxi, i);
        }

        int ans = 0;
        for(int i : nums) {
            ans += maxi - i;
        }

        return ans;
    }
};
