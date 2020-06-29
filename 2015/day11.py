# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 15:26:23 2019
Advent of Code 2015 Day 11
@author: Dabutsu
"""

def asc_series(arr: str) -> bool:
    for i in range(len(arr)-2):
        if ord(arr[i]) == ord(arr[i+1])-1 == ord(arr[i+2])-2:
            return True
    return False


def banned_letters(word: str) -> bool:
    return len(set(word).intersection(set(['i', 'o', 'l']))) == 0


def two_pairs(word: str) -> bool:
    counter = 0
    i = 0
    while i < len(word)-1:
        if word[i] == word[i+1]:
            counter += 1
            i += 1
        i += 1
    return counter == 2


def increment(word: str) -> str:
    temp = [ord(i) for i in word]
    for i in range(len(temp)):
        if temp[-1-i] > 122:
            temp[-1-i] = ord("a")
            if i == len(temp)-1:
                break
            else:
                temp[-1-i-1] += 1
        else:
            if i == 0:
                temp[-1-i] += 1
    return "".join([chr(x) for x in temp])


def main(temp: str) -> str:
    i = 0
    while True:
        if asc_series(temp) and banned_letters(temp) and two_pairs(temp):
            return temp
        else:
            temp = increment(temp)
            i += 1
          
            
if __name__ == "__main__":
    test = "abcdfgh"
    part_one = main("cqjxjnds")
    part_two = main(increment(part_one))
    