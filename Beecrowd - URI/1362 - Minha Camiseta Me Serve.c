#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAMISETAS 40
#define MAX_VOLUNTARIOS 35

int N, M;
int numPorTamanho;
int camisaTipo[MAX_CAMISETAS];
int match[MAX_CAMISETAS];
int volAceita[MAX_VOLUNTARIOS][2];

int toIndex(char *s) {
    if(strcmp(s, "XXL") == 0) return 0;
    if(strcmp(s, "XL")  == 0) return 1;
    if(strcmp(s, "L")   == 0) return 2;
    if(strcmp(s, "M")   == 0) return 3;
    if(strcmp(s, "S")   == 0) return 4;
    if(strcmp(s, "XS")  == 0) return 5;
    return -1;
}

bool dfs(int v, bool visitado[]) {
    for (int i = 0; i < N; i++) {
        if (!visitado[i] && (camisaTipo[i] == volAceita[v][0] || camisaTipo[i] == volAceita[v][1])) {
            visitado[i] = true;
            if (match[i] == -1 || dfs(match[i], visitado)) {
                match[i] = v;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        scanf("%d %d", &N, &M);
        numPorTamanho = N / 6;
        
        for (int tamanho = 0, idx = 0; tamanho < 6; tamanho++) {
            for (int j = 0; j < numPorTamanho; j++, idx++) {
                camisaTipo[idx] = tamanho;
            }
        }
        
        for (int i = 0; i < M; i++) {
            char s1[5], s2[5];
            scanf("%s %s", s1, s2);
            volAceita[i][0] = toIndex(s1);
            volAceita[i][1] = toIndex(s2);
        }
        
        for (int i = 0; i < N; i++) {
            match[i] = -1;
        }
        
        int resultado = 0;
        
        for (int v = 0; v < M; v++) {
            bool visitado[MAX_CAMISETAS] = {0};
            if (dfs(v, visitado))
                resultado++;
        }
        
        printf("%s\n", resultado == M ? "YES" : "NO");
    }
    
    return 0;
}
