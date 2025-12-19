class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        int i = 0;
        int m = meetings.size();

        while (i < m) {
            int time = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            unordered_set<int> persons;

            // collect all meetings at the same time
            while (i < m && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                persons.insert(x);
                persons.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            // start BFS from people who already know the secret
            for (int p : persons) {
                if (knowsSecret[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // spread secret within same time
            while (!q.empty()) {
                int u = q.front(); q.pop();
                knowsSecret[u] = true;
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (knowsSecret[i]) ans.push_back(i);
        }
        return ans;
    }
};
