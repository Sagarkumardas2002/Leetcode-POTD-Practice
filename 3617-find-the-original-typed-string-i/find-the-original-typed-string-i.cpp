class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();

        // start with 1: the original word is always one possibility
        int count = 1;  
        
        // Try reducing one or more repeats in a single group (only one group allowed)
        for (int i = 0; i < n;) {
            int j = i;

            // Count the length of a repeating character group
            while (j < n && word[j] == word[i]) j++;
            int len = j - i;
            if (len > 1) {
                count += (len - 1);  // We can reduce this group in (len - 1) ways
            }
            
            i = j;  // Move to the next group
        }

        return count;
    }
};
