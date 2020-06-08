#!/usr/bin/python3
""" calculate how much water will be retained after it rains
"""


def save_position(walls, num, i):
    """ find the max num next to the num, prev position in the array

    Arg:
        - walls: array, list to find the next max number
        - num: initial number in the array to compare
        - i: is the position of num in the array

    Return:
        - max: is the next maximum number in the array compare with num
        - j: indice: walls[j], position in the array of the max
    """
    max = walls[i+1]
    # Traverse array elements from second
    # and compare every element with curr max
    for j in range(i+1, len(walls)):
        if walls[j] >= num:
            max = walls[j]
            break
    return (max, j)


def rain(walls):
    """ calculate how much water will be retained after it rains.

    Arg:
        - walls: is a list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.
    """
    if walls is None:
        return 0

    # prev, pos_prev = save_position(walls, walls[0], 0)
    final_water_retain = 0
    for i in range(len(walls)):
        if walls[i] == 0 and i == 0:
            while (walls[i] == 0):
                i += 1
                if (i+1) == len(walls):
                    return 0
                prev, pos_prev = walls[i], i
        if walls[0] != 0:
            prev, pos_prev = walls[0], 0
        last, pos_last = save_position(walls, prev, pos_prev)
        if prev < last:
            water_retain = prev * (abs(pos_prev - pos_last) - 1)
        else:
            water_retain = last * (abs(pos_prev - pos_last) - 1)
        while (((pos_prev+1) - (pos_last)) != 0):
            water_retain = water_retain - walls[pos_prev+1]
            pos_prev += 1
        final_water_retain += water_retain
        water_retain = 0
        if (pos_last+1) == len(walls):
            break
        prev, pos_prev = last, pos_last

    return final_water_retain
