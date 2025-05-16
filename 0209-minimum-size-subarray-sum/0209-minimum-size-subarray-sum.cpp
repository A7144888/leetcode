class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start,end,sum=0,sublength=0;//sumarray長度
        int result=INT32_MAX;
        for(end=0;end<nums.size();end++){
            sum+=nums[end];
            while(sum>=target){
                sublength=end-start+1;
                result=min(result,sublength);
                sum-=nums[start++];
            }
        }
        return result==INT32_MAX?0:result;
    }
};