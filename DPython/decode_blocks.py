import os
import sys

size = 0
endBlocks = [None] * 5 * int(1e5)

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]
fileType = sys.argv[3]

path = os.path.dirname(os.path.abspath(__file__))

inputFile = open(os.path.join(path, inputFileName), 'r')
outputFile = open(os.path.join(path, outputFileName), 'w')

blocks = inputFile.read().split('\n')


for i in range(len(blocks) - 1):
    block = blocks[i]
    blockId = str()

    for j in range(len(block)):
        if block[j] == ';':
            endBlocks[int(blockId)] = block[j + 1:]
            break

        blockId += block[j]
    size += 1

for i in range(size):
    if len(str(endBlocks[i])) == 0:
        continue
    outputFile.write(str(endBlocks[i]) + "\n")
