import sys, math

def closest_pair(P, Q):
    n = len(P)
    if n <= 3:
        best = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                dx = P[i][0] - P[j][0]
                dy = P[i][1] - P[j][1]
                best = min(best, dx*dx + dy*dy)
        return best

    mid = n // 2
    midx = P[mid][0]
    P_left = P[:mid]
    P_right = P[mid:]
    
    Q_left = []
    Q_right = []
    for p in Q:
        if p[0] <= midx:
            Q_left.append(p)
        else:
            Q_right.append(p)
    
    d_left = closest_pair(P_left, Q_left)
    d_right = closest_pair(P_right, Q_right)
    d = min(d_left, d_right)
    
    strip = [p for p in Q if abs(p[0] - midx) < math.sqrt(d)]
    
    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if (strip[j][1] - strip[i][1]) >= math.sqrt(d):
                break
            dx = strip[i][0] - strip[j][0]
            dy = strip[i][1] - strip[j][1]
            d = min(d, dx*dx + dy*dy)
    return d

def main():
    data = sys.stdin.read().split()
    idx = 0
    while idx < len(data):
        n = int(data[idx])
        idx += 1
        if n == 0:
            break
        points = []
        for _ in range(n):
            x = float(data[idx])
            y = float(data[idx+1])
            idx += 2
            points.append((x, y))

        if n < 2:
            print("INFINITY")
            continue


        P = sorted(points, key=lambda p: p[0])
        Q = sorted(points, key=lambda p: p[1])
        d_sq = closest_pair(P, Q)
        d = math.sqrt(d_sq)
        if d >= 10000:
            print("INFINITY")
        else:
            print(f"{d:.4f}")

if __name__ == "__main__":
    main()
