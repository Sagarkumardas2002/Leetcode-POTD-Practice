class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = 0;
        int empty = 0;

        // Drink all initial bottles
        drunk += numBottles;
        empty += numBottles;

        // Keep exchanging while possible
        while (empty >= numExchange) {
            empty -= numExchange;   // spend empty bottles
            numExchange++;          // requirement increases
            drunk++;                // drink the new full bottle
            empty++;                // that new bottle turns empty
        }

        return drunk;
    }
};