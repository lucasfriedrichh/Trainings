import math

def cup_volume(h, b, B, H):
    r = b + (B - b) * (h / H)
    return (math.pi * h / 3.0) * (b**2 + b * r + r**2)

def main():
    T = int(input().strip())
    for _ in range(T):
        N, L = map(int, input().split())
        b, B, H = map(int, input().split())
        
        v_required = L / N
        
        lo, hi = 0.0, H
        for _ in range(100):
            mid = (lo + hi) / 2.0
            vol = cup_volume(mid, b, B, H)
            if vol < v_required:
                lo = mid
            else:
                hi = mid
        
        h = (lo + hi) / 2.0
        print(f"{h:.2f}")

if __name__ == '__main__':
    main()
