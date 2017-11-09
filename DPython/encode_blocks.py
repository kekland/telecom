# -*- coding: utf-8 -*-

import sys
import os

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]
fileType = sys.argv[3]

path = os.path.dirname(os.path.abspath(__file__))
inputFile = open(os.path.join(path, inputFileName), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')

input = str(inputFile.read())

s = str()
pref = "▓0░"
cnt = 0
tx = str()
for i in range(len(input)):
    s += input[i]
    if len(pref) + len(s) == 54:
        tx += pref + s
        cnt += 1
        s = ""
        pref = "▓" + str(cnt) + "░"

if len(s) != 0:
    tx += pref + s

outputFile.write(tx)
