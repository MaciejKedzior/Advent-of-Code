# -*- coding: utf-8 -*-
"""
Created on Mon Aug 26 10:14:48 2019
Advent of Code 2015 Day 14
@author: Dabutsu
"""

import re


def part1(stats: tuple, time=1000) -> int:
    travel = int(stats[2])
    rest = int(stats[3])
    speed = int(stats[1])
    q, r = divmod(time, travel + rest)
    distance = (q*travel + min(r, travel)) * speed
    return distance
    


if __name__ == "__main__":
    seconds = 2503
    reindeer_stats = re.findall(r'(\w+) can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds.', open("day14.txt").read())
    part_one = [part1(i, seconds) for i in reindeer_stats]
