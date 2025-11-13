class Solution {
public:
    int maxOperations(string s) {
        int operations = 0;
        int ones_count = 0;
        
        // Traverse from left to right
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ones_count++;
            } else {
                // We found a '0', check if previous char was '1'
                // If yes, all accumulated '1's will need to jump over this 0-block
                if (i > 0 && s[i - 1] == '1') {
                    operations += ones_count;
                }
            }
        }
        
        return operations;
    }
};
