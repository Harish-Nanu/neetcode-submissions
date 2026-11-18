class Solution:

    def __init__(self):
        self.subset = [[]]

    def recur(self, nums: List[int], sofar: List[int], idx : int):
        if idx >= len(nums):
            return
        new_sofar = list(sofar)
        new_sofar.append(nums[idx])
        self.subset.append(new_sofar)
        self.recur(nums, sofar, idx+1)
        self.recur(nums, new_sofar, idx+1)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        sofar = []
        self.recur(nums, sofar, 0)
        return self.subset