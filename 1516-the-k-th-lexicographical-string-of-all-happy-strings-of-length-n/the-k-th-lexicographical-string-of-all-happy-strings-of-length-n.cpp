class Solution {
public:
vector<string> ans;
int nn;
void rec(string s){
    if(s.size()==nn) {
        ans.push_back(s);
        return;
    }
    if(s[s.size()-1]=='a'){
        rec(s+'b');
        rec(s+'c');
    }
    else if(s[s.size()-1]=='b'){
        rec(s+'a');
        rec(s+'c');
    }
    else{
        rec(s+'a');
        rec(s+'b');
    }
}
    string getHappyString(int n, int k) {
        nn= n;
        rec("a");
        rec("b");
        rec("c");
        if(ans.size()<k) return "";
        else return ans[k-1];
    }
};