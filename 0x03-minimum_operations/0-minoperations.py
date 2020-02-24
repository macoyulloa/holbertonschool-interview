#!/usr/bin/python3
"""calculates the fewest number of operations needed"""


def minOperations(n):
    """minimum of operation"""
    if n < 2 or type(n) is not int:
        return 0
    descompose = []
    for i in range(2, n + 1):
        if n % i == 0:
            while n % i == 0:
                n = n / i
                descompose.append(i)
        else:
            pass
    return sum(descompose)
