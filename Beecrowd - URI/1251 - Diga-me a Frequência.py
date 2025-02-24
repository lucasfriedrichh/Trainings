import sys

def main():
    data = sys.stdin.read().splitlines()
    first_case = True

    for line in data:
        
        if not first_case:
            print()
        else:
            first_case = False
        
        freq = {}
        for char in line:
            freq[char] = freq.get(char, 0) + 1
        
        sorted_chars = sorted(freq.items(), key=lambda item: (item[1], -ord(item[0])))
        
        for char, count in sorted_chars:
            print(f"{ord(char)} {count}")

if __name__ == "__main__":
    main()
