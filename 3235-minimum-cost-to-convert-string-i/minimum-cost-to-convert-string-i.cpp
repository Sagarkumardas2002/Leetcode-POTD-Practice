class Solution {
private:

    // Solves the all-pairs shortest path problem using Floyd Warshall algorithm
    void floydWarshall(vector<vector<long long>> &dist) {
        int V = dist.size();

        // Add all vertices one by one to the set of intermediate vertices.
        for (int k = 0; k < V; k++) {

            // Pick all vertices as source one by one
            for (int i = 0; i < V; i++) {

                // Pick all vertices as destination for the above picked source
                for (int j = 0; j < V; j++) {

                    // shortest path from i to j 
                    if(dist[i][k] != 1e8 && dist[k][j]!= 1e8)
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = original.size();
        vector<vector<long long>> dist(26, vector<long long>(26, 1e8));
        long long ans = 0;

        for(int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for(int i = 0; i < n; i++){
            
            char start = original[i];
            char end = changed[i];
            int value = cost[i];

            dist[start - 'a'][end - 'a'] = min(dist[start - 'a'][end - 'a'], (long long)value);
        }

        floydWarshall(dist);

        for(int i = 0; i < source.length(); i++){

            char sour = source[i];
            char dest = target[i];

            if(sour == dest)
                continue;
            else {
                if(dist[sour - 'a'][dest - 'a'] == 1e8)
                    return -1;
                else
                    ans += dist[sour - 'a'][dest - 'a'];
            }
        }

        return ans;
    }
};