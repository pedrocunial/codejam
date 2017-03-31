import itertools

with open("small.in", "r") as fin, open("output.out", "w") as fout:
    L, D, T = (int(x) for x in fin.readline().strip().split())

    words = set()
    for i in range(D):
        words.add(fin.readline().strip())


    for case in range(T):
        w = fin.readline().strip()

        r = []
        i = 0
        while i < len(w):
            item = []
            if w[i] == "(":
                i += 1
                while w[i] != ")":
                    item.append(w[i])
                    i += 1
                i += 1

            else:
                item.append(w[i])
                i += 1

            r.append(item)

        words_1 = words.copy()
        words_2 = set()

        for c in range(L):
            for p in words_1:
                if p[c] in r[c]:
                    words_2.add(p)
            words_1 = words_2
            words_2 = set()

        fout.write("Case #{}: {}\n".format(case + 1, len(words_1)))

    print("done")
