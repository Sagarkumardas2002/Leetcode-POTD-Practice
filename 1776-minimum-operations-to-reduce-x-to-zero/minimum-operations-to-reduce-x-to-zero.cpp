class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        int totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }

        int target=totalSum-x;

        if(target<0){
            return -1;
        }

        int left=0;
        int currentSum=0;
        int maxLen=-1;

        for(int right=0;right<n;right++){
            currentSum+=nums[right];

            while(currentSum>target && right>=left){
                currentSum-=nums[left];

                left++;
            }

            if(currentSum==target){
                int length=right-left+1;

                if(length>maxLen) maxLen=length;
            }

        }
        if(maxLen==-1) return -1;
        return n-maxLen;
    }
};