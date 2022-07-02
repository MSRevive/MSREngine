#!/bin/bash
gcc -g0 -O1 -fno-stack-protector -m32 blocksort.c -c -o blocksort.o &&
gcc -g0 -O1 -fno-stack-protector -m32 bzlib.c -c -o bzlib.o &&
gcc -g0 -O1 -fno-stack-protector -m32 compress.c -c -o compress.o &&
gcc -g0 -O1 -fno-stack-protector -m32 crctable.c -c -o crctable.o &&
gcc -g0 -O1 -fno-stack-protector -m32 decompress.c -c -o decompress.o &&
gcc -g0 -O1 -fno-stack-protector -m32 huffman.c -c -o huffman.o &&
gcc -g0 -O1 -fno-stack-protector -m32 precompiled.c -c -o precompiled.o &&
gcc -g0 -O1 -fno-stack-protector -m32 randtable.c -c -o randtable.o &&
ar rcs ../../lib/public/linux32/bzip2.a blocksort.o bzlib.o compress.o crctable.o decompress.o huffman.o precompiled.o randtable.o
