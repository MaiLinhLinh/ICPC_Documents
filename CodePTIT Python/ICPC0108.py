import sys
import bisect

def solve():
    data = list(map(int, sys.stdin.read().strip().split()))
    it = iter(data)
    t = next(it, 0)
    out = []

    for _ in range(t):
        n = next(it)
        a = [next(it) for _ in range(n)]
        a.sort()

        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                k = -(a[i] + a[j])
                # tìm k trong đoạn (j+1 .. n-1)
                pos = bisect.bisect_left(a, k, j + 1, n)
                if pos < n and a[pos] == k:
                    cnt += 1
        out.append(str(cnt))

    print("\n".join(out))

if __name__ == "__main__":
    solve()
