#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) rep(i, 0, (n))


int main(){
    int n;
    while(scanf("%d",&n)==1){
        int countE[61]={0}, countD[61]={0};
        for(int i=0;i<n;i++){
            int m; char l;
            scanf("%d %c",&m,&l);
            if(l=='E') countE[m]++;
            else countD[m]++;
        }
        int ans=0;
        for(int i=30;i<=60;i++) ans += countE[i] < countD[i] ? countE[i] : countD[i];
        printf("%d\n",ans);
    }
    return 0;
}
