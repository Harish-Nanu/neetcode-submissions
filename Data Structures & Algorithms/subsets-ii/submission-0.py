class Solution:

    def __init__(self):
        self.subsets = [[]]

    def recur(self, nums: List[int], curr: int, prev: int, subset: List[int]):
        if curr >= len(nums):
            return
        if nums[curr] != prev:
            self.recur(nums, curr+1, prev, subset+[nums[curr]])
            self.subsets.append(subset+[nums[curr]])
        self.recur(nums, curr+1, nums[curr], subset)
        

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        subset = []
        self.recur(nums, 0, 50, subset)
        return self.subsets
