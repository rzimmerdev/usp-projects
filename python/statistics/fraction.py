import math


def divides(n, d):
    return not n % d


def swap(n, x, y):
    n[x], n[y] = n[y], n[x]


def partition(n, low, high):
    pivot, id_x = n[high], low

    for i in range(low, high):
        if n[i] <= pivot:
            swap(n, i, id_x)
            id_x += 1

    swap(n, id_x, high)
    return id_x


def quick_sort_recurr(n, low, high):
    if len(n) == 1:
        return n
    if low < high:
        center = partition(n, low, high)
        quick_sort_recurr(n, low, center - 1), quick_sort_recurr(n, center + 1, high)
    return n


def quick_sort(n):
    return quick_sort_recurr(n, 0, len(n) - 1)


def sieve(max_num: int):
    primes = [True for _ in range(2, max_num)]

    for i in range(4, max_num, 2):
        primes[i - 2] = False

    for i in range(3, max_num):
        if not primes[i - 2]:
            continue
        for j in range(i * i, max_num, i):
            primes[j - 2] = False
    return primes


def factorate(num: int, cache: list = None):
    if not cache:
        cache = sieve(int(num / 2) + 1)

    factors = list()

    while num != 1:
        for prime, i in enumerate(cache):
            if num % (prime + 2):
                continue
            while not num % (prime + 2):
                factors.append(prime + 2)
                num = int(num / (prime + 2))
        if num != 1:
            factors.append(num)
        break

    return factors


def merge(first_list: list, second_list: list, in_place=False):

    if in_place:
        pos = 0
        for num in second_list:
            while pos < len(first_list) and first_list[pos] < num:
                pos += 1
            first_list.insert(pos, num)
    else:
        result = list()
        while first_list or second_list:
            if not first_list:
                result.append(second_list.pop(0))
            elif not second_list:
                result.append(first_list.pop(0))
            elif first_list[0] < second_list[0]:
                result.append(first_list.pop(0))
            else:
                result.append(second_list.pop(0))

        return result


def factor_product(arr: list):
    size = len(arr)
    while size > 1:
        arr[size - 2] = merge(arr[size - 2], arr.pop())
        size -= 1

    return arr[0]


def read_fraction():
    n, d = ([int(x) for x in input().split()] for _ in range(2))
    return frac(n, d)


def binary_search(n: list, val: int):
    low, center, high = 0, 0, len(n) - 1

    while low <= high:
        center = (high + low) // 2

        if n[center] < val:
            low = center + 1
        elif n[center] > val:
            high = center - 1
        else:
            return center

    return center


def insort(n: list, val: int):
    new = n.copy()
    new.insert(binary_search(n, val), val)
    return new


class frac:
    prime_cache = sieve(10000)

    def __init__(self, n: int = None, d: int = 1, composite: tuple = None):
        if n is not None:
            composite = (factorate(n, self.prime_cache), factorate(d, self.prime_cache))
            self.n, self.d = self._simplify(composite)
        else:
            self.n, self.d = self._simplify(composite)

    @staticmethod
    def _simplify(composite: tuple):
        n, d = composite
        id_x, id_y = 0, 0
        size_x, size_y = len(n), len(d)

        result_n, result_d = (list(), list())

        while id_x < size_x or id_y < size_y:
            if id_x >= size_x:
                result_d.append(d[id_y])
                id_y += 1
            elif id_y >= size_y:
                result_n.append(n[id_x])
                id_x += 1
            elif n[id_x] < d[id_y]:
                result_n.append(n[id_x])
                id_x += 1
            elif n[id_x] > d[id_y]:
                result_d.append(d[id_y])
                id_y += 1
            else:
                id_x += 1
                id_y += 1

        return result_n, result_d

    def __mul__(self, other):
        if isinstance(other, frac):
            n = merge(self.n, other.n)
            d = merge(self.d, other.d)
        elif isinstance(other, int):
            n = insort(self.n, other)
            d = self.d
        else:
            n = self.n
            d = self.d

        return frac(composite=(n, d))

    def __add__(self, other):
        if isinstance(other, frac):
            n = math.prod(self.n) * math.prod(other.d) + math.prod(self.d) * math.prod(other.n)
            n = factorate(n, self.prime_cache)
            d = merge(self.d, other.d)
        elif isinstance(other, int):
            n = math.prod(self.n) + math.prod(self.d) * other
            n = factorate(n, self.prime_cache)
            d = self.d
        else:
            n = self.n
            d = self.d

        return frac(composite=(n, d))

    def __sub__(self, other):
        if isinstance(other, frac):
            n = math.prod(self.n) * math.prod(other.d) - math.prod(self.d) * math.prod(other.n)
            n = factorate(n, self.prime_cache)
            d = merge(self.d, other.d)
        elif isinstance(other, int):
            n = math.prod(self.n) - math.prod(self.d) * other
            n = factorate(n, self.prime_cache)
            d = self.d
        else:
            n = self.n
            d = self.d

        return frac(composite=(n, d))

    def __rsub__(self, other):
        if isinstance(other, frac):
            n = -math.prod(self.n) * math.prod(other.d) + math.prod(self.d) * math.prod(other.n)
            n = factorate(n, self.prime_cache)
            d = merge(self.d, other.d)
        elif isinstance(other, int):
            n = -math.prod(self.n) + math.prod(self.d) * other
            n = factorate(n, self.prime_cache)
            d = self.d
        else:
            n = self.n
            d = self.d

        return frac(composite=(n, d))

    def __truediv__(self, other):
        if isinstance(other, frac):
            n = merge(self.n, other.d)
            d = merge(self.d, other.n)
        elif isinstance(other, int):
            n = self.n
            d = insort(self.d, other)
        else:
            n = self.n
            d = self.d
        return frac(composite=(n, d))

    def __rtruediv__(self, other):
        if isinstance(other, frac):
            n = merge(self.d, other.n)
            d = merge(self.n, other.d)
        elif isinstance(other, int):
            n = insort(self.d, other)
            d = self.n
        else:
            n = self.n
            d = self.d
        return frac(composite=(n, d))

    __rmul__ = __mul__
    __radd__ = __add__

    def __lt__(self, other):
        value = self.__float__()

        if isinstance(other, frac):
            return value < other.__float__()
        else:
            return value < other

    def __le__(self, other):
        value = self.__float__()

        if isinstance(other, frac):
            return value <= other.__float__()
        else:
            return value <= other

    def __gt__(self, other):
        value = self.__float__()

        if isinstance(other, frac):
            return value > other.__float__()
        else:
            return value > other

    def __ge__(self, other):
        value = self.__float__()

        if isinstance(other, frac):
            return value >= other.__float__()
        else:
            return value >= other

    def __str__(self):
        if not self.d or (len(self.d) == 1 and self.d[0] == 1):
            return str(math.prod(self.n))
        else:
            return f"{math.prod(self.n)}/{math.prod(self.d)}"

    def __float__(self):
        return math.prod(self.n)/math.prod(self.d)


def factor_pow(factors: list, x: int):
    result = list()
    for num in factors:
        for jmp in range(x):
            result.append(num)
    return result


def frac_pow(p, x: int):
    if isinstance(p, frac):
        n = factor_pow(p.n, x)
        d = factor_pow(p.d, x)

        return frac(composite=(n, d))
    else:
        return pow(p, x)


class arrange(list):
    factors_cache = list()
    prime_cache = sieve(10000)

    def __init__(self, n: int, p: int = 0):
        super().__init__()
        for num in range(1, n - p + 1):
            merge(self, factorate(num, self.prime_cache), True)

    def __str__(self):
        return str(math.prod(self))
