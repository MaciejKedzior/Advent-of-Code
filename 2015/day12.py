# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 20:49:06 2019
Advent of Code 2015 Day 12
@author: Dabutsu
"""

import json
import re


def part_one():
    return sum(map(int, re.findall(r"-?[0-9]+", [i.rstrip() for i in open("day12.txt")][0])))


def part_two():
    with open("day12.json") as data1:
        second_list = json.load(data1)
        
    def sum_of_all(obj):
        if type(obj) == int:
            return obj
        if type(obj) == list:
            return sum([sum_of_all(i) for i in obj])
        if type(obj) != dict:
            return 0
        if "red" in obj.values():
            return 0
        return sum_of_all(list(obj.values()))
    
    return sum_of_all(second_list)

print(part_one())
print(part_two())