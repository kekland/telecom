import os
import sys

def stoif(s):
        res = 0

        for i in range(len(s)):
                res *= 10
                res += (s[i] + '0')

        return res

size = 0
endBlocks = [None] * 5 * int(1e5)

inputFileName = sys.argv[0]
outputFileName = sys.argv[1]
fileType = sys.argv[2]

path = os.path.dirname(os.path.abspath(__file__))

inputFile = open(os.path.join(path, inputFileName + '.' + fileType), 'r')
outputFile = open(os.path.join(path, outputFileName + '.txt'), 'w')

while True:
        try:
                ln = inputFile.readline()
                blockId = str()

                if len(ln) == 0:
                        continue

                for i in range(len(ln)):
                        if ln[i] == ';':
                                endBlocks[stoif(blockId)] = ln[i+1:]
                                break
                        blockId += ln[i]
                size += 1
        except EOFError:
                break

for i in range(size):
        outputFile.write(endBlocks[i] + '\n')