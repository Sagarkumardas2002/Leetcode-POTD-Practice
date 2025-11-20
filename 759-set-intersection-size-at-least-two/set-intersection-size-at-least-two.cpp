class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Sort: end ascending, if tie then start descending
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 if (a[1] == b[1]) 
                     return a[0] > b[0];
                 return a[1] < b[1];
             });

        int ans = 0;
        int a = -1, b = -1;  // last two picked numbers

        for (auto &it : intervals) {
            int L = it[0], R = it[1];

            bool a_in = (a >= L && a <= R);
            bool b_in = (b >= L && b <= R);

            // Case 1: already have 2 inside
            if (a_in && b_in) continue;

            // Case 2: only b inside → add 1 more
            if (b_in) {
                ans++;
                a = b;
                b = R;
            }
            // Case 3: none inside → add 2
            else {
                ans += 2;
                a = R - 1;
                b = R;
            }
        }

        return ans;
    }
};
