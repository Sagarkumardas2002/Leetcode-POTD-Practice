class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        unordered_set<char> digits = {'0','1','2','3','4','5','6','7','8','9'};

        int vowelCount = 0, consonantCount = 0;

        for (char ch : word) {
            if (!isalpha(ch) && !isdigit(ch)) return false;

            if (vowels.count(ch)) {
                vowelCount++;
            } else if (isalpha(ch)) {
                consonantCount++;
            }
        }

        return word.size() >= 3 && vowelCount >= 1 && consonantCount >= 1;
    }
};
