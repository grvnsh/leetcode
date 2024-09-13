class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        curr = 0
        prev = float('inf')
        for i in range(1, len(nums)):
            current_diff = nums[i] - nums[i-1]
            if current_diff == prev:
                curr += 1
                count += curr
            else:
                curr = 0
            prev = current_diff
        return count