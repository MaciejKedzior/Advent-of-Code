# -*- coding: utf-8 -*-
"""
Created on Thu Sep 26 00:02:42 2019
Advent of Code 2015 Day 18
@author: Dabutsu
"""

from copy import deepcopy

arr_size = tuple([100, 100])
temp_arr_size = tuple([6, 6])


def light_on(candle: str) -> bool:
    return candle == "#"

def higher(arr: list, row: int, column: int) -> int:
    result = 0
    if row == 0:
        return 0
    for i in range(3):
        if column-1+i < 0:
            continue
        try:
            if light_on(arr[row-1][column-1+i]):
                result += 1
        except IndexError:
            continue
    return result

def lower(arr: list, row: int, column: int) -> int:
    result = 0
    if row == arr_size[1]:
        return 0
    for i in range(3):
        if column-1+i < 0:
            continue
        try:
            if light_on(arr[row+1][column-1+i]):
                result += 1
        except IndexError:
            continue
    return result

def same_lvl(arr: list, row: int, column: int) -> int:
    result = 0
    if column == 0:
        if light_on(arr[row][column+1]):
            result += 1
    elif column == arr_size[1]-1:
        if light_on(arr[row][column-1]):
            result += 1
    else:
        if light_on(arr[row][column+1]):
            result += 1
        if light_on(arr[row][column-1]):
            result += 1
    return result

def next_ture(c_arr: list, c_row: int, c_col: int) -> int:
    return higher(c_arr, c_row, c_col) + lower(c_arr, c_row, c_col) + same_lvl(c_arr, c_row, c_col)

def transform(arr: list, ture=0) -> int:
    if ture == 100:
        return sum([light_on(arr[i][j]) for i in range(len(arr)) for j in range(len(arr))])
    temp = deepcopy(arr)
    corners = tuple([(0, 0), (0, 99), (99, 0), (99, 99)])
    print("Ture no %s" %ture)
    for row in range(len(arr)):
        for col in range(len(arr)):
            value = next_ture(arr, row, col)
            if (row, col) in corners:
                continue
            if light_on(arr[row][col]):
                if value in [2,3]:
                    continue
                else:
                    temp[row][col] = "."
            else:
                if value == 3:
                    temp[row][col] = "#"
    return transform(temp, ture+1)
    

if __name__ == "__main__":
    test = [[".", "#", ".", "#", ".", "#"],
            [".", ".", ".", "#", "#", "."],
            ["#", ".", ".", ".", ".", "#",],
            [".", ".", "#", ".", ".", "."],
            ["#", ".", "#", ".", ".", "#"],
            ["#", "#", "#", "#", ".", "."]]

    actual = [list(i.rstrip()) for i in open("day18.txt").readlines()]
    actual[0][0], actual[0][99], actual[99][0], actual[99][99] = "#", "#", "#", "#"
    new = transform(actual, 0)
    