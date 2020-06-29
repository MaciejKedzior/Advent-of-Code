# -*- coding: utf-8 -*-
"""
Created on Sun Aug  4 12:08:18 2019
Advent of Code 2015 Day 4
@author: Dabutsu
"""

import hashlib


key = 'ckczppom'
number = 1

while True:
    temp = key + str(number)
    print('temp=', temp)
    hashed = hashlib.md5(temp.encode())
    if hashed.hexdigest()[:6] == '000000':
        print(number)
        break
    else:
        number += 1