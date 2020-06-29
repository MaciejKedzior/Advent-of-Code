# -*- coding: utf-8 -*-
"""
Created on Thu Aug 15 19:50:28 2019
Advent of Code 2015 Day 10
@author: Dabutsu
"""
from itertools import groupby

data = "1113222113"
test = "1"
  
    
def count(word: str, ture=0):
    temp = ""
    if ture == 50:
        return word
    for k, v in groupby(word):
        temp += str(len(list(v))) + str(k)
    return count(temp, ture+1)

app = count(data)
print(len(app))
