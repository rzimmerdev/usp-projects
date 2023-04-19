import sys
import math
from queue import PriorityQueue


def get_digit(number, n):
    return number // 10 ** (n - 1) % 10


def num_fixed(value, fix) -> str:
    if value == 0 or value == -1:
        if fix <= 1:
            return value
        else:
            return " " * (fix - 1 + value) + str(value)

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
    """Graph object containing count for total nodes, as well as adjacency list corresponding to connections
    between two respective nodes.

    Some operations are also available to read connections from a given Pajek file, as
    well as the possibility to count all nodes in existing connected components.

    Attributes:
        total_nodes: Counts all nodes existing inside graph.
        adjacency: Adjacency list containing connections between nodes.
        Connection between ith node and j exists if j is in adjacency[i].
    """
    def __init__(self, file=None):
        if file is None:
            self.total_nodes, self.adjacency = 0, []
        else:
            self.total_nodes, self.adjacency = self.read_pajek(file)

    @staticmethod
    def read_pajek(file):
        """Reads total nodes count and all edges adjacency nodes in sequence, given an input file with the Pajek file
        formatting.

        Args:
            file: Opened file object with desired graph information, formatted as Pajek file.
        Returns:
            total_nodes, adjacency: Returns a tuple with the count of all nodes, as well as a list representing the
            adjacency list of all node connections.
        """
        total_nodes = int(file.readline().split(" ")[1])

        graph_type = file.readline().strip()
        edges = file.read().splitlines()

        weighted = "*Arcs"
        unweighted = "*Edges"

        if graph_type == unweighted:
            adjacency = [[0] * total_nodes for _ in range(total_nodes)]

            for edge in edges:
                edge = edge.split(" ")
                adjacency[int(edge[0]) - 1].append(int(edge[1]) - 1)
                adjacency[int(edge[1]) - 1].append(int(edge[0]) - 1)
        elif graph_type == weighted:
            adjacency = [[-1] * total_nodes for _ in range(total_nodes)]

            for edge in edges:
                edge = edge.split(" ")
                adjacency[int(edge[0]) - 1][int(edge[1]) - 1] = int(edge[2])
        else:
            adjacency = None

        return total_nodes, adjacency

    @staticmethod
    def pretty_print(matrix, total_columns):
        column_max = [0] * total_columns
        for row in matrix:
            for idx, column in enumerate(row):
                if column_max[idx] < column:
                    column_max[idx] = column

        for idx, line in enumerate(matrix):
            for idy, val in enumerate(line):
                fixed_size = math.ceil(math.log10(column_max[idy])) if column_max[idy] > 1 else 1
                print(num_fixed(val if idx != idy else 0, fixed_size),
                      end=" " if idy < total_columns - 1 else "")
            print("\n", end="")

    def dijkstra(self, root):
        distances = [sys.maxsize] * self.total_nodes
        distances[root] = 0

        next_nodes = PriorityQueue()
        next_nodes.put((distances[root], root))

        visited = {}

        while not next_nodes.empty():
            (distance, current_node) = next_nodes.get()

            for adjacent_node in range(self.total_nodes):
                if self.adjacency[current_node][adjacent_node] == -1 or adjacent_node in visited:
                    continue
                distance = self.adjacency[current_node][adjacent_node]
                distance_from_root = distances[current_node] + distance

                if distance_from_root < distances[adjacent_node]:
                    next_nodes.put((distance_from_root, adjacent_node))
                    distances[adjacent_node] = distance_from_root
        return distances

    def distance_matrix(self):
        distances = []

        for node in range(self.total_nodes):
            distances.append(self.dijkstra(node))

        return distances


if __name__ == "__main__":

    pajek_file = open(input())

    graph = Graph(pajek_file)
    graph.pretty_print(graph.distance_matrix(), graph.total_nodes)

