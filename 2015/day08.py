# -*- coding: utf-8 -*-
"""
Created on Mon Aug 12 21:10:24 2019
Advent of Code 2015 Day 8
@author: Dabutsu
"""

print (sum(len(s[:-1]) - len(eval(s)) for s in open('day8.txt')))
print (sum(2+s.count('\\')+s.count('"') for s in open('day8.txt')))