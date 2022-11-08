(n, m, k) = tuple(list(map(int, input().split())))
# print(f"n = {n} m = {m} k = {k}")
schedules = []
for i in range(n):
    schedules.append(input())
# print(schedules)

memo = [[-1] * 210] * 210
time = [[1e9] * 210] * 210


def init():
    for i in range(n):
        pos = []
        for j in range(m):
            if schedules[i][j] == "1":
                pos.append(j)
        # print(f"pos = {pos}")

        for x in range(k + 1):
            p = len(pos)
            if x >= p:
                time[i][x] = 0
                continue
            time[i][x] = 1e9

            for j in range(p):
                left = x - j
                if j > x:
                    break
                right = p - 1 - left
                time[i][x] = min(time[i][x], pos[right] - pos[j] + 1)


def rec(d, kleft):
    if d == n:
        return 0
    if memo[d][kleft] != -1:
        return memo[d][kleft]
    ans = 1e9
    for x in range(kleft + 1):
        ans = min(ans, rec(d + 1, kleft - x) + time[d][x])
    memo[d][kleft] = ans
    return ans


def solve():
    init()
    print(rec(0, k))


solve()
