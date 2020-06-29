# -*- coding: utf-8 -*-
"""
Created on Sun Aug 25 21:55:01 2019
Advent of Code 2015 Day 13
@author: Dabutsu
"""
from itertools import permutations

def proper_data(tab: list):
    new = []
    for i in tab:
        temp = []
        for j in i:
            if j.capitalize() == j:
                if "gain" in i and j.isdecimal():
                    temp.append(j)
                elif "lose" in i and j.isdecimal():
                    temp.append(str(-1*int(j)))
                else:
                    temp.append(j)
        new.append(temp)
    return new

def new_graph(tab: list) -> dict:
    graph = {}
    for i in tab:
        if i[0] not in graph:
            graph[i[0]] = {}
        if i[1] not in graph[i[0]]:
            graph[i[0]][i[2]] = int(i[1])
    return graph

def sum_of_happines(tab: list, graph: dict) -> int:
    value = 0
    for i in range(len(tab)):
        if i == 0:
            #print(tab[0], "sits next to", tab[-1], graph[tab[0]][tab[-1]])
            #print("and", tab[1], graph[tab[0]][tab[1]])
            value += graph[tab[0]][tab[-1]] + graph[tab[0]][tab[1]]
        elif i != 0 and i != len(tab)-1:
            #print(tab[i], "sits next to", tab[i-1], graph[tab[i]][tab[i-1]])
            #print("and", tab[i+1], graph[tab[i]][tab[i+1]])
            value += graph[tab[i]][tab[i+1]] + graph[tab[i]][tab[i-1]]
        else:
            #print(tab[-1], "sits next to", tab[-2], graph[tab[-1]][tab[-2]])
            #print("and", tab[0], "but I don't count her")
            value += graph[tab[-1]][tab[-2]] + graph[tab[-1]][tab[0]]
    return value


if __name__ == "__main__":
    people_one = new_graph(proper_data([i.rstrip(".\n").split(" ") for i in open("day13_part1.txt")]))
    people_two = new_graph(proper_data([i.rstrip(".\n").split(" ") for i in open("day13_part2.txt")]))

    cases_one = list(permutations(people_one.keys()))
    cases_two = list(permutations(people_two.keys()))

    result_one = max([sum_of_happines(i, people_one) for i in cases_one])
    result_two = max([sum_of_happines(i, people_two) for i in cases_two])

    print("Part 1:", result_one)
    print("Part 2:", result_two)