import sys
import math


def get_digit(number, n):
    return number // 10 ** (n - 1) % 10


def num_fixed(value, fix) -> str:
    num = ""
    insignificant = True
    for i in range(fix, 0, -1):
        digit = get_digit(value, i)
        if digit != 0:
            insignificant = False
        if not insignificant:
            num += str(get_digit(value, i))
        else:
            num += " "
    return num


class Graph:

    def __init__(self, matrix):
        self._adjaceny_matrix = matrix
        self._total_nodes = len(matrix)

    def pretty_print(self):
        biggest = (max(map(max, self._adjaceny_matrix)))

        num_size = math.ceil(math.log10(biggest))
        for line in self._adjaceny_matrix:
            for val in line:
                print(num_fixed(val, num_size), end=" ")
            print("\n", end="")

    @staticmethod
    def closest_node(distances, root):
        return min(range(len(distances[root])), key=distances[root].__getitem__)

    def dijkstra(self, root):

        dist = [sys.maxsize] * self._total_nodes
        dist[root] = 0
        sptSet = [False] * self._total_nodes

        for cout in range(self._total_nodes):

            # Pick the minimum distance vertex from
            # the set of vertices not yet processed.
            # x is always equal to src in first iteration
            possible = [row for row in dist if dist.index(row) not in sptSet]
            x = self.minDistance(dist, sptSet)

            # Put the minimum distance vertex in the
            # shortest path tree
            sptSet[x] = True

            # Update dist value of the adjacent vertices
            # of the picked vertex only if the current
            # distance is greater than new distance and
            # the vertex in not in the shortest path tree
            for y in range(self._total_nodes):
                if self._adjaceny_matrix[x][y] > 0 and sptSet[y] == False and \
                        dist[y] > dist[x] + self._adjaceny_matrix[x][y]:
                    dist[y] = dist[x] + self._adjaceny_matrix[x][y]

        self.pretty_print(dist)
