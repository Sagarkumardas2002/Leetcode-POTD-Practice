#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pii = pair<int,int>; // (freq, val)

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<int,int> freq;

        // Custom comparator for sorting: freq desc, then val desc
        auto cmp = [](const pii &a, const pii &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };

        // topX = top x frequent numbers
        multiset<pii, decltype(cmp)> topX(cmp);
        multiset<pii, decltype(cmp)> rest(cmp);
        unordered_map<int, multiset<pii, decltype(cmp)>::iterator> pos;

        long long currSum = 0;

        auto add = [&](int val) {
            int oldFreq = freq[val]++;
            int newFreq = freq[val];
            pii newPair = {newFreq, val};

            // Remove old position if exists
            if (oldFreq > 0) {
                pii oldPair = {oldFreq, val};
                if (pos.count(val)) {
                    auto it = pos[val];
                    if (topX.find(*it) != topX.end()) {
                        currSum -= 1LL * it->first * it->second;
                        topX.erase(it);
                    } else {
                        rest.erase(it);
                    }
                }
            }

            // Insert new frequency
            rest.insert(newPair);
            pos[val] = rest.find(newPair);

            // Move best elements to topX
            while ((int)topX.size() < x && !rest.empty()) {
                auto best = *rest.begin();
                currSum += 1LL * best.first * best.second;
                topX.insert(best);
                pos[best.second] = topX.find(best);
                rest.erase(rest.begin());
            }

            // Fix ordering if needed
            if (!topX.empty() && !rest.empty()) {
                auto worstTop = prev(topX.end());
                auto bestRest = *rest.begin();
                if (cmp(bestRest, *worstTop)) {
                    // Swap
                    currSum -= 1LL * worstTop->first * worstTop->second;
                    currSum += 1LL * bestRest.first * bestRest.second;
                    topX.insert(bestRest);
                    pos[bestRest.second] = topX.find(bestRest);
                    rest.insert(*worstTop);
                    pos[worstTop->second] = rest.find(*worstTop);
                    topX.erase(worstTop);
                    rest.erase(rest.begin());
                }
            }
        };

        auto remove = [&](int val) {
            int oldFreq = freq[val];
            if (oldFreq == 0) return;
            pii oldPair = {oldFreq, val};

            // Erase old
            if (pos.count(val)) {
                auto it = pos[val];
                if (topX.find(*it) != topX.end()) {
                    currSum -= 1LL * it->first * it->second;
                    topX.erase(it);
                } else {
                    rest.erase(it);
                }
                pos.erase(val);
            }

            freq[val]--;
            if (freq[val] == 0) {
                freq.erase(val);
                return;
            }

            // Insert new freq
            pii newPair = {freq[val], val};
            rest.insert(newPair);
            pos[val] = rest.find(newPair);

            // Balance sizes
            while ((int)topX.size() < x && !rest.empty()) {
                auto best = *rest.begin();
                currSum += 1LL * best.first * best.second;
                topX.insert(best);
                pos[best.second] = topX.find(best);
                rest.erase(rest.begin());
            }

            if (!topX.empty() && !rest.empty()) {
                auto worstTop = prev(topX.end());
                auto bestRest = *rest.begin();
                if (cmp(bestRest, *worstTop)) {
                    currSum -= 1LL * worstTop->first * worstTop->second;
                    currSum += 1LL * bestRest.first * bestRest.second;
                    topX.insert(bestRest);
                    pos[bestRest.second] = topX.find(bestRest);
                    rest.insert(*worstTop);
                    pos[worstTop->second] = rest.find(*worstTop);
                    topX.erase(worstTop);
                    rest.erase(rest.begin());
                }
            }
        };

        // Initial window
        for (int i = 0; i < k; i++) add(nums[i]);
        ans.push_back(currSum);

        // Sliding window
        for (int i = k; i < n; i++) {
            remove(nums[i - k]);
            add(nums[i]);
            ans.push_back(currSum);
        }

        return ans;
    }
};
