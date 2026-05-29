
n=len(nums)
print(n)
for i in range(n-1):
    key=nums[i]
    for j in range(n-j-1):
        if nums[i+1]<nums[i]:
            nums[i],nums[i+1]=nums[i+1],nums[i]
print(nums)








