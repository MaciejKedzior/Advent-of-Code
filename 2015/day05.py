# -*- coding: utf-8 -*-
"""
Created on Sun Aug  4 13:52:47 2019
Advent of Code 2015 Day 5
@author: Dabutsu
"""
import re


with open("day5.txt") as data:
    array = [i.rstrip() for i in data]

def contains_3vovels(word: str) -> bool:
    vowels = ["a", "i", "u", "e", "o"]
    counter = 0
    for i in word:
        if i in vowels:
            counter += 1
        if counter == 3:
            return True
    return False

def twice_row(word: str) -> bool:
    for i in range(len(word)-1):
        if word[i] == word[i+1]:
            return True
    return False

def banned_phrases(word: str) -> bool:
    banned = ["ab", "cd", "pq", "xy"]
    for i in range(len(word)-1):
        if word[i:i+2] in banned:
            return False
    return True


def main(tab: list) -> int:
    counter = 0
    for i in tab:
        if contains_3vovels(i) and twice_row(i) and banned_phrases(i):
            counter += 1
    return counter

def new_main(tab: list) -> int:
    counter = 0
    for i in tab:
        if re.search(r'(..).*\1', i) and re.search(r'(.).\1', i):
            counter += 1
    return counter


if __name__ == "__main__":
    temp =["qjhvhtzxzqqjkmpb", "xxyxx", "uurcxstgmygtbstg", "ieodomkazucvgmuy"]
    print(main(array))
    print(new_main(array))
    