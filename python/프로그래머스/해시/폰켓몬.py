def solution(nums):
    answer = 0
    s = set(nums)
    return min(len(s), len(nums) / 2)