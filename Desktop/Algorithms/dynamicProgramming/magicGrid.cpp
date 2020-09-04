/*You are given a magrid S ( a magic grid ) having R rows and C columns. 
Each cell in this magrid has either a Hungarian horntail dragon that 
our intrepid hero has to defeat, or a flask of magic potion
that his teacher Snape has left for him. A dragon at a cell (i,j) 
takes away |S[i][j]| strength points from him, and a potion at a cell 
(i,j) increases Harry's strength by S[i][j]. If his strength drops
to 0 or less at any point during his journey, Harry dies,
and no magical stone can revive him.
Harry starts from the top-left corner cell (1,1) and the Sorcerer's 
Stone is in the bottom-right corner cell (R,C). 
From a cell (i,j), Harry can only move either one cell down or right 
i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. 
Harry has used magic before starting his journey to determine which 
cell contains what, but lacks the basic simple mathematical skill 
to determine what minimum strength he needs to start with to collect 
the Sorcerer's Stone. Please help him once again.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
      int R,C;
        cin>>R>>C;
        int input[R][C],dp[R][C];
        //memset(input,0 
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>input[i][j];
            }
        }
        int m=R,n=C;
        dp[R-1][C-1]=1;
        
        for(int i=m-2;i>=0;i--){
		    dp[i][n-1] = dp[i+1][n-1] - input[i][n-1];
            if(dp[i][n-1]<=0)
                dp[i][n-1]=1;
	    }
	    
        for(int j=n-2;j>=0;j--){
		    dp[m-1][j] = dp[m-1][j+1]-input[m-1][j];
            if(dp[m-1][j]<=0)
                dp[m-1][j]=1;
        }
        
	    for(int i=m-2;i>=0;i--){
		    for(int j=n-2;j>=0;j--){
			    dp[i][j] = -input[i][j] + min(dp[i+1][j],dp[i][j+1]);
                if(dp[i][j]<=0)
                    dp[i][j]=1;
            }
	    }
        cout<<dp[0][0]<<endl;
        
    }
    return 0;
}

