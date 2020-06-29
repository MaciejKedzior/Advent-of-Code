# -*- coding: utf-8 -*-
"""
Created on Fri Sep  6 19:21:29 2019
Advent of Code 2015 Day 15
@author: Dabutsu
"""

import itertools
import re
   

def versions(i=4):
    temp = itertools.combinations_with_replacement(range(0, 101), i)
    for x in temp:
        if sum(x) == 100:
            new = itertools.permutations(x)
            for y in new:
                yield y
   
def total_score(combination: tuple):
    temp = {}
    for i in range(len(names)):
        temp[names[i]] = combination[i]
    statistics = [0, 0, 0, 0]
    calories = 0
    
    for i in names:
        statistics[0] += temp[i] * ingredients[i][0]
        statistics[1] += temp[i] * ingredients[i][1]
        statistics[2] += temp[i] * ingredients[i][2]
        statistics[3] += temp[i] * ingredients[i][3]
        calories += temp[i] * ingredients[i][4]
    statistics = [0 if i < 0 else i for i in statistics]
    
    if 0 in statistics or calories != 500:
        return 0
    
    value = 1
    for i in statistics:
        value *= i
    return value
    
    
    
if __name__ == "__main__":
    info = [list(map(int, re.findall("-?\d+", i))) for i in [i.rstrip() for i in open("day15.txt")]]
    names = [i.split(":")[0] for i in open("day15.txt")]
    
    ingredients = {}
    for i in zip(names, info):
        ingredients[i[0]] = i[1]
    
    max_score = 0
    for i in versions():
        temp = total_score(i)
        if temp > max_score:
            max_score = temp
    print("The biggest score is: %s" %max_score)