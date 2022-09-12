board_size = 8


def pprint(matrix: list, end):
    print(*matrix, sep="\n", end=end)


def toggle_place(coord, col, diagonal_l, diagonal_r):
    col[coord[0]] = not col[coord[0]]
    diagonal_l[coord[1] - coord[0] + board_size - 1] = not diagonal_l[coord[1] - coord[0] + board_size - 1]
    diagonal_r[coord[1] + coord[0]] = not diagonal_r[coord[1] + coord[0]]


def dfs(pos, board, col, diagonal_l, diagonal_r, sequence, total):
    if pos == board_size:
        return max(sequence, total)

    for i in range(board_size):
        if not col[i] and not diagonal_l[pos - i + board_size - 1] and not diagonal_r[pos + i]:

            toggle_place((i, pos), col, diagonal_l, diagonal_r)
            sequence = dfs(pos + 1, board, col, diagonal_l, diagonal_r, sequence, total + board[pos][i])
            toggle_place((i, pos), col, diagonal_l, diagonal_r)

    return sequence


def count_positions(board):
    col = [False for _ in range(board_size)]
    diagonal_l = [False for _ in range(15)]
    diagonal_r = [False for _ in range(15)]

    return dfs(0, board, col, diagonal_l, diagonal_r, 0, 0)


def main():
    k = int(input())

    for case in range(k):

        board = []
        for i in range(board_size):
            board.append([int(val) for val in input().split()])

        # pprint(board, end="\n\n")
        print("{0:5d}".format(count_positions(board)))


if __name__ == "__main__":
    main()
