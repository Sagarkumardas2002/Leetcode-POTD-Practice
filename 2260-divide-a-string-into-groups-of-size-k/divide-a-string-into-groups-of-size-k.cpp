class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for (int i = 0; i < s.size(); i += k) {
            string part = "";
            for (int j = 0; j < k; j++) {
                if (i + j < s.size()) {
                    part += s[i + j];
                } else {
                    part += fill;
                }
            }
            result.push_back(part);
        }
        return result;
    }
};