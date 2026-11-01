class Solution {
public:
    int minMoves(vector<int>& nums) {
       int a=INT_MAX;
       for(int i:nums) a=min(a,i);
       int b=0;
       for(int i:nums){
        b+=i-a;
       }
    return b;
    }
    
};