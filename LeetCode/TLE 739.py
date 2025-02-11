class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        ans = []
        for i in range(len(temperatures)):
            flag = False
            if i == len(temperatures):
                ans.append(0)
                break
            
            j=i+1
            couter = 0
            while j < len(temperatures):
                if temperatures[i] < temperatures[j]:
                    couter +=1
                    flag = True
                    break
                else:
                    couter +=1
                    j+=1

            if flag:
                ans.append(couter)
            else:
                ans.append(0)


        return ans



sol = Solution()
print(sol.dailyTemperatures([73,74,75,71,69,72,76,73]))