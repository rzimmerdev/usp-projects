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

        adjacency = [list() for _ in range(total_nodes)]
        for edge in edges:
            edge = edge.split(" ")
            if not (edge[0].isdigit() and edge[1].isdigit()):
                continue
            adjacency[int(edge[0]) - 1].append(int(edge[1]) - 1)
            if graph_type == "*Edges":
                adjacency[int(edge[1]) - 1].append(int(edge[0]) - 1)
        return total_nodes, adjacency

    def dfs(self, current, visited):
        """Traverses all connected nodes relative to current node, in depth first order, given a list keeping track
        of all nodes already visited inside the graph. An optional parameter can be given to keep track of all nodes
        traversed during dfs, which correspond to all nodes connected to the relative current node.

        Args:
            current: Root node from which to start recursive depth first search.
            visited: List of all nodes already visited during previous or future calls of the DFS function.
        """
        if visited[current]:
            return True
        visited[current] = True
        for adjacent in self.adjacency[current]:
            return self.dfs(adjacent, visited)
        return False

    def verify_cycle(self):
        for node, adjacent in enumerate(self.adjacency):
            visited = [False for _ in range(self.total_nodes)]
            if self.dfs(node, visited):
                return True
        return False


def main():
    input_file = input()

    file = open(input_file)
    graph = Graph(file)
    file.close()

    print("S" if graph.verify_cycle() else "N")


if __name__ == "__main__":
    main()
