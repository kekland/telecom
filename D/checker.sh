#/~/Projects/ACM/NTI/D
# $1 = INPUT_NAME
# $2 = OUTPUT_NAME
# $3 = FILE_NAME
./encode_blocks.out $1 encoded_blocks.dat $3
./mix_blocks.out encoded_blocks.dat mixed_blocks.dat
./decode_blocks.out mixed_blocks.dat $2 $3

cmp --silent $1 $2 && echo "Success : Files are identical." || echo "Error : Files are different."
