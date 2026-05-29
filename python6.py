class Solution:
    def majorityElement(self, nums):
        count = 0
        vote = None
        for num in nums:
            if count == 0:
                vote = num
            if num == vote:
                count += 1
            else:
                count -= 1
        return vote
