import sys
import os

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]
fileType = sys.argv[3]

path = os.path.dirname(os.path.abspath(__file__))
inputFile = open(os.path.join(path, inputFileName), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')

blocks = inputFile.read().split('\n')

for i in range(len(blocks)):
    if len(blocks[i]) == 0:
        continue
    outputFile.write(str(i) + ';' + blocks[i] + '\n')
