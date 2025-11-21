class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        
        // For each character from 'a' to 'z'
        for(char ch = 'a'; ch <= 'z'; ch++){
            int first = -1, last = -1;
            
            // Find first occurrence
            for(int i = 0; i < n; i++){
                if(s[i] == ch){
                    first = i;
                    break;
                }
            }
            
            // Find last occurrence
            for(int i = n - 1; i >= 0; i--){
                if(s[i] == ch){
                    last = i;
                    break;
                }
            }
            
            // If the character appears at least twice
            if(first != -1 && last != -1 && last > first){
                // Count unique middle characters
                bool seen[26] = {0};
                for(int mid = first + 1; mid < last; mid++){
                    seen[s[mid] - 'a'] = true;
                }
                
                // Count distinct middle chars
                for(int k = 0; k < 26; k++){
                    if(seen[k]) ans++;
                }
            }
        }
        
        return ans;
    }
};
