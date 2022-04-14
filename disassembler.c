#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t *read_rom(char *filename){
	// f is a filehandle
	FILE *f = fopen(filename, "rb"); // rb = read bytes
	if (!f){
		printf("Could not open %s\n", filename);
		exit(1);
	}

	// fseek (buffer, offset, whence (where from))
	fseek(f, 0, SEEK_END); //If you give it an offset of -2, it will put the pointer 2 bytes before the end
	int fsize = ftell(f); // Gets current offset (pointer location)
	fseek(f, 0, SEEK_SET); //SEEK_SET = beginning of file; need to reset the pointer to the beginning, so we start reading from there

	// Allocate memory for the size of the document (in bytes)
	uint8_t *buffer = malloc(fsize); //buffer is pointer to allocated memory

	// fread(memory you wanna read into, size in bytes of each chunk, how much of the file to read, file handle)
	int bytes_read = fread(buffer, 1, fsize, f); // bytes_read as in "red", not "reed". Bytes that have been read in the past
	fclose(f); // no defer for you

	if (bytes_read != fsize){
		printf("Failed to fully read file: %s\n", filename);
		exit(1);
	}

	return buffer;
}

char *disassembler(uint8_t instruction){
	switch (instruction) {
		case 0x00: printf("BRK s"); break;
		case 0x18: printf("CLC i"); break;
		case 0xc3: printf("unimplemented"); break;
		case 0xc5: printf("CMP zp"); break;
		case 0xd4: printf("unimplemented"); break;
		case 0xf5: printf("SPC zp,x"); break;
	}
	printf("\n");
}


int main(){
	// TODO Add rom to read
	uint8_t *buffer = read_rom("");
	// Print out the first 10 instructions
	for (int i = 0; i < 10; i++) {
		printf("%x\n", buffer[i]);
		disassembler(buffer[i]);
	}
}

