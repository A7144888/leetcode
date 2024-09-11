class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return"";
        }
        return str1.substr(0,gcd(size(str1),size(str2)));
    }
};/*  Runtime:6msBeats21.18
      Memory%8.74MB Beats30.24%
       寫法上不一樣就導致效能差很多，不知道為甚麼*/
