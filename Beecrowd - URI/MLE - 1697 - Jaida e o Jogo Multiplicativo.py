def jaida_game_multiplicative(test_cases):
    results = []
    
    for case in test_cases:
        n, nums = case
        if 1 not in nums:
            results.append(0)
            continue
        
        nums_set = set(nums)
        max_x = 0
    
        nums = sorted(nums)
    
        current = 1
        while True:
            if current in nums_set:
                max_x = current
            else:
                if current > max_x + 1:
                    break 
            
                found = False
                for num in nums:
                    product = num * current
                    if product not in nums_set:
                        nums_set.add(product)
                        nums.append(product)
                        found = True
                if not found:
                    break
            current += 1
        
        results.append(max_x)
    
    return results

t = int(input()) 
test_cases = []
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    test_cases.append((n, nums))

results = jaida_game_multiplicative(test_cases)
for res in results:
    print(res)
