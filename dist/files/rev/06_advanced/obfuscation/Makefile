sample: sample.S
	nasm -fELF64 ./sample.S -o sample.o
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc sample.o -o sample
	strip --strip-all ./sample
