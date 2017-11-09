import sys
import os
import random

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]

path = os.path.dirname(os.path.abspath(__file__))

inputFile = open(os.path.join(path, inputFileName), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')

blocks = inputFile.read().split('\n')

blocks.sort()

random.seed()

for i in range(random.randint(0,9)):
        random.shuffle(blocks)

for i in range(len(blocks)):
        if len(blocks[i]) == 0:
                continue
        outputFile.write(blocks[i] + '\n')
