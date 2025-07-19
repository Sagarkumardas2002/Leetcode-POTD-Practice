class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for(auto x: folder){
            if(res.empty() || x.find(res.back()+"/")!=0) res.push_back(x);
        }
        return res;
    }
};