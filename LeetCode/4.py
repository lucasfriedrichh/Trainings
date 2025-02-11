class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        nums1 += nums2
        nums1.sort()
        if len(nums1) % 2 == 0:
            metade = (len(nums1)/2) - 1
            ans = float(nums1[int(metade)] + nums1[int(metade) + 1]) / 2
        else:
            metade = (len(nums1)/2)
            ans = float(nums1[int(metade)])
        return ans
    
solution = Solution()

print(f"ans: {solution.findMedianSortedArrays([2], [-2,-1])}")
