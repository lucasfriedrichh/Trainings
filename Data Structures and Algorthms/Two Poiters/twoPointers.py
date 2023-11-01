#Find de sum of 2 of these indexes that is the target
arr = [1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,5]
target = 9

#Point declaration
# l == 0
# r == size of the arr
l,r  = 0 , len(arr)-1

while l<r:
    sum = arr[l] + arr[r]
    if sum<target:
        l+=1
    elif sum > target:
        r+=1
    elif sum == target:
        print(f"Find the ans: {arr[l]} + {arr[r]} == {target}")
        break