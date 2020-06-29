# -*- coding: utf-8 -*-
"""
Created on Sun Aug  4 00:04:06 2019
Advent of Code 2015 day 3
@author: Dabutsu
"""
class Santa:
    def __init__(self):
        self.counter = {}
        self.current_coord = [0, 0]
        self.counter.setdefault(tuple(self.current_coord), 1)
        self.number = 0
 
    def change(self, sign: str):
        if sign == "<":
            self.current_coord[0] -= 1
        elif sign == ">":
            self.current_coord[0] += 1
        elif sign == "^":
            self.current_coord[1] += 1
        elif sign == "v":
            self.current_coord[1] -= 1
        else:
            print("ERROR IN LINE")
    
    def move(self, sign: str) -> int:
        self.change(sign)
        if tuple(self.current_coord) not in self.counter:
            self.counter.setdefault(tuple(self.current_coord), 0)
            self.counter[tuple(self.current_coord)] += 1
    
    def houses_visited(self) -> int:
        for i in self.counter:
            if self.counter[i] >= 1:
                self.number += 1
        return self.number    

  
with open("day3-2.txt") as data:
    tabelka = [j for i in data for j in i]
    
def execution(tab: list) -> int:    
    santa = Santa()
    robo_santa = Santa()
    for i in range(len(tab)):
        if i % 2 == 0:
            santa.move(tab[i])
        else:
            robo_santa.move(tab[i])
    return len(set(santa.counter).union(set(robo_santa.counter)))


if __name__ == "__main__":
    temp = ["^", "v", "^", "v", "^", "v", "^", "v", "^", "v"]
    print(execution(tabelka))
