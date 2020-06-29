# -*- coding: utf-8 -*-
"""
Created on Wed Aug 14 23:46:28 2019
Advent of Code 2015 Day 9
@author: Dabutsu
"""
from itertools import permutations
from re import split


def splitting(word: str) -> list:
    temp = split(r'(\w+)\sto\s(\w+)\s=\s(\d+)', word)
    temp.remove(temp[0])
    temp.remove(temp[-1])
    return temp

def new_graph(tab: list) -> dict:
    graph = {}
    for i in tab:
        if i[0] not in graph:
            graph[i[0]] = {}
        if i[1] not in graph[i[0]]:
            graph[i[0]][i[1]] = int(i[2])
    return graph
    
def length(tab: tuple) -> int:
    value = 0
    for i in range(len(tab)-1):
        if len(tab[i]) != 0:
            if tab[i+1] in poss[tab[i]]:
                value += poss[tab[i]][tab[i+1]]
            else:
                value += poss[tab[i+1]][tab[i]]
        else:
           value += poss[tab[i+1]][tab[i]] 

    return value

def main(tab: list) -> int:
    mini = 0    #OR MAXI IN THE SECOND PART
    for i in range(len(tab)):
        if i == 0:
            mini = length(tab[i])
        else:
            temp = length(tab[i])
            if temp < mini:
                mini = temp
    return mini


if __name__ == "__main__":
    with open("day9.txt") as data:
        array = [splitting(i.rstrip()) for i in data]
         
    poss = new_graph(array)
    poss["Arbre"] = {}
    n = list(permutations(poss.keys()))
    print(main(n))