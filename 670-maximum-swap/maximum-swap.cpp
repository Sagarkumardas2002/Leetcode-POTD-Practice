class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> maxRight(n);

        maxRight[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int rightMaxInd = maxRight[i + 1];
            int rightMaxElement = s[rightMaxInd];

            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxInd;
        }

        for (int i = 0; i < n; i++) {
            int maxRightIndex = maxRight[i];
            int maxRightElement = s[maxRightIndex];

            if (s[i] < maxRightElement) {
                swap(s[i], s[maxRightIndex]);
                return stoi(s);
            }
        }
        return num;
    }
};