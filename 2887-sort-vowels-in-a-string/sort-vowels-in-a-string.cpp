class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> v;
        
        // Step 1: Collect vowels
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                v.push_back(c);
            }
        }

        // Step 2: Sort vowels by ASCII
        sort(v.begin(), v.end());

        // Step 3: Replace vowels in order
        int idx = 0;
        for (char &c : s) {
            if (vowels.find(c) != string::npos) {
                c = v[idx++];
            }
        }

        return s;
    }
};
