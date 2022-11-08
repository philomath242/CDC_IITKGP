mod = 10**9 + 7


def f(s, idx, num, isz, tight, p, dp):
    if idx == len(s):
        return isz == False and num == 0
    if (idx, num, isz, tight) in dp.keys():
        return dp[(idx, num, isz, tight)]
    up = 0
    n = len(s)
    if tight:
        up = ord(s[idx]) - ord("0")
    else:
        up = 9
    res = 0
    for i in range(up + 1):
        if i == 0 and isz:
            t = 0
            if i == up:
                t = tight
            else:
                t = False

            res += f(s, idx + 1, 0, True, t, p, dp)
            res %= mod
        else:
            if (n - 1 - idx) % 2 == 0 and i % 2 != 0:
                t = 0
                if i == up:
                    t = tight
                else:
                    t = False
                nwn = num * 10 + i
                res += f(s, idx + 1, nwn % p, False, t, p, dp)
                res %= mod

            else:

                if (n - 1 - idx) % 2 != 0 and i % 2 == 0:
                    t = 0
                    if i == up:
                        t = tight
                    else:
                        t = False
                    nwn = num * 10 + i
                    res += f(s, idx + 1, nwn % p, False, t, p, dp)
                    res %= mod

    dp[(idx, num, isz, tight)] = res
    return res


p = int(input())
l = list(input())
r = input()
for i in range(len(l) - 1, -1, -1):
    if l[i] != "0":
        x = int(l[i])
        x -= 1
        l[i] = str(x)
        j = i + 1
        while j < len(l):
            l[j] = "9"

            j += 1
        break
dp = {}
# print(l)
x = f(r, 0, 0, True, True, p, dp)
# print(x)
dp = {}
y = f(l, 0, 0, True, True, p, dp)
print((x - y + mod) % mod)
