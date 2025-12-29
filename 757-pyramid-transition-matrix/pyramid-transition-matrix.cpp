class Solution {
public:
    unordered_set<string> bad;

    bool solve(int idx, string bottom, string next, unordered_map<string, vector<char>>& mp) {
        if(bottom.size() == 1) return true;

        // Only check memo at the start of a new row
        if(idx == 0 && bad.count(bottom)) return false;

        if(idx == bottom.size() - 1){
            bool res = solve(0, next, "", mp);
            if(!res)
                bad.insert(bottom);  // Mark full row as bad if no solution
            return res;
        }

        string key = bottom.substr(idx, 2);
        if(mp.find(key) == mp.end()) return false;

        for(char it : mp[key]){
            next.push_back(it);
            if(solve(idx + 1, bottom, next, mp)) return true;
            next.pop_back();  // backtrack
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(string& s : allowed){
            string key = s.substr(0, 2);
            mp[key].push_back(s[2]);
        }
        return solve(0, bottom, "", mp);
    }
};