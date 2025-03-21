import pandas as pd
import sys

with open(sys.argv[1], 'r') as f:
    data = f.readlines()

num_failed = 0
num_attacked = 0
num_exploited = 0

for line in data[1:]:
    if 'exploited' in line:
        num_exploited += 1
    elif 'attacked' in line:
        num_attacked += 1
    else:
        num_failed += 1

print(f'{num_exploited} & {num_attacked} & {num_failed} \\\\')
