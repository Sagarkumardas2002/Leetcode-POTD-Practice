class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag = true; //true -> increasing and false -> decreasing
        int count = 0; //should be exactly 3 at end
        if(nums[0] < nums[1])count++;
        else return false;

        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1] || count > 3)return false;
            if(flag && nums[i] > nums[i+1]){
                flag = false;
                count++;
            }else if(!flag && nums[i] < nums[i+1]){
                flag = true;
                count++;
            }
        }

        return count == 3;
    }
};