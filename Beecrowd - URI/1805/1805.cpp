#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
int main() {
 
    long long a, b, sum;
    scanf("%lld %lld", &a, &b);
    sum = (b * (b+1)- (a*(a-1)))/2;
    printf("%lld\n", sum);
    
    return 0;
}