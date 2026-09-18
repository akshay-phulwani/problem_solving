class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;

        for(int i = 0; i + 10 <= s.size(); i++) {
            string x = s.substr(i, 10);
            mp[x]++;
        }

        for(auto &p : mp) {
            if(p.second > 1) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};