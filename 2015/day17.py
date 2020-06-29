# -*- coding: utf-8 -*-
"""
Created on Sun Sep 22 13:53:25 2019
Advent of Code 2015 Day 17
@author: Dabutsu
"""

from itertools import combinations


def number_of_poss_ex1(containers: list, value: int) -> int:
    return len([list(x) for i in range(1, len(containers)) for x in combinations(containers, i) if sum(list(x)) == value])
      
def number_of_poss_ex2(containers: list, value: int) -> int:
    poss = [list(x) for i in range(1, len(containers)) for x in combinations(containers, i) if sum(list(x)) == value]
    mini = len(min(poss, key=len))
    return len(list(map(tuple, filter(lambda x: len(x) == mini, poss))))


if __name__ == "__main__":
    kubki = list(map(int, [i.rstrip() for i in open("day17.txt").readlines()]))
    ilosc = 150
    print(number_of_poss_ex1(kubki, ilosc), number_of_poss_ex2(kubki, ilosc))
    