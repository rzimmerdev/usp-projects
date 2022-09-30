def swap(n, a, b):
    buff = n[a]
    n[a] = n[b]
    n[b] = buff


def merge(n, m):
    merged = list()
    i, j = 0, 0
    inversions = 0

    while i < len(n) and j < len(m):
        if n[i] < m[j]:
            merged.append(n[i])
            i += 1
        else:
            merged.append(m[j])
            inversions += len(n) - i
            j += 1

    while i < len(n):
        merged.append(n[i])
        i += 1
    while j < len(m):
        merged.append(m[j])
        j += 1

    return merged, inversions


def mergesort(n):
    inversions = 0
    if len(n) == 2:
        if n[0] >= n[1]:
            swap(n, 0, 1)
            inversions = 1
    elif len(n) > 2:
        center = len(n) // 2
        a, inversions_a = mergesort(n[:center])
        b, inversions_b = mergesort(n[center:])

        inversions += inversions_a + inversions_b

        n, inversions_n = merge(a, b)
        inversions += inversions_n
    return n, inversions


def main():
    cases = int(input())

    for case in range(cases):
        _ = input()
        endings = [int(x) - 1 for x in input().split()]
        n, inversions = mergesort(endings)
        print(inversions)


if __name__ == "__main__":
    main()
