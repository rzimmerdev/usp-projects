def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return low


def main():
    n, m = map(int, input().split())
    songs = list()
    acc_time = [0]
    count = 0
    for song in range(n):

        song_attr = [int(x) for x in input().split()]

        for _ in range(song_attr[0]):
            songs.append(song)
            acc_time.append(acc_time[count] + song_attr[1])
            count += 1

    acc_time.pop(0)
    count -= 1

    for time in map(int, input().split()):
        find = binary_search(acc_time, 0, len(acc_time) - 1, time)
        print(songs[find] + 1)


if __name__ == "__main__":
    main()
