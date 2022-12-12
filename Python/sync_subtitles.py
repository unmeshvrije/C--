#!/usr/bin/env python3

from datetime import datetime, timedelta
import sys

input_file = sys.argv[1]
output_file = sys.argv[2]

TIME_JUMP_IN_SECONDS = int(sys.argv[3])

with open(input_file) as src, open(output_file, 'w') as dest:
    for line in src:
        line = line.strip()
        if "-->" not in line:
             print(line, file=dest)
             continue
        ts_from, ts_to = line.split(' --> ')
        ts_from = datetime.strptime(ts_from, '%H:%M:%S.%f')
        ts_to = datetime.strptime(ts_to, '%H:%M:%S.%f')

        ts_from_new = (ts_from - timedelta(seconds=TIME_JUMP_IN_SECONDS)).strftime('%H:%M:%S.%f')[:-3]
        ts_to_new = (ts_to - timedelta(seconds=TIME_JUMP_IN_SECONDS)).strftime('%H:%M:%S.%f')[:-3]
        new_line = f'{ts_from_new} --> {ts_to_new}'
        print(new_line, file=dest)
