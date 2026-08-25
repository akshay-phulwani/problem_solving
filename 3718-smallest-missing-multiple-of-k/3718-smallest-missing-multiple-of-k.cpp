class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        for(int i=1;;i++){
            if(ans.find(i*k)==ans.end()) return i*k;
        }
    }
};