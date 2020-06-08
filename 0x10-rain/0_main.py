#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 0, 0, 0]
    print("must be 0")
    print(rain(walls))

    walls = [0, 0, 0, 2]
    print("must be 0")
    print(rain(walls))

    walls = [0, 4, 0, 0]
    print("must be 0")
    print(rain(walls))

    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print("must be 6")
    print(rain(walls))

    walls1 = [2, 0, 2]
    print("must be 2")
    print(rain(walls1))

    walls2 = [3, 0, 2, 0, 4]
    print("must be 7")
    print(rain(walls2))

    walls3 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print("must be 6")
    print(rain(walls3))
