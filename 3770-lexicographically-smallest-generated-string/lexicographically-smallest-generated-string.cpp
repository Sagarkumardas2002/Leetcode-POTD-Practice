class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;

        string word(L, '?');
        vector<int> fixed(L, 0); // marks positions forced by T or later edits

        // step 1: enforce all T windows
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        fixed[i + j] = 1;
                    } else {
                        // Conflict: Two 'T's force different characters at the same spot
                        return "";
                    }
                }
            }
        }

        // step 2: fill remaining empty spots with 'a' (Greedy for Lexicographically smallest)
        for (int i = 0; i < L; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // step 3: handle F windows
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    // Need to break this window's match
                    bool done = false;

                    // Try from rightmost to keep prefix lexicographically smallest
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (!fixed[pos]) {
                            // Change to the smallest char != str2[j]
                            for (char c = 'a'; c <= 'z'; c++) {
                                if (c != str2[j]) {
                                    word[pos] = c;
                                    fixed[pos] = 1; // lock it
                                    done = true;
                                    break;
                                }
                            }
                        }
                        if (done) break;
                    }

                    // If we couldn't break the match (all chars were fixed)
                    if (!done) return "";
                }
            }
        }
        return word;
    }
};