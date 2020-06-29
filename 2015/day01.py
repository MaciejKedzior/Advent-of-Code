# -*- coding: utf-8 -*-
"""
Created on Sat Aug  3 23:07:13 2019
Advent Code 2015 Day 1
@author: Dabutsu
"""
with open("day1.txt") as data:
    tabelka = [j for i in data for j in i]


def pietro(tab: list) -> int:
    wynik, counter = 0, 1
    for i in tabelka:
        if i == "(":
            wynik += 1
        else:
            wynik -= 1
        if wynik == -1:
            print("counter= %d" %counter)
            return -1
        counter += 1
    return wynik


if __name__ == "__main__":
    print(pietro(tabelka))