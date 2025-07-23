
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            return removeSubstrings(s, "ba", y, "ab", x);
        } else {
            return removeSubstrings(s, "ab", x, "ba", y);
        }
    }
    
private:
    int removeSubstrings(const string& s, const string& first, int firstScore, const string& second, int secondScore) {
        stack<char> st;
        int score = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == first[0] && c == first[1]) {
                st.pop();
                score += firstScore;
            } else {
                st.push(c);
            }
        }
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        for (char c : remaining) {
            if (!st.empty() && st.top() == second[0] && c == second[1]) {
                st.pop();
                score += secondScore;
            } else {
                st.push(c);
            }
        }
        return score;
    }
};