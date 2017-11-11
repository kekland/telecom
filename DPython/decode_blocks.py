# -*- coding: utf-8 -*-

import os
import sys

size = 0
endBlocks = [None] * 5 * int(1e7)

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]
fileType = sys.argv[3]

path = os.path.dirname(os.path.abspath(__file__))

inputFile = open(os.path.join(path, inputFileName), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')
outputFileTwo = open(os.path.join(path, "temp/outputdbg.dat"), "w")
input = str(inputFile.read())
size = 0
s = str()
for i in range(len(input)):
    s += input[i]
    if len(s) == 54:
        outputFileTwo.write("BLOCK | " + s + "\n")
        for j in range(len(s)):
            if j != len(s) - 1:
                if s[j] == ';':
                    endBlocks[int(s[0:j])] = s[j + 1:]
                    s = ""
                    size += 1
                    outputFileTwo.write("Break at " + str(j) + "\n")
                    break

lastBlock = endBlocks[size - 1]
for i in range(len(lastBlock) - 1, 0, -1):
    print(lastBlock[i])
    if lastBlock[i] != '0':
        endBlocks[size - 1] = lastBlock[0:i + 1]
        print("spltted")
        break

for i in range(size):
    if len(str(endBlocks[i])) == 0:
        continue
    #print(endBlocks[i])
    outputFile.write(str(endBlocks[i]))
