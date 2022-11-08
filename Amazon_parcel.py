def getMinimumCost(parcels, k):
    # Write your code here
    rem = k - len(parcels)
    pset = set(parcels)
    cur = 1
    ans = 0
    while rem:
        if cur not in pset:
            ans += cur
            rem -= 1

        cur += 1

    return ans


print(getMinimumCost([2, 3, 6, 10, 11], 9))
