class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int result;
        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.second>1){
                result=it.first;
            }
        }
        return result;
    }
};