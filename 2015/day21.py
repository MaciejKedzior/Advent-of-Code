# -*- coding: utf-8 -*-
"""
Created on Fri Oct  4 13:29:43 2019
Advent of Code 2015 Day 21
@author: Dabutsu
"""
import re

def new_dict(arr: list) -> dict:
    temp = {}
    for i in range(0, len(arr), 4):
        temp[arr[i]] = dict()
        temp[arr[i]]["Cost"] = arr[i+1]
        temp[arr[i]]["Damage"] = arr[i+2]
        temp[arr[i]]["Armor"] = arr[i+3]
    return temp

def new_player(arr: list) -> dict:
    temp = {"Health": 0, "Damage": 0, "Armor": 0}
    for i in range(len(arr)):
        temp[arr[i]]
    
    
    
weapons = new_dict(re.findall(r'\w+', open("day21_w.txt").read()))
armors = new_dict(re.findall(r'\w+', open("day21_a.txt").read()))
rings = new_dict(re.findall(r'\S+', open("day21_r.txt").read()))


