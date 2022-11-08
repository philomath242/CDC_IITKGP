def main(spstrings, inp):
    string = inp
    for s in spstrings:
        string = string.replace(s, "")

    print(string)


main(["ad", "bz", "ax"], "axgy")
