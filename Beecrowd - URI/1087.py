def main():
    x1,y1,x2,y2= map(int, input().split())
    if x1==0:
        return
    if x1 == x2 and y1 == y2:
        print(0)
    elif x1 == x2 or y1 == y2:
        print(1)
    elif x1 - x2 == x1-y2:
        print(1)
    elif x1 + x2 == x1 + y2:
        print(1)
    else:
        print(2)


if __name__ == "__main__":
    while True:
        try:
            main()
        except EOFError:
            break