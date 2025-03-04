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
    int G, P;
    while (scanf("%d %d", &G, &P) == 2) {
        if (G == 0 && P == 0) break;
        
        int resultados[101][101];

        for (int i = 0; i < G; i++){
            for (int j = 0; j < P; j++){
                scanf("%d", &resultados[i][j]);
            }
        }
        
        int S;
        scanf("%d", &S);

        while (S--) {
            int K;
            scanf("%d", &K);
            int pontos[110];
            for (int i = 0; i < K; i++){
                scanf("%d", &pontos[i]);
            }
            

            int total[110] = {0};

            for (int i = 0; i < G; i++){
                for (int j = 0; j < P; j++){
                    int pos = resultados[i][j];
                    if (pos <= K) {
                        total[j] += pontos[pos - 1];
                    }
                }
            }
            
            int max = -1;
            for (int i = 0; i < P; i++){
                if (total[i] > max)
                    max = total[i];
            }
            
            int primeiro = 1;
            for (int i = 0; i < P; i++){
                if (total[i] == max) {
                    if (!primeiro)
                        printf(" ");
                    printf("%d", i + 1);
                    primeiro = 0;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
