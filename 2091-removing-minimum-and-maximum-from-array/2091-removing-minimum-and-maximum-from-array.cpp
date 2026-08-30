class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a = INT_MIN, b = INT_MAX;
        int c = 0, d = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > a) {
                a = nums[i];
                c = i;
            }

            if(nums[i] < b) {
                b = nums[i];
                d = i;
            }
        }

        int n = nums.size();

        if(c > d)
            swap(c, d);

        return min({d + 1, n - c, c + 1 + n - d});
    }
};