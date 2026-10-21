class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = nums[0], sum2 = nums[0];
        int maxsum = nums[0], minsum = nums[0];
        int t = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            t += nums[i];

            sum1 = max(nums[i], sum1 + nums[i]);
            maxsum = max(maxsum, sum1);

            sum2 = min(nums[i], sum2 + nums[i]);
            minsum = min(minsum, sum2);
        }

        if (maxsum < 0) return maxsum;

        return max(maxsum, t - minsum);
    }
};