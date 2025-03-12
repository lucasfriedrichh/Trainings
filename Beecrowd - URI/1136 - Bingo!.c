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
    
    int N, B;
    while(scanf("%d %d", &N, &B) && (N||B)){
        int a[101]={0}, i, j, d, ok=1;
        for(i=0;i<B;i++) scanf("%d", &a[i]);
        int diff[101]={0};
        for(i=0;i<B;i++)
            for(j=0;j<B;j++){
                d=abs(a[i]-a[j]);
                if(d<=N) diff[d]=1;
            }
        for(i=0;i<=N;i++){
            if(!diff[i]){
                ok=0;
                break;
            }
        }
        printf("%c\n", ok?'Y':'N');
    }
    return 0;

}