class Solution {
public:
    bool isValid(string word) {
        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        set<char> num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        set<char> consonent = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                               'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w',
                               'x', 'y', 'z', 'B', 'C', 'D', 'F', 'G', 'H',
                               'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S',
                               'T', 'V', 'W', 'X', 'Y', 'Z'};

        int vCount = 0;
        int numCount = 0;
        int consCount = 0;
        int otherCount=0;

        for (auto& it : word) {
            if (vowel.find(it) != vowel.end()) {
                vCount++;
            } else if (num.find(it) != num.end()) {
                numCount++;
            } else if (consonent.find(it) != consonent.end()) {
                consCount++;
            }
            else{
                otherCount++;
            }
        }

        if (word.size() >= 3 && vCount >= 1 && consCount >= 1 && otherCount==0) {
            return true;
        }
        return false;
    }
};