#!/usr/bin/python3
"""calculates the fewest number of operations needed"""


def minOperations(n):
    """minimum of operation"""
    if n < 2 or type(n) is not int:
        return 0
    descompose = []
    for i in range(2, n + 1):
        if n % i == 0:
            while n % i == 0 and n != 1:
                n = n / i
                descompose.append(i)
    return sum(descompose)
