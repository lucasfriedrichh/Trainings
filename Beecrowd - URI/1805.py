x, y = input().split(' ')
x = int(x)
y = int(y)
t = 0

while y >= x:
    if y == x:
        t += x
        break
    t += x
    t+=y
    x += 1
    y-=1

print(t)