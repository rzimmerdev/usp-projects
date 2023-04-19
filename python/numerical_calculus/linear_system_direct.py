import numpy as np


def to_float(function):
    def converted(*args):
        return function(*[np.array(arg, dtype=np.float64) for arg in args])

    return converted


def det(A, U=None):
    if U is not None:
        return np.prod(np.diag(U))

    if not isinstance(A, np.ndarray):
        return A
    elif len(A) == 1:
        return A[0, 0] if isinstance(A[0], np.ndarray) else A[0]
    elif len(A) == 2:
        return A[0, 0] * A[1, 1] - A[0, 1] * A[1, 0]

    out = 0

    for i, row in enumerate(A):
        minor = det(
            np.concatenate((A[0:i, 1:], A[i + 1:, 1:]))
        )

        cofac = A[i, 0] * minor
        out += (-1 if i % 2 else 1) * cofac

    return out


def forward_sub(L, b):
    y = np.zeros_like(b, dtype=np.float32)

    for i in range(len(L)):
        y[i] = (b[i] - np.dot(L[i, :i], y[:i])) / L[i, i]

    return y


def back_sub(U, b):
    x = np.zeros_like(b, dtype=np.float32)

    for i in range(len(U) - 1, -1, -1):
        x[i] = (b[i] - np.dot(U[i, i + 1:], x[i + 1:])) / (U[i, i] if U[i, i] != 0 else 1)

    return x


@to_float
def lu_decomp(A):
    n = len(A)
    L = np.eye(n)
    U = np.copy(A)

    for k in range(n - 1):
        for i in range(k + 1, n):
            L[i, k] = U[i, k] / U[k, k]
            U[i, k:] -= L[i, k] * U[k, k:]

    return L, U


def cholesky_decomp(A):
    n = len(A)
    H = np.zeros_like(A, dtype=np.float32)

    for i in range(n):
        for k in range(i + 1):
            k_sum = sum(H[i][:k] * H[k][:k])

            if i == k:
                H[i][k] = np.sqrt(A[i][i] - k_sum)
            else:
                H[i][k] = (1.0 / H[k][k] * (A[i][k] - k_sum))

    return H


@to_float
def gauss_elimination(A, b):
    n = len(A)
    U = np.copy(A)
    y = np.copy(b)

    for k in range(n - 1):

        p = np.argmax(abs(U[k:, k]))

        U[[k, p]] = U[[p, k]]
        y[[k, p]] = y[[p, k]]

        for i in range(k + 1, n):
            m = -U[i, k] / (U[k, k] if U[k, k] != 0 else 1)
            U[i, k:n] += m * U[k, k:n]
            y[i] += m * y[k]

    return back_sub(U, y)


@to_float
def lup_decomp(A):
    n = len(A)
    P = np.eye(n)
    L = np.eye(n)
    U = np.copy(A)

    for k in range(n - 1):
        p = np.argmax(abs(U[k:, k]))

        P[[k, p], :] = P[[p, k], :]
        U[[k, p], k:] = U[[p, k], k:]
        L[[k, p], :k] = L[[p, k], :k]

        for i in range(k + 1, n):
            L[i, k] = U[i, k] / U[k, k]
            U[i, k + 1:] -= L[i, k] * U[k, k + 1:]
            U[i, k] = 0

    return L, U, P


def lup_solve(A, b):
    L, U, P = lup_decomp(A)

    b_pivoted = P.dot(b)
    y_pivoted = forward_sub(L, b_pivoted)
    x_pivoted = back_sub(U, y_pivoted)

    return x_pivoted


def inv(A):
    I = np.eye(len(A))
    A_inv = np.zeros_like(A, dtype=np.float32)

    for idx, i in enumerate(I):
        A_inv[idx] = gauss_elimination(A, i)

    if np.isnan(np.min(A_inv)):
        return A

    return A_inv


def main(A, b):
    print("A * x = b")
    print("A: \n", A)
    print("b: \n", b, "\n\n")

    L, U = lu_decomp(A)

    print("A = L * U")
    print("L: \n", L)
    print("U: \n", U)
    print("L @ U: \n", L @ U, "\n\n")

    print("det(A) via L * U: ")
    print(det(A, U), "\n")

    print("Solving for x: ")

    y = forward_sub(L, b)
    x = back_sub(U, y)

    print(x)

    print("\nGauss Elimination for A, b:")
    print(gauss_elimination(A, b))

    print("\n")
    L, U, P = lup_decomp(A)

    print(np.matmul(L, U))
    print("X after pivoting:", lup_solve(A, b))

    print("Calculo da inversa de A:")
    print(inv(A))


if __name__ == "__main__":
    A1 = np.array([
        [2, 0, 1],
        [4, 3, 7],
        [6, 6, 16]
    ])

    b1 = np.array([2, 1, 4]).T

    main(A1, b1)

    A2 = np.array([
        [-8, 1, 1],
        [1, -5, 1],
        [1, 1, -4]
    ])

    b2 = np.array([1, 16, 7])

    main(A2, b2)

    A_spd = np.array([
        [3, 2, 0],
        [2, 5, 1],
        [0, 1, 3]
    ])

    print("Cholesky-Decomposition of Hermitian matrix: \n")

    H = cholesky_decomp(A_spd)

    print(np.matmul(H, H.T))
