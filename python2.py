def countingValleys(steps):
    altitude = 0
    valleys = 0
    for step in steps:
        if step == 'U':
            altitude += 1
            if altitude == 0:
                valleys += 1
        else:
            altitude -= 1
    return valleys
print(countingValleys("UDDDUDUU"))
