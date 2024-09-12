import sys
input=lambda:sys.stdin.readline().rstrip()

for i in range(int(input())):
    n=int(input())
    print(*reversed([input().index("#")+1 for i in range(n)]))
