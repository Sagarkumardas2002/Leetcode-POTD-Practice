class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int it : arr) {
            mp[it]++;
        }

        int largestLucky = -1;
        for (auto it : mp) {
            int number = -1; 
            if (it.first == it.second) {
                number = it.first;
            }
            largestLucky = max(largestLucky, number);
        }

        return largestLucky;
    }
};
