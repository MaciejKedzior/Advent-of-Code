# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 21:15:54 2019
Advent of Code Day 6
@author: Dabutsu
"""
with open("day6.txt") as data:
    commands = [i.rstrip().split(" ") for i in data]

for i in range(len(commands)):
    temp = []
    if len(commands[i]) == 4:
        temp.append(commands[i][0])
        temp.append(tuple(commands[i][1].split(",")))
        temp.append(tuple(commands[i][3].split(",")))
    else:
        temp.append(commands[i][1])
        temp.append(tuple(commands[i][2].split(",")))
        temp.append(tuple(commands[i][4].split(",")))
    commands[i] = temp

tab = [[0 for i in range(1000)] for i in range(1000)]

def change_lights(arr: list, comm: str, beg: tuple, end: tuple) -> None:
    for i in range(int(beg[0]), int(end[0])+1):
        for j in range(int(beg[1]), int(end[1])+1):
            if comm == "toggle":
                if arr[i][j] == 0:
                    arr[i][j] = 1
                else: 
                    arr[i][j] = 0
            elif comm == "off":
                if arr[i][j] == 0:
                    continue
                else:
                    arr[i][j] = 0
            elif comm == "on":
                if arr[i][j] == 1:
                    continue
                else:
                    arr[i][j] = 1
            else:
                print("poop happens")
                
def change_lights_bright(arr: list, comm: str, beg: tuple, end: tuple) -> None:
    for i in range(int(beg[0]), int(end[0])+1):
        for j in range(int(beg[1]), int(end[1])+1):
            if comm == "toggle":
                arr[i][j] += 2
            elif comm == "off":
                if arr[i][j] == 0:
                    continue
                else:
                    arr[i][j] -= 1
            elif comm == "on":
                arr[i][j] += 1
            else:
                print("poop happens")
                
def main_one(arr: list) -> int:
    for i in range(len(arr)):
        print(arr[i][0], arr[i][1], arr[i][2])
        change_lights(tab, arr[i][0], arr[i][1], arr[i][2])
    return 0
        
def main_two(arr: list) -> int:
    for i in range(len(arr)):
        change_lights_bright(tab, arr[i][0], arr[i][1], arr[i][2])
    return 0


if __name__ == "__main__":
    main_one(commands)
    main_two(commands)
    counter = 0
    for i in tab:
        counter += sum(i)
