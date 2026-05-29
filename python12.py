n = int(input("enter number"))
temp = n
rev = 0
while temp > 0:
    rev = rev* 10 + temp % 10
    temp //= 10
sq = n * n
temp = sq
rev_sq = 0
while temp > 0:
    rev_sq= rev_sq * 10 + temp % 10
    temp //= 10
sq_rev = rev * rev
if rev_sq== sq_rev:
    print("Adam Number")
else:
    print("Not an Adam Number")
