class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startx=0,starty=0;//起始位置 res[x][y]
        int offset=1;
        vector<vector<int>> res(n ,vector<int>(n,0));
        int loop=n/2;//總共會走n/2圈
        int mid=n/2;//最中間會==res[n/2][n/2]
        int i,j;
        int count=1;
        while(loop--){
            i=startx;
            j=starty;

            for(;j<n-offset;j++){//左至右
                res[i][j]=count++;
            }
            for(;i<n-offset;i++){//上至下
                res[i][j]=count++;
            }
            for(;j>starty;j--){//右至左
                res[i][j]=count++;
            }
            for(;i>startx;i--){//下至上
                res[i][j]=count++;
            }
            offset++;
            startx++;
            starty++;//更新起始位置和對應的offest
        }
        if(n%2==1){
            res[mid][mid]=count;//奇數則中間要另外填
        }
        return res;
        
    }
};