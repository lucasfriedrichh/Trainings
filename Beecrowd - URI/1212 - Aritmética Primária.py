while True:
    line = input()
    a, b = map(int, line.split())

    if a == 0 and b == 0:
        break

    a = str(a)[::-1]
    b = str(b)[::-1]

    carry = 0
    carry_count = 0

    max_length = max(len(a), len(b))

    for i in range(max_length):
        digit_a = int(a[i]) if i < len(a) else 0
        digit_b = int(b[i]) if i < len(b) else 0

        total = digit_a + digit_b + carry

        if total >= 10:
            carry = 1
            carry_count += 1
        else:
            carry = 0

    if carry_count == 0:
        print("No carry operation.")
    elif carry_count == 1:
        print("1 carry operation.")
    else:
        print(f"{carry_count} carry operations.")