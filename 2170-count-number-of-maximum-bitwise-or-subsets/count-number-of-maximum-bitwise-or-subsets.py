class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_or = 0
        for num in nums:
            max_or |= num
        def back(i, curr):
            if i == len(nums):
                return 1 if curr == max_or else 0
            in_ = back(i + 1, curr | nums[i])
            out = back(i + 1, curr)
            return in_ + out
        return back(0, 0)