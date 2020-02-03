#!/usr/bin/python3
""" checking if all boxes in the list of list can be opened """


def checkingBoxes(box, boxes, pos_checked):
    """ Passing thought all elements in a box """
    if len(box) > 0:
        for elem in box:
            if elem not in pos_checked:
                if elem < len(boxes):
                    pos_checked.append(elem)
                    checkingBoxes(boxes[elem], boxes, pos_checked)
                else:
                    return False
            else:
                pass
        return
    else:
        return


def canUnlockAll(boxes):
    """ Checking of all boxes can be opened.
    return: True or False """
    pos_checked = [0]
    position = [x for x in range(len(boxes))]
    if len(boxes) is 1:
        return True
    value = checkingBoxes(boxes[0], boxes, pos_checked)
    if value is False:
        return False
    else:
        return (all(elem in pos_checked for elem in position))
