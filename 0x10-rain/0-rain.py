#!/usr/bin/python3
""" calculate how much water will be retained after it rains
"""


def maxWater(arr, n):
    """
    """
    # To store the maximum water
    # that can be stored
    max_water = 0

    # For every element of the array
    for i in range(1, n - 1):
        # Find the maximum element on its left
        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])

        # Find the maximum element on its right
        right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        # Update the maximum water
        max_water = max_water + (min(left, right) - arr[i])

    return max_water


def rain(walls):
    """ calculate how much water will be retained after it rains.

    Arg:
        - walls: is a list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.
    """
    water_retained = maxWater(walls, len(walls))
    return water_retained
