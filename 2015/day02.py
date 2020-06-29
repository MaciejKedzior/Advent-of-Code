# -*- coding: utf-8 -*-
"""
Created on Sat Aug  3 23:20:40 2019
Advent Code 2015 day 2
@author: Dabutsu
"""


with open("day2.txt") as data:
    tabelka = [i.rstrip() for i in data]

for i in range(len(tabelka)):
    tabelka[i] = tabelka[i].split("x")

for j in range(len(tabelka)):
    for k in range(len(tabelka[j])):
        tabelka[j][k] = int(tabelka[j][k])


def present_ribbon(length: int, width: int, height: int):
    sort_dim = sorted([length, width, height])
    return 2 * sort_dim[0] + 2 * sort_dim[1] + length * width * height
   
    
def present_surface(length: int, width: int, height: int) -> int:
    return 2*length*width + 2*width*height + 2*length*height + min((length*width, width*height, length*height))


def whole_surface(tab: list) -> int:
    result = 0
    for i in tab:
        print(i)
        result += present_surface(i[0], i[1], i[2])
    return result


def whole_surface_ribbon(tab: list) -> int:
    result = 0
    for i in tab:
        print(i)
        result += present_ribbon(i[0], i[1], i[2])
    return result


if __name__ == "__main__":
    print(whole_surface(tabelka))
    print(whole_surface_ribbon(tabelka))