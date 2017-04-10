from math import log, ceil


def cut_arr(arr):
    mlen = -1
    _max = 0
    arrlen = len(arr)
    for i in range(arrlen):
        if len(arr[i]) > mlen:
            _max = i
            mlen = len(arr[i])
    # print(_max, arr)
    half = len(arr[_max]) // 2
    l = arr[_max][: half]
    r = arr[_max][half + 1:]
    del arr[_max]
    arr.insert(_max, r)
    arr.insert(_max, l)
    return arr

def get_max_id(arr):
    alen = len(arr)
    if alen < 2:
        return 0
    _max = arr[0]
    mid = 0
    for i in range(1, alen):
        val = arr[i]
        if val > _max:
            mid = i
            _max = val
    return mid

def cut2(arr):
    mid = get_max_id(arr)
    val = arr[mid] - 1
    del arr[mid]
    l = ceil(val / 2)
    r = val - l
    arr.insert(mid, r)
    arr.insert(mid, l)
    return arr, mid


def prob2(n, k, case):
    # arr = [n]
    # while k:
    #     arr, mid = cut2(arr)
    #     k -= 1
    # print("Case #{}: {} {}".format(case, arr[mid], arr[mid + 1]))
    x = int(log(k, 2)) + 1
    l = int(n // (2 ** x))
    r = l if x != k else l - 1
    print("Case #{}: {} {}".format(case, l, r))


def prob(stalls, k, case):
    while k:
        # stalls = cut_arr(stalls)
        k -= 1
    # stalls = cut_arr(stalls)
    # print(stalls)
    # print("Case #{}: {} {}".format(case, len(stalls[0]), len(stalls[1])))


with open('input.in', 'r') as fin:
    T = int(fin.readline().strip())
    for i in range(1, T + 1):
        # N stalls
        # K ppl
        N, K = (int(x) for x in fin.readline().strip().split())
        prob2(N, K, i)
