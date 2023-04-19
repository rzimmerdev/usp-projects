import numpy as np

from linear_system_direct import lu_decomp as lu, inv, gauss_elimination as solve


def to_float(function):
    def converted(*args):
        return function(*[np.array(arg, dtype=np.float64) for arg in args])

    return converted


def abs_error(a, b):
    return np.linalg.norm(b - a)


def MAE(a, b):  # Mean Absolute Error
    return np.linalg.norm(b - a) / np.linalg.norm(b)


@to_float
def gauss_jacobi(A, b, eps=1e-8):
    x0 = np.zeros_like(b)
    n = len(A)
    k = min(1e4, eps ** -1)

    D = np.diag(np.diag(A))
    C = np.eye(n) - solve(D, A)
    g = solve(D, b)

    while abs_error(np.dot(A, x0), b) > eps and k >= 0:
        x0 = np.dot(C, x0) + g
        k -= 1

    if k == 0:
        return ValueError("Solution is not convergent")

    return x0


def converges(A, axis=1):
    a = np.zeros(len(A))
    a_kk = np.diag(A)

    a[:] = abs(A).sum(axis=axis) / abs(a_kk) - 1

    return np.max(a) < 1


@to_float
def gauss_seidel(A, b, eps=1e-8):
    L, R = np.tril(A), np.triu(A, 1)
    x0 = np.zeros_like(b)

    C = -np.linalg.solve(L, R)
    g = solve(L, b)

    k = min(1e6, eps ** -1)

    while abs_error(np.dot(A, x0), b) > eps and k >= 0:
        x0 = np.matmul(C, x0) + g

        k -= 1

    if k == 0:
        return ValueError("Solution is not convergent")

    return x0


def gauss_seidel2(A, b):
    x0 = np.zeros(len(A))
    tol = 1e-8
    L = np.tril(A)
    R = np.triu(A, 1)
    C = -np.linalg.solve(L, R)
    g = np.linalg.solve(L, b)
    kmax = 10000
    k = 0

    error = np.zeros(kmax)

    while np.linalg.norm(b - A.dot(x0)) > tol and k < kmax:
        error[k] = np.linalg.norm(b - A.dot(x0))
        k = k + 1
        x0 = C.dot(x0) + g

    if k == kmax:
        print('\nErro: o método não converge.\n')

    x = x0
    return x


if __name__ == "__main__":
    A_non = np.array([
        [2, 0, 1],
        [4, 3, 7],
        [6, 6, 16]
    ])

    b_non = np.array([2, 1, 4]).T

    A = np.array([
        [-8, 1, 1],
        [1, -5, 1],
        [1, 1, -4]
    ])
    b = np.array([1, 16, 7]).T

    x = gauss_jacobi(A, b)
    x_fast = gauss_seidel(A, b)
    x = gauss_seidel2(A, b)
    print(x, np.linalg.solve(A, b))

    print(converges(A))
    print(converges(A_non))
