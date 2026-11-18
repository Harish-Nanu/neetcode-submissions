class Solution:

    def __init__(self):
        self.Sum = []

    def recur(self, nums: List[int], target: int, curr: int, sofar: List[int], prev : int):
        if(curr >= len(nums)):
            return
        if(sum(sofar) > target):
            return
        new_sofar = list(sofar)
        new_sofar.append(nums[curr])
        new_sofar_str= str(new_sofar)
        if(sum(new_sofar) == target):
            self.Sum.append(new_sofar)
            return
        if prev != nums[curr]:
            self.recur(nums, target, curr+1, new_sofar, prev)
        self.recur(nums, target, curr+1, sofar, nums[curr])

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        sofar = []
        candidates.sort()
        self.recur(candidates, target, 0, sofar, 100)
        return self.Sum