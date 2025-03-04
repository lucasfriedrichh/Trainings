#include <stdio.h>
#include <string.h>

int main(void) {
    char map[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char decode[256];
    memset(decode, 0, sizeof(decode));

    int len = strlen(map);
    for (int i = 1; i < len; i++) 
        decode[(unsigned char)map[i]] = map[i - 1];
    

    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') 
            putchar(c);
        else if (decode[c]) 
            putchar(decode[c]);
        else 
            putchar(c);
        
    }

    return 0;
}
