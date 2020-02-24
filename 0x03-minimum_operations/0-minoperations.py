#!/usr/bin/python3
"""calculates the fewest number of operations needed"""


def isPrime(num):
    """check if the number is prime"""
    if num <= 2:
        return True
    value = 0
    for i in range(1, num + 1):
        if num % i == 0:
            value += 1
            if value > 2:
                return False
    return True


def primeDescompose(x):
    """descompose x into a primes"""
    val = x
    primes = []
    for i in range(2, x + 1):
        if isPrime(i):
            if x % i == 0:
                while x % i == 0:
                    x = x / i
                    primes.append(i)
            else:
                pass
    return primes


def minOperations(n):
    """minimum of operation"""
    if n <= 0:
        return 0
    if type(n) is not int:
        return 0
    if isPrime(n):
        return n
    list_primes = primeDescompose(n)
    return sum(list_primes)
