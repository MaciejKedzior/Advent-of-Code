# -*- coding: utf-8 -*-
"""
Created on Fri Sep  6 21:28:01 2019

@author: Dabutsu
"""

import re

def igscore(ig, ms, k): return max(sum([ing[k] * m for ing, m in zip(ig, ms)]), 0)
def score(ig, m): return igscore(ig, m, "cap") * igscore(ig, m, "dur") * igscore(ig, m, "flav") * igscore(ig, m, "text")

def find_max_score(ingredients, current, mass, remaining_weight):
    if current == len(ingredients)-1:
        mass[current] = remaining_weight
        if igscore(ingredients, mass, "cal") != 500: return 0
        return score(ingredients, mass)

    best_score = 0
    for m in range(1, remaining_weight):
        mass[current] = m
        best_score = max(best_score, find_max_score(ingredients,
                                                    current+1,
                                                    mass,
                                                    remaining_weight-m))

    return best_score

ingredients = []
with open('day15.txt', 'r') as fh:
    p = re.compile(r'^([A-Za-z]+): capacity (-?[0-9]+), durability (-?[0-9]+), flavor (-?[0-9]+), texture (-?[0-9]+), calories (-?[0-9]+)$')
    for l in fh:
        name, cap, dur, flav, text, cal = p.findall(l.strip())[0]
        ingredients.append({"name": name, "cap": int(cap), "dur": int(dur), "flav": int(flav), "text": int(text), "cal": int(cal)})

print(find_max_score(ingredients, 0, [0]*len(ingredients), 100))