class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int k=nums.size()-1;
       for(int head=0,tail=nums.size()-1;head<=tail; ){
            if(pow(nums[head],2)>pow(nums[tail],2)){
                result[k--]=(pow(nums[head],2));
                head++;
            }
            else{
                result[k--]=(pow(nums[tail],2));
                tail--;
            }
        }
        return result;
    }
};