import sys
import os

inputFileName = sys.argv[0]
outputFileName = sys.argv[1]
fileType = sys.argv[2]

path = os.path.dirname(os.path.abspath(__file__))
inputFile = open(os.path.join(path, inputFileName + '.' + fileType), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')

blocks = inputFile.read().split(',')

for i in range(len(blocks)):
        if len(blocks[i]) == 0:
                continue
        outputFile.write(i + ';' + blocks[i] + '\n')

