# -*- coding: utf-8 -*-
"""
Created on Thu Sep 26 23:12:52 2019
Advent of Code 2015 Day 20
@author: Dabutsu
"""
'''
drugie podejscie - nie dziala xd
'''


input_val = 34000000
elves = {}
houses = {}

def presents(elf_number: int) -> int:
    return elf_number * 10

def adding_elves(beg: int, end: int):
    for i in range(beg, end):
        elves[i] = [i for i in range(i, end, i)]
    
def adding_houses(beg: int, end: int):
    for i in range(beg, end):
        houses[i] = 0

def elves_iter() -> int:
    for i in elves:
        for j in elves[i]:
            houses[j] += presents(i)  
    for i in houses:
        if houses[i] >= input_val:
            return i, input_val
    else:
        adding_houses(len(houses)+1, len(houses)+100)
        adding_elves(len(elves)+1, len(elves)+100)
        return 0,0
        
adding_elves(1, 10)
adding_houses(1, 10)
elves_iter()

while True:
    a = elves_iter()
    if a[1] == input_val:
        print(a)
        break
