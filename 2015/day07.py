# -*- coding: utf-8 -*-
"""
Created on Fri Aug  9 20:47:31 2019
Advent of Code 2015 Day 7
@author: Dabutsu
"""

gates = {}
results = {}
with open("day7.txt") as data:
    for i in data:
        gates[i.split(" -> ")[1].rstrip()] = i.rstrip().split(" -> ")[0].split(" ")

#gates["b"] = ['956'] for the 2nd part only
def get_value(key):
    print("Now it is %s key!" %key)
    try:
        return int(key)
    except ValueError:
        pass
    
    if key not in results:
        command = gates[key]
        if "NOT" in command:
            res = 0xffff - get_value(command[1])
        elif "AND" in command:
            res = get_value(command[0]) & get_value(command[2])
        elif "OR" in command:
            res = get_value(command[0]) | get_value(command[2])
        elif "RSHIFT" in command:
            res = get_value(command[0]) >> get_value(command[2])
        elif "LSHIFT" in command:
            res = get_value(command[0]) << get_value(command[2])
        else:
            res = get_value(command[0])
        results[key] = res
    return results[key]
    
    
print(get_value("a"))
