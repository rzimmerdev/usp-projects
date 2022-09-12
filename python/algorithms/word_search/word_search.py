def is_inside(pos, dimensions: tuple):
    return (0 <= pos[0] < dimensions[0]) and \
           (0 <= pos[1] < dimensions[1])


def sum_pos(pos, move):
    return pos[0] + move[0], pos[1] + move[1]


def permute(n, m):
    return [(i, j) for j in range(m) for i in range(n)]


def dfs(pos, matrix, marked, dimensions, word, cur_sequence=""):
    if not is_inside(pos, dimensions) or marked[pos[0]][pos[1]]:
        return False

    new_sequence = cur_sequence + matrix[pos[0]][pos[1]]
    if word == new_sequence:
        return True

    marked[pos[0]][pos[1]] = True

    moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    for move in moves:
        new_pos = sum_pos(pos, move)
        if dfs(new_pos, matrix, marked, dimensions, word, new_sequence):
            return True

    marked[pos[0]][pos[1]] = False
    return False


def find_word(matrix: list, word: str):

    n, m = len(matrix), len(matrix[0])

    marked = [[False for _ in range(m)] for _ in range(n)]
    starting_positions = permute(n, m)

    for pos in starting_positions:
        if dfs(pos, matrix, marked, (n, m), word, ""):
            return True
    return False


def main():
    n, m = (int(x) for x in input().split(" "))
    char_matrix = []

    for i in range(n):
        char_matrix.append(list(input()))

    _, word = input(), input()

    print("Yes" if find_word(char_matrix, word) else "No")


if __name__ == "__main__":
    main()
