class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max=*max_element(candies.begin(),candies.end());
       vector<bool> result;

       for(int i:candies){
        result.push_back(i+extraCandies>=max);
       }
       return result;
    }
};