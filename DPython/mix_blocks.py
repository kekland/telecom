# -*- coding: utf-8 -*-

import sys
import os
import random

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]

path = os.path.dirname(os.path.abspath(__file__))

inputFile = open(os.path.join(path, inputFileName), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')

input = str(inputFile.read())
blocks = []
s = str()
for i in range(len(input)):
    s += input[i]
    if len(s) == 54:
        blocks.append(s)
        s = ""
if len(s) != 0:
    blocks.append(s)

random.seed()
random.shuffle(blocks)


for i in range(len(blocks)):
    outputFile.write(blocks[i])
