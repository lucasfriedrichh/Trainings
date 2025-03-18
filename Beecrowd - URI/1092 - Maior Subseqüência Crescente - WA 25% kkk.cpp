#include <bits/stdc++.h>
using namespace std; 
static const int MAXN=600,MAXM=600;
static int mat[MAXN][MAXM],RightPos[MAXN][MAXM],chainArr[MAXN],minC2[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        int N,M;cin>>N>>M;if(!cin||(!N&&!M))break;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0;i<N;i++){
            RightPos[i][M-1]=M-1;
            for(int j=M-2;j>=0;j--){
                if(mat[i][j]<mat[i][j+1]) RightPos[i][j]=RightPos[i][j+1];
                else RightPos[i][j]=j;
            }
        }
        int ans=1;
        for(int c1=0;c1<M;c1++){
            for(int i=0;i<N;i++){
                minC2[i]=RightPos[i][c1];
            }
            chainArr[0]=1;
            {
                int w=minC2[0]-c1+1,area=w;
                ans=max(ans,area);
            }
            for(int i=1;i<N;i++){
                int c2=min(minC2[i-1],minC2[i]);
                if(mat[i-1][c2]<mat[i][c1]){
                    chainArr[i]=chainArr[i-1]+1;
                    minC2[i]=c2;
                } else {
                    chainArr[i]=1;
                }
                int w=minC2[i]-c1+1,area=chainArr[i]*w;
                ans=max(ans,area);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
