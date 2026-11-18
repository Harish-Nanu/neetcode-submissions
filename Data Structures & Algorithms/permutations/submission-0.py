class Solution:

    def binsearch(self, l:int, r:int, nums: List[int], target: int) -> int:
        l, r = l-1, r+1
        while l + 1 < r:
            mid = (l+r) // 2
            if nums[mid] > target:
                r = mid
            else:
                l = mid
        return r

    def permute(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        curr = n-2
        ans.append(list(nums))
        while curr >= 0:
            bigger = self.binsearch(curr+1, n-1, nums, nums[curr])
            # print(nums)
            if bigger == n:
                curr -= 1
                nums[curr+1:n] = sorted(nums[curr+1:n])
            else:
                nums[curr], nums[bigger] = nums[bigger], nums[curr]
                nums[curr+1:n] = sorted(nums[curr+1:n])
                curr = n-2
                ans.append(list(nums))
        return ans