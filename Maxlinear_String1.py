# abac
# abc..........


def main(string):
    # string = input()
    res = ["."] * 26
    for c in string:
        res[ord(c) - ord("a")] = c

    ans = ""

    for c in res:
        ans += c

    print(ans)


main("abac")
