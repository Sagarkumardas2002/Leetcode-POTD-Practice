class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long ans=0;
        map<int,int> count;
        vector<pair<int,int>> v;
        
        for(auto i:power) count[i]++;
        for(auto i:count) v.push_back(i);
        long long mx =0;
        vector<long long> f(v.size(),0);
        for(int i=0, j=0;i<v.size();i++)
        {
            while(j<i && v[j].first<v[i].first-2)
            {
                mx = max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1LL*v[i].first*v[i].second;
        }

        for(int i=0;i<f.size();i++)
        {
            ans = max(ans, f[i]);
        }
        
        return ans;
    }
};