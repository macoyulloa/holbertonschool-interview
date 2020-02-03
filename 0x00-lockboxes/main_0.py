#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [3]]
print(canUnlockAll(boxes))

print("Debe ser falso")
boxes = [[1], [1], [3]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [5, 6]]
print(canUnlockAll(boxes))
