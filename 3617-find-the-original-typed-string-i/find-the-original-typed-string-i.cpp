class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int count=1;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && word[j]==word[i]) j++;
            int length=j-i;

            if(length>1){
                count+=(length-1);
            }
            i=j;
        }
        return count;
    }
};