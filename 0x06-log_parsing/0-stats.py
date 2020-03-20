#!/usr/bin/python3
"""reads stdin line by line and computes metrics"""
import sys


total_size = 0
status_list = ['200', '301', '400', '401', '403', '404', '405', '500']
counter_status = [0, 0, 0, 0, 0, 0, 0, 0]
count = 0

for std_line in sys.stdin:
    line_sep = std_line.split(" ")
    size = line_sep[-1]
    status = line_sep[-2]
    if status in status_list:
        j = status_list.index(status)
        counter_status[j] += 1
        total_size += int(size)
        count += 1
    if count == 10:
        print("File size: {:d}".format(total_size))
        for i in range(len(status_list)):
            if counter_status[i] != 0:
                print("{:}: {:d}".format(status_list[i], counter_status[i]))
        count = 0
