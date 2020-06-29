# -*- coding: utf-8 -*-
"""
Created on Sat Sep 28 15:29:13 2019

@author: Dabutsu
"""
from collections import defaultdict

target = 34000000

def part1(upperBound):
    houses = defaultdict(int)

    for elf in range(1, target):
        for house in range(elf, upperBound, elf):
            houses[house] += elf*10
            
        if houses[elf] >= target:
            return elf

def part2(upperBound):
    houses = defaultdict(int)

    for elf in range(1, target):
        for house in range(elf, min(elf*50+1, upperBound), elf):
            houses[house] += elf*11
            
        if houses[elf] >= target:
            return elf

            
a = part1(1000000)
b = part2(1000000)