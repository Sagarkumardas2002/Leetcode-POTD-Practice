class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size();

        for (int i = 0; i < n; i++) {
            bool placed = false;

            for (int j = 0; j < n; j++) {
                if (fruits[i] <= baskets[j]) {
                    baskets[j] = 0; // mark basket as used
                    placed = true;
                    break; // move to next fruit
                }
            }
            
             if (!placed) unplaced++;
        }
        return unplaced;
    }
};