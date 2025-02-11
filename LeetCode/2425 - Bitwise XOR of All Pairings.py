class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:        
        xor_nums1 = 0
        xor_nums2 = 0

        for num in nums1:
            xor_nums1 ^= num
        for num in nums2:
            xor_nums2 ^= num

        if len(nums1) % 2 == 0 and len(nums2) % 2 == 0:
            return 0
        elif len(nums1) % 2 == 1 and len(nums2) % 2 == 1:
            return xor_nums1 ^ xor_nums2
        elif len(nums1) % 2 == 1:
            return xor_nums2
        else:
            return xor_nums1

