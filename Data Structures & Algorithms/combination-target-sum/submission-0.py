class Solution:

    def __init__(self):
        self.Sum = []

    def recur(self, nums: List[int], target: int, curr : int, sofar : List[int]):
        if(sum(sofar) > target):
            return
        if(curr >= len(nums)):
            return
        new_sofar = list(sofar)
        new_sofar.append(nums[curr])
        if(sum(sofar) == target):
            self.Sum.append(sofar)
            return
        self.recur(nums, target, curr, new_sofar)
        self.recur(nums, target, curr+1, sofar)

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        sofar = []
        self.recur(nums, target, 0, sofar)
        return self.Sum