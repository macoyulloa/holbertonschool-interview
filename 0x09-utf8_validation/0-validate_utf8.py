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
    n_bytes_utf = 0

    for byte in data:
        byte = format(byte, '#010b')[-8:]

        if n_bytes_utf == 0:
            if byte[0] == '1':
                n_bytes_utf = len(byte.split('0')[0])
            if n_bytes_utf > 4 or n_bytes_utf == 1:
                return False
            if n_bytes_utf == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
            n_bytes_utf -= 1

    if n_bytes_utf == 0:
        return True
    return False
