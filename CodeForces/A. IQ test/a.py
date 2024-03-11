n = int(input())
nums = input().split()
even = []
odd = []

for i in range(len(nums)):
    if int(nums[i]) % 2 == 0:
        even.append(i)
    else:
        odd.append(i)

if len(even) < len(odd):
    for eve in even:
        print(eve + 1)
else:
    for eve in odd:
        print(eve + 1)