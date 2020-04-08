#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8
"""


def validUTF8(data):
    """
    Determines if a data set represents a valid UTF-8
    UTF could be until 4 bytes, managing them as UTF encode
    Return: True if is a valid UTF-8 encoding or False
    """
    validation = False
    continue_flag = 0

    for element in data:

        byte = format(element, '#010b')[-8:]
        if continue_flag == 0:
            if byte[0] == '1':
                continue_flag = len(byte.split('0')[0])
            if continue_flag > 4 or continue_flag == 1:
                return False
            if continue_flag == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
            continue_flag = continue_flag - 1

    if continue_flag == 0:
        return True
    return validation
