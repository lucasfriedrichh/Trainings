#TLE

def is_lucky(ticket):
    n = len(ticket)
    if n % 2 == 1:
        return False
    half = n // 2
    first_half = ticket[:half]
    second_half = ticket[half:]
    return sum(map(int, first_half)) == sum(map(int, second_half))

n = int(input())
tickets = input().split()

lucky_count = 0

for i in range(n):
    for j in range(n):
        if is_lucky(tickets[i] + tickets[j]):
            lucky_count += 1

print(lucky_count)
