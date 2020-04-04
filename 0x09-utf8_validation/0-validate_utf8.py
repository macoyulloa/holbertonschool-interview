#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8
"""


def validUTF8(data):
    """
    Determines if a data set represents a valid UTF-8
    Return: True if is a valid UTF-8 encoding or False
    """
    for i in range(len(data)):
        if (data[i] >= 256 or data[i] < 0):
            return False
    return True
