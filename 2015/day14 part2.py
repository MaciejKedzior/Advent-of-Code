# -*- coding: utf-8 -*-
"""
Created on Mon Aug 26 13:37:50 2019
Advent of Code 2015 Day 14 part 2
@author: Dabutsu
"""
import re


class Reindeer:
    def __init__(self, name, speed, travel_time, rest_time):
        self.name = name
        self.speed = speed
        self.travel_time = travel_time
        self.rest_time = rest_time
        self.points = 0
        self.dist_per_ture = [0] * 2503
        self.highest = 0
    
    def won(self, win:bool):
        self.points += 1
    
    def distance4cycle(self):
        return self.speed * self.travel_time
    
    #JAKBY DZIALA, ALE COS JEST NIE DO KONCA Z PUNKTAMI 
    #I NIE WIEM CZY TO PROBLEM Z NALICZANIEM KM CZY Z PUNKTAMI JUZ W MAINE xD
    def moving_time(self, time):
        cyc_number = 0
        self.dist_per_ture[0] = self.speed
        amount = self.travel_time + self.rest_time
        cycles = time // amount
        
        
        while cyc_number < cycles:
            for i in range(amount):
                if i < self.travel_time:
                    self.dist_per_ture[cyc_number*amount+i] = self.dist_per_ture[cyc_number*amount+i-1] + self.speed
                else:
                    self.dist_per_ture[cyc_number*amount+i] = self.dist_per_ture[cyc_number*amount+i-1]
            cyc_number += 1
        
        for i in range(time - (cyc_number*amount)):
            self.dist_per_ture[cyc_number*amount + i] = self.dist_per_ture[cyc_number*amount-1]
         
        self.highest = self.dist_per_ture[-1]
        
    def stats(self):
        print("In cycle %s goes %s km." %(self.name, self.distance4cycle()))


if __name__ == "__main__":
    
    reindeer_stats = re.findall(r'(\w+) can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds.', open("day14.txt").read())
    '''
    dancer = Reindeer("Dancer", 16, 11, 162)
    comet = Reindeer("Comet", 14, 10, 127)
    
    dancer.stats()
    comet.stats()
    dancer.moving_time(1000)
    comet.moving_time(1000)
    a = dancer.dist_per_ture
    b = comet.dist_per_ture
    for i in zip(a,b):
        print(i[0], i[1])
        if i[0] > i[1]:
            dancer.won(1)
        elif i[0] < i[1]:
            comet.won(1)
        else:
            dancer.won(1)
            comet.won(1)
    print("Dancer has %s points." %dancer.points)
    print("Comet has %s points." %comet.points)
    '''
    object_table = [Reindeer(i[0], int(i[1]), int(i[2]), int(i[3])) for i in reindeer_stats]   
    for i in object_table:
        i.moving_time(2503)
    values = [i.dist_per_ture[-1] for i in object_table]