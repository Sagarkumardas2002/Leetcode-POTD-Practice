class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int>outer(n+1,0);
      vector<int>inner(n+1,0);

      for(auto &it:trust){
        int a=it[0];
        int b=it[1];

        outer[a]++;
        inner[b]++;
      }  

      for(int i=1;i<=n;i++){
        if(outer[i]==0 && inner[i]==n-1){
            return i;
        }
      }

      return -1;
    }
};