# Author: Ignazio Leonardo Calogero Sperandeo
# Date: 2026-06-01
# Project Delivery: Ref. README.md
# by jimbug // :)

q, n = map(int, input().split())

right_sequence = input().strip()

for _ in range(n):
    sequence = input().strip()
    print(sum([a == b for a, b in zip(right_sequence, sequence)]))
