#!/usr/bin/python3
""" checking if all boxes in the list of list can be opened """


def canUnlockAll(boxes):
    """ determine if all boxes can be opened """
    for key in range(1, len(boxes) - 1):
        res = False
        for index in range(len(boxes)):
            res = key in boxes[index] and key != index
            if res:
                break
        if res is False:
            return res
    return True
