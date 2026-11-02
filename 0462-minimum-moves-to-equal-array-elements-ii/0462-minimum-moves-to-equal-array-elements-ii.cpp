class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int md = nums[nums.size() / 2];
        int a = 0;

        for(int i : nums) {
            a += abs(i - md);
        }

        return a;
    }
};