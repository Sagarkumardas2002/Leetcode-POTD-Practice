class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int smallestAbsolutValue = INT_MAX;
        long long sum = 0;
        int countNegative = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);

                if (matrix[i][j] < 0) {
                    countNegative++;
                }

                smallestAbsolutValue =
                    min(smallestAbsolutValue, abs(matrix[i][j]));
            }
        }

        // if the number of negatives element is even then total sum is the max sum
        if (countNegative % 2 == 0) {
            return sum;
        }

         // Adjust the sum if the number of negatives is odd
        return sum - 2 * smallestAbsolutValue;
    }
};