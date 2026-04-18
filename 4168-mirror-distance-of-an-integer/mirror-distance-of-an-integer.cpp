class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int reversed = 0;

        // reverse the number
        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }

        // return absolute difference
        return abs(original - reversed);
    }
};