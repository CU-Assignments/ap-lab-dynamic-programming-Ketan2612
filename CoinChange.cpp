class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            int t[n+1][amount+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<amount+1;j++){
                    if(i==0){
                        t[i][j]=INT_MAX-1;
                    }
                    if(j==0){
                        t[i][j]=0;
                    }
                }
            }
            for(int i=1;i<amount+1;i++){
                if(i%coins[0]==0) t[1][i]=i/coins[0];
                else t[1][i]=INT_MAX-1;
            }
            for(int i=2;i<n+1;i++){
                for(int j=1;j<amount+1;j++){
                    if(coins[i-1]<=j){
                        t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                    }
                    else{
                        t[i][j]=t[i-1][j];
                    }
    
                }
            }
            if( t[n][amount]==INT_MAX-1){
                return -1;
            }
            else{
                return t[n][amount];
            }
        }
    };