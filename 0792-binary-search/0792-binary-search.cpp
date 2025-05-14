class Solution {
public:
    int search(vector<int>& nums, int target) {
        int goal=-1;
        int left=0,right=nums.size();
        while(left<right){//size為n的vector實際上的最大index為n-1,所以=right時已經超出範圍外
            int middle=(left+right)/2;
            if(nums[middle]>target){//在middle左邊
                right=middle;
            }
            else if(nums[middle]<target){//在middle右邊
                left=middle+1;
            }
            else{
                goal=middle;
                return goal;
            }
        }
        return goal;
    }
};