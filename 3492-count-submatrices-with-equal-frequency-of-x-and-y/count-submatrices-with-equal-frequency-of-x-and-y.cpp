class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> freqX(n, vector<int>(m, 0));
        vector<vector<int>> freqY(n, vector<int>(m, 0));

        // count freq in 1st col
        for(int i=0; i<n; i++){
            if(grid[i][0] == 'X'){
                freqX[i][0] = 1;
            } else if( grid[i][0] == 'Y'){
                freqY[i][0] = 1;
            }
        }

        // count freq row wise of X and Y till each cell
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                
                freqY[i][j] = freqY[i][j-1];
                freqX[i][j] = freqX[i][j-1];

                if(grid[i][j] == 'X'){
                    freqX[i][j]++;
                } else if( grid[i][j] == 'Y'){
                    freqY[i][j]++;
                }
            }
        }
        // each cell will contain thr freq of X and Y in the submtrix till i, j from 0, 0 
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){

                freqX[i][j] += freqX[i-1][j];
                freqY[i][j] += freqY[i-1][j];

            }
        }
        // count the submatrix according to the condition
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(freqX[i][j] > 0 && freqX[i][j] == freqY[i][j]){
                    count++;
                }
            }
        }

        return count;

    }
};