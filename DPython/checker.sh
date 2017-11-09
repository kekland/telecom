#/~/Projects/ACM/NTI/D
# $1 = INPUT_NAME
# $2 = OUTPUT_NAME
# $3 = FILE_NAME
python encode_blocks.py $1 temp/encoded_blocks.dat $3
python mix_blocks.py temp/encoded_blocks.dat temp/mixed_blocks.dat
python decode_blocks.py temp/mixed_blocks.dat $2 $3

cmp --silent $1 $2 && echo "Success : Files are identical." || echo "Error : Files are different."
